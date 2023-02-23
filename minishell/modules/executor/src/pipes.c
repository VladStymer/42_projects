/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:40:47 by loichu            #+#    #+#             */
/*   Updated: 2023/01/05 23:46:36 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executor_p.h>

int	count_cmds(t_node *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		if (head->type == PIPE)
			head = head->pipe->node;
		else if (head->type == CMD)
			return (count);
		else
			throw_exit(not_implemented());
	}
	return (count);
}

int	wait_exit(pid_t *pids, int nb_cmds)
{
	pid_t	pid;
	int		exit_code;
	int		i;
	int		status;

	exit_code = 0;
	i = -1;
	while (++i < nb_cmds)
	{
		pid = wait(&status);
		if (DEBUG)
			printf("[%i] exited (%i)\n", pid, status);
		if (pid == pids[nb_cmds - 1])
			exit_code = status;
	}
	free(pids);
	if (DEBUG)
		printf("exit code: %i => %i\n", exit_code, WEXITSTATUS(exit_code));
	return (WEXITSTATUS(exit_code));
}

t_node	*exec_pipe_node(t_node *head, int *pid, int *pfd, t_executor_deps deps)
{
	head->pipe->cmd->fd_in = pfd[0];
	pipe(pfd);
	if (DEBUG)
		printf("PIPE\t%i <==> %i\n", pfd[0], pfd[1]);
	head->pipe->cmd->fd_out = pfd[1];
	*pid = exec_cmd(head->pipe->cmd, pfd, deps);
	return (head->pipe->node);
}

t_node	*exec_cmd_node(t_node *head, int *pid, int *pfd, t_executor_deps deps)
{
	head->cmd->fd_in = pfd[0];
	*pid = exec_cmd(head->cmd, pfd, deps);
	return (NULL);
}

int	exec_pipes(t_node *head, t_executor_deps deps)
{
	int					nb_cmds;
	pid_t				*pids;
	int					i;
	int					pfd[2];

	pfd[0] = 0;
	pfd[1] = 1;
	nb_cmds = count_cmds(head);
	pids = (pid_t *)protected_malloc(nb_cmds * sizeof(pid_t));
	i = 0;
	while (head)
	{
		if (head->type == PIPE)
			head = exec_pipe_node(head, &(pids[i++]), pfd, deps);
		else if (head->type == CMD)
			head = exec_cmd_node(head, &(pids[i++]), pfd, deps);
		else
		{
			throw(not_implemented());
			return (errno);
		}
	}
	return (wait_exit(pids, nb_cmds));
}
