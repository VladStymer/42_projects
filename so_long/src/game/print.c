/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:49:14 by vnicoud           #+#    #+#             */
/*   Updated: 2022/05/09 11:56:05 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	one_print(t_mcount *count)
{
	count->wall_img = mlx_xpm_file_to_image(count->mlx, PATH_W,
			&count->width, &count->height);
	mlx_put_image_to_window(count->mlx, count->win, count->wall_img,
		count->y * TILES, count->x * TILES);
}

void	zero_print(t_mcount *count)
{
	count->background_img = mlx_xpm_file_to_image(count->mlx, PATH_BG,
			&count->width, &count->height);
	mlx_put_image_to_window(count->mlx, count->win, count->background_img,
		count->y * TILES, count->x * TILES);
}

void	c_print(t_mcount *count)
{
	count->collect_img = mlx_xpm_file_to_image(count->mlx, PATH_I,
			&count->width, &count->height);
	mlx_put_image_to_window(count->mlx, count->win, count->collect_img,
		count->y * TILES, count->x * TILES);
}

void	e_print(t_mcount *count)
{
	count->exit_img = mlx_xpm_file_to_image(count->mlx, PATH_EX,
			&count->width, &count->height);
	mlx_put_image_to_window(count->mlx, count->win, count->exit_img,
		count->y * TILES, count->x * TILES);
}

void	v_print(t_mcount *count)
{
	count->enemy_img = mlx_xpm_file_to_image(count->mlx, PATH_V,
			&count->width, &count->height);
	mlx_put_image_to_window(count->mlx, count->win, count->enemy_img,
		count->y * TILES, count->x * TILES);
}
