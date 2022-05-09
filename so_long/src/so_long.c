/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:15:46 by vnicoud           #+#    #+#             */
/*   Updated: 2022/05/09 14:06:12 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initmap(t_mcount *count)
{
	count->lines = -1;
	count->columns = 0;
	count->newcolumn = 0;
	count->actucolumns = 1;
	count->numbofchar = 0;
	count->wallisok = 0;
	count->collect = 0;
	count->others = 0;
	count->player = 0;
	count->steps = 0;
	count->exit = 0;
	count->mlx = 0;
	count->win = 0;
}

int	main(int argc, char **argv)
{
	t_mcount	count;

	initmap(&count);
	if (!map(argc, argv, &count))
		return (0);
	init_window(&count);
	return (1);
}
