/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:07:43 by vnicoud           #+#    #+#             */
/*   Updated: 2022/05/09 11:55:18 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	close_win(t_mcount *count)
{
	free(count->map_str);
	exit(0);
}

int	check_moves(t_mcount *count)
{
	if (count->map_str[count->pposy][count->pposx] == 'C')
	{
		count->collectex += 1;
		count->map_str[count->pposy][count->pposx] = '0';
	}
	else if (count->map_str[count->pposy][count->pposx] == 'V')
	{
		mlx_string_put(count->mlx, count->win, (count->lines / 2) * TILES,
			(count->columns / 2) * TILES, 0xFFFF00, "YOU LOOSE");
		close_win(count);
	}
	else if (count->map_str[count->pposy][count->pposx] == 'E' &&
		count->collectex == count->collect)
	{
		mlx_string_put(count->mlx, count->win, (count->lines / 2) * TILES,
			(count->columns / 2) * TILES, 0xFFFF00, "YOU WIN");
		close_win(count);
	}
	count->steps++;
	return (1);
}

int	event(int key, t_mcount *count)
{
	mlx_put_image_to_window(count->mlx, count->win, count->wall_img,
		1 * TILES, 0 * TILES);
	mlx_put_image_to_window(count->mlx, count->win, count->wall_img,
		0 * TILES, 0 * TILES);
	if (key == UP)
		move_up(count);
	if (key == DOWN)
		move_down(count);
	if (key == LEFT)
		move_left(count);
	if (key == RIGHT)
		move_right(count);
	if (key == ESC)
		close_win(count);
	count->showsteps = ft_itoa(count->steps);
	mlx_string_put(count->mlx, count->win, 50, 50, 0x000000,
		"CURRENT STEP:");
	mlx_string_put(count->mlx, count->win, 160, 50, 0x000000, count->showsteps);
	return (0);
}
