/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:29:14 by loichu            #+#    #+#             */
/*   Updated: 2023/01/13 15:22:41 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executor_p.h>

int	get_file_fd(t_file *head, int fd, t_executor_deps deps)
{
	char	*prev_file;

	prev_file = NULL;
	while (head)
	{
		if (fd > 2)
		{
			if (DEBUG)
				printf("[executor] close file %s with fd %i\n", prev_file, fd);
			deps.close_fd(fd);
		}
		fd = deps.open_file(head);
		if (fd < 0)
		{
			throw(cannot_open_file(head->path));
			return (fd);
		}
		prev_file = head->path;
		head = head->next;
	}
	return (fd);
}

void	dup_fd(int new_fd, int target_fd, t_deps deps)
{
	if (new_fd != target_fd)
	{
		if (DEBUG)
			printf("\tdup2 %i => %i\n", new_fd, target_fd);
		dup2(new_fd, target_fd);
		if (DEBUG)
			printf("\tclose %i (DUP)\n", new_fd);
		deps.close_fd(new_fd);
	}
}

void	close_pipe_if_not_used(int *pfd, int *io, t_cmd *cmd, t_deps deps)
{
	if (DEBUG)
	{
		printf("[executor] close_pipe_if_not_used ");
		printf("pfd: (%i, %i)\tio: (%i, %i)\t", pfd[0], pfd[1], io[0], io[1]);
		printf("command: (%i, %i)\n", cmd->fd_in, cmd->fd_out);
	}
	if (pfd[0] != 0 && pfd[0] != io[0] && io[0] == cmd->fd_in)
	{
		if (DEBUG)
			printf("[executor] %s: close %i\n", cmd->argv[0], pfd[0]);
		deps.close_fd(pfd[0]);
	}
}

int	*get_and_dup_fds(t_cmd *cmd, int *pfd, t_deps deps, int *io)
{
	int	fd;

	io[0] = get_file_fd(cmd->input, cmd->fd_in, deps);
	io[1] = get_file_fd(cmd->output, cmd->fd_out, deps);
	if (io[0] < 0 || io[1] < 0)
		return (io);
	if (DEBUG)
	{
		printf("[executor] pfd:\t\t(%i, %i)\n", pfd[0], pfd[1]);
		printf("[executor] CMD_IO:\t(%i, %i)\n", io[0], io[1]);
		printf("[executor] %s:\n", cmd->argv[0]);
	}
	fd = -1;
	while (++fd < 2)
		dup_fd(io[fd], fd, deps);
	if (DEBUG)
		printf("[executor] finished duplicating fds\n");
	close_pipe_if_not_used(pfd, io, cmd, deps);
	return (io);
}
