/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:32:31 by vnicoud           #+#    #+#             */
/*   Updated: 2022/05/09 13:42:22 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**mallocmap(int fd, t_mcount *count, char *map)
{
	int		i;
	char	**map_str;

	i = -1;
	fd = open(map, O_RDONLY);
	map_str = malloc(sizeof(char *) * count->lines + 1);
	if (!map_str)
		return (null_error("error in the allocation memory of the map"));
	while (i != count->lines)
		map_str[++i] = get_next_line(fd);
	map_str[i] = NULL;
	close(fd);
	return (map_str);
}

int	checkborder(t_mcount *count, char **map)
{
	int	i;

	i = -1;
	while (++i != count->columns)
	{
		check_wall(map[0][i], count);
		check_wall(map[count->lines - 1][i], count);
	}
	i = -1;
	while (++i != count->lines)
	{
		check_wall(map[i][0], count);
		check_wall(map[i][count->columns - 1], count);
	}
	if (count->wallisok > 1)
		return (1);
	else
		return (0);
}

int	checkitems(t_mcount *count, char c)
{
	if (c == 'P')
	{
		count->player += 1;
		count->pposy = (count->lines + 2);
		count->pposx = (count->actucolumns);
	}
	if (c == 'E')
		count->exit += 1;
	if (c == 'C')
		count->collect += 1;
	if (c == '1' || c == '0' || c == 'V' || c == 'P'
		|| c == 'E' || c == 'C' || c == '\n')
		return (1);
	else
		return (error("ONLY USE P, E, C, 1, 0 or V FOR FILE THE MAP"));
}

void	check_wall(char c, t_mcount *count)
{
	if (c == '1')
		count->wallisok += 1;
	else
		count->wallisok -= 10000;
}

int	map(int argc, char **argv, t_mcount *count)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		return (error("ARGC"));
	if (argv[1] == NULL)
		return (error("NEED 2 ARGUMENTS"));
	if (!check_extension(".ber", argv[1]))
		return (error("MAP MUST BE .ber"));
	if (fd < 0)
		return (error("CAN'T OPEN THE FILE"));
	if (!checksquare(fd, count))
		return (0);
	count->map_str = mallocmap(fd, count, argv[1]);
	if (!checkborder(count, count->map_str))
		return (error("THE BORDERS HAVE TO BE 1 ALL ARROUND"));
	return (1);
}
