/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:17:05 by vnicoud           #+#    #+#             */
/*   Updated: 2022/05/09 14:05:54 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILES 100
# define PATH_W "./sprite_file/wall.xpm"
# define PATH_BG "./sprite_file/background.xpm"
# define PATH_EX "./sprite_file/exit.xpm"
# define PATH_PD "./sprite_file/player_down.xpm"
# define PATH_PU "./sprite_file/player_up.xpm"
# define PATH_PR "./sprite_file/player_right.xpm"
# define PATH_PL "./sprite_file/player_left.xpm"
# define PATH_I "./sprite_file/item.xpm"
# define PATH_V "./sprite_file/enemy.xpm"
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

# include "./mlx/mlx.h"
# include "src/gnl/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_map_count
{
	int		lines;
	int		columns;
	int		actucolumns;
	int		columns_bup;
	int		lines_bup;
	int		pposy;
	int		pposx;
	int		newcolumn;
	int		numbofchar;
	int		wallisok;
	int		player;
	int		exit;
	int		collect;
	int		collectex;
	int		steps;
	int		others;
	int		width;
	int		height;
	int		img;
	char	**map_str;
	void	*wall_img;
	void	*background_img;
	void	*playeru_img;
	void	*playerd_img;
	void	*playerl_img;
	void	*playerr_img;
	void	*collect_img;
	void	*exit_img;
	void	*enemy_img;
	char	*showsteps;
	void	*mlx;
	void	*win;
	int		x;
	int		y;
}				t_mcount;

//game
void	init_window(t_mcount *count);
int		event(int key, t_mcount *count);
int		close_win(t_mcount *count);
void	move_up(t_mcount *count);
void	move_down(t_mcount *count);
void	move_left(t_mcount *count);
void	move_right(t_mcount *count);
int		check_moves(t_mcount *count);
void	one_print(t_mcount *count);
void	zero_print(t_mcount *count);
void	p_print(t_mcount *count);
void	c_print(t_mcount *count);
void	e_print(t_mcount *count);
void	v_print(t_mcount *count);

//map
char	*get_next_line(int fd);
int		map(int argc, char **argv, t_mcount *count);
int		checkborder(t_mcount *count, char **map);
char	**mallocmap(int fd, t_mcount *count, char *map);
int		checksquare(int fd, t_mcount *count);
void	check_wall(char c, t_mcount *count);
int		checkitems(t_mcount *count, char c);
int		check_extension(char *str, char *extension);
int		pars(int fd, t_mcount *count);

//init
void	initmap(t_mcount *count);
int		print_map(t_mcount *count);
void	print_what(char *c, t_mcount *count);

//utils
void	ft_bzero(void *s, int n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, int len);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
char	*ft_strdup(char *src);

//errors
int		error(char *str);
void	*null_error(char *str);

#endif