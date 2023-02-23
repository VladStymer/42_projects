/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 12:21:30 by loichu            #+#    #+#             */
/*   Updated: 2023/01/13 15:00:23 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executor_p.h>

void	parent_clean(int pid, int fd_in, int fd_out, t_deps deps)
{
	if (DEBUG)
		printf("[%i] launched\n", pid);
	if (fd_in != 0)
	{
		if (DEBUG)
			printf("parent: close %i\n", fd_in);
		deps.close_fd(fd_in);
	}
	if (fd_out != 1)
	{
		if (DEBUG)
			printf("parent: close %i\n", fd_out);
		deps.close_fd(fd_out);
	}
	signal(SIGINT, sig_end_child);
}

void	find_and_execute(char *exec_name, char **argv, t_deps deps)
{
	char	*exec;

	if (isit_path(exec_name))
	{	
		if (DEBUG)
			printf("[executor] execute path\n");
		if (execve(exec_name, argv, ft_getenv()) == -1)
			execve_error(exec_name);
	}
	if (DEBUG)
		printf("[executor] resolve and execute command\n");
	exec = deps.resolve(exec_name);
	if (!exec)
		throw_exit(command_not_found(exec_name));
	if (DEBUG)
		printf("[executor] Exec CMD %s\n", exec);
	if (execve(exec, argv, ft_getenv()) == -1)
		execve_error(exec);
}

void	exec_child(t_cmd *cmd, int *pfd, t_deps deps)
{
	t_builtin	builtin;
	int			io[2];

	if (DEBUG)
		printf("[executor] Exec child process\n");
	signal(SIGINT, SIG_DFL);
	get_and_dup_fds(cmd, pfd, deps, io);
	if (io[0] < 0 || io[1] < 0)
		exit(1);
	if (cmd->argc == 0)
		exit(0);
	builtin = deps.resolve_builtin(cmd->argv[0]);
	if (builtin)
		exit(exec_builtin(cmd, builtin, pfd, deps));
	find_and_execute(cmd->argv[0], cmd->argv, deps);
}

int	exec_builtin(t_cmd *cmd, t_builtin builtin, int *pfd, t_deps deps)
{
	int		return_code;
	int		io[2];

	if (DEBUG)
		printf("[executor] execute builtin\n");
	get_and_dup_fds(cmd, pfd, deps, io);
	if (io[0] < 0 || io[1] < 0)
		return (1);
	return_code = builtin(cmd->argc, cmd->argv, ft_getenv());
	if (io[0] > 2)
		deps.close_fd(io[0]);
	if (io[1] > 2)
		deps.close_fd(io[1]);
	if (DEBUG)
		printf("%s exited with %i\n", cmd->argv[0], return_code);
	return (return_code);
}

pid_t	exec_cmd(t_cmd *cmd, pid_t *pfd, t_deps deps)
{
	pid_t				pid;

	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid < 0)
		throw_exit(error_errno("Fork failed"));
	else if (pid == 0)
		exec_child(cmd, pfd, deps);
	parent_clean(pid, cmd->fd_in, cmd->fd_out, deps);
	return (pid);
}
