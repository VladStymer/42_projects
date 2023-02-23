/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_std_io.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:36:08 by lhumbert          #+#    #+#             */
/*   Updated: 2023/01/13 17:56:15 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executor_p.h>

void	save_std_io(t_cmd *cmd, int *saved_io)
{
	t_file	*cmd_io[2];
	int		fd;

	cmd_io[0] = cmd->input;
	cmd_io[1] = cmd->output;
	fd = -1;
	while (++fd < 2)
	{
		if (cmd_io[fd])
		{
			saved_io[fd] = dup(fd);
			if (DEBUG)
				printf("[executor] saved fd %i to %i\n", fd, saved_io[fd]);
		}
		else
			saved_io[fd] = fd;
	}
}

void	restore_std_io(int *saved_io)
{
	int	fd;

	fd = -1;
	while (++fd < 2)
	{
		if (saved_io[fd] != fd)
		{
			dup2(saved_io[fd], fd);
			close(saved_io[fd]);
			if (DEBUG)
			{
				printf("[executor] restored fd %i, closed %i\n",
					fd, saved_io[fd]);
			}
		}
	}
}
