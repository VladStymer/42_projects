/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:09:23 by vnicoud           #+#    #+#             */
/*   Updated: 2022/05/09 13:41:41 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_up(t_mcount *count)
{
	mlx_put_image_to_window(count->mlx, count->win, count->background_img,
		count->pposx * TILES, count->pposy * TILES);
	count->pposy--;
	if (count->map_str[count->pposy][count->pposx] == '1' ||
		(count->map_str[count->pposy][count->pposx] == 'E' &&
			count->collectex < count->collect))
		count->pposy++;
	check_moves(count);
	mlx_put_image_to_window(count->mlx, count->win, count->playeru_img,
		count->pposx * TILES, count->pposy * TILES);
}

void	move_down(t_mcount *count)
{
	mlx_put_image_to_window(count->mlx, count->win, count->background_img,
		count->pposx * TILES, count->pposy * TILES);
	count->pposy++;
	if (count->map_str[count->pposy][count->pposx] == '1' ||
		(count->map_str[count->pposy][count->pposx] == 'E' &&
			count->collectex < count->collect))
		count->pposy--;
	check_moves(count);
	mlx_put_image_to_window(count->mlx, count->win, count->playerd_img,
		count->pposx * TILES, count->pposy * TILES);
}

void	move_left(t_mcount *count)
{
	mlx_put_image_to_window(count->mlx, count->win, count->background_img,
		count->pposx * TILES, count->pposy * TILES);
	count->pposx--;
	if (count->map_str[count->pposy][count->pposx] == '1' ||
		(count->map_str[count->pposy][count->pposx] == 'E' &&
			count->collectex < count->collect))
		count->pposx++;
	check_moves(count);
	mlx_put_image_to_window(count->mlx, count->win, count->playerl_img,
		count->pposx * TILES, count->pposy * TILES);
}

void	move_right(t_mcount *count)
{
	mlx_put_image_to_window(count->mlx, count->win, count->background_img,
		count->pposx * TILES, count->pposy * TILES);
	count->pposx++;
	if (count->map_str[count->pposy][count->pposx] == '1' ||
		(count->map_str[count->pposy][count->pposx] == 'E' &&
			count->collectex < count->collect))
		count->pposx--;
	check_moves(count);
	mlx_put_image_to_window(count->mlx, count->win, count->playerr_img,
		count->pposx * TILES, count->pposy * TILES);
}
