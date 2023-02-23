/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:29:35 by loichu            #+#    #+#             */
/*   Updated: 2023/01/13 14:59:45 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executor_p.h>

int	execute_single_command(t_cmd *cmd, t_deps deps)
{
	int			status;
	int			fake_pfd[2];
	int			saved_io[2];
	t_builtin	builtin;

	if (DEBUG)
		printf("[executor] execute single command\n");
	builtin = NULL;
	fake_pfd[0] = 0;
	fake_pfd[1] = 1;
	if (cmd->argc > 0)
		builtin = deps.resolve_builtin(cmd->argv[0]);
	if (builtin)
	{
		save_std_io(cmd, saved_io);
		status = exec_builtin(cmd, builtin, fake_pfd, deps);
		restore_std_io(saved_io);
		return (status);
	}
	exec_cmd(cmd, fake_pfd, deps);
	wait(&status);
	signal(SIGINT, signal_handler);
	return (WEXITSTATUS(status));
}

int	execute(t_node *head, t_executor_deps deps)
{
	int			exit_code;

	exit_code = 0;
	if (!head)
		throw_exit(missing_argument("head"));
	if (head->type == PIPE)
		return (exec_pipes(head, deps));
	else if (head->type == CMD)
		return (execute_single_command(head->cmd, deps));
	else
	{
		throw(not_implemented());
		return (errno);
	}
	return (exit_code);
}
