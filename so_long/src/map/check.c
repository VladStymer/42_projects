/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:18:49 by vnicoud           #+#    #+#             */
/*   Updated: 2022/05/09 17:15:23 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	pars(int fd, t_mcount *count)
{
	int		size;
	char	map;

	while (true)
	{
		size = read(fd, &map, 1);
		if (!checkitems(count, map))
			return (0);
		if (size < 0)
			return (error("CAN'T READ THE FILE"));
		if (map == '\n')
		{
			count->lines++;
			count->actucolumns = 1;
		}
		if (map != '\n' && size > 0 && count->lines == -1)
			count->columns++;
		if (map != '\n' && size > 0)
		{
			count->actucolumns++;
			count->numbofchar++;
		}
		if (size == 0)
			break ;
	}
	return (1);
}

int	checksquare(int fd, t_mcount *count)
{
	if (!pars(fd, count))
		return (0);
	close(fd);
	count->columns_bup = count->columns;
	count->lines_bup = count->lines;
	if (count->columns * count->lines != count->numbofchar)
		return (error("Map have to be a rectangle"));
	if (count->player != 1 || count->exit < 1 || count->collect < 1)
		return (error("With nmbrs of player, exit or collectible"));
	else
		return (1);
}
