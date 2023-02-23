/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:13:43 by loichu            #+#    #+#             */
/*   Updated: 2023/01/13 17:43:55 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_handler_p.h>

int	_open(char *path, int mode)
{
	int	fd;

	fd = open(path, mode, 0644);
	if (fd == -1)
	{
		throw_exit(cannot_open_file(path));
		return (errno);
	}
	if (DEBUG)
		printf("[file_handler] opened %i\n", fd);
	return (fd);
}

t_open_mode_func_ptr	open_mode_fun(t_open_mode mode)
{
	if (mode == READ)
		return (&open_read);
	else if (mode == HEREDOC)
		return (&open_heredoc);
	else if (mode == WRITE)
		return (&open_write);
	else if (mode == APPEND)
		return (&open_append);
	else
		return (throw(not_implemented()));
}

int	open_file(t_file *file)
{
	int	fd;

	fd = -1;
	fd = open_mode_fun(file->mode)(file->path);
	return (fd);
}

int	close_fd(int fd)
{
	if (DEBUG)
		printf("[file handler] will close %i\n", fd);
	close(fd);
	if (DEBUG)
		printf("[file handler] closed %i\n", fd);
	return (0);
}
