/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:34:17 by vlad              #+#    #+#             */
/*   Updated: 2022/05/09 13:40:52 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	p_print(t_mcount *count)
{
	count->playeru_img = mlx_xpm_file_to_image(count->mlx, PATH_PU,
			&count->width, &count->height);
	count->playerd_img = mlx_xpm_file_to_image(count->mlx, PATH_PD,
			&count->width, &count->height);
	count->playerl_img = mlx_xpm_file_to_image(count->mlx, PATH_PL,
			&count->width, &count->height);
	count->playerr_img = mlx_xpm_file_to_image(count->mlx, PATH_PR,
			&count->width, &count->height);
	mlx_put_image_to_window(count->mlx, count->win, count->playerd_img,
		count->y * TILES, count->x * TILES);
}

void	print_what(char *c, t_mcount *count)
{
	if (*c == '1')
		one_print(count);
	if (*c == '0')
		zero_print(count);
	if (*c == 'P')
		p_print(count);
	if (*c == 'C')
		c_print(count);
	if (*c == 'E')
		e_print(count);
	if (*c == 'V')
		v_print(count);
}

int	print_map(t_mcount *count)
{
	count->x = 0;
	count->y = -1;
	while (count->x != count->lines && count->y++ != count->columns)
	{
		print_what(&count->map_str[count->x][count->y], count);
		if (count->y == count->columns - 1)
		{
			count->y = -1;
			count->x++;
		}
	}
	return (1);
}

void	init_window(t_mcount *count)
{
	count->mlx = mlx_init();
	count->win = mlx_new_window(count->mlx, count->columns * TILES,
			count->lines * TILES, "so_long");
	print_map(count);
	count->pposy--;
	count->pposx--;
	mlx_hook(count->win, 17, 0, close_win, count);
	mlx_hook(count->win, 2, 0, event, count);
	mlx_loop(count->mlx);
}
