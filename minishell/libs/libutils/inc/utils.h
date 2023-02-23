/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:59:02 by loichu            #+#    #+#             */
/*   Updated: 2023/01/12 15:16:12 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <libft.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/termios.h>

// count_tab.c
int		count_tab(char **tab);

// sig.c
void	sig_end_child(int sig);
void	signal_handler(int signo);
char	*get_prompt(void);
void	exit_shell(void);
void	term_handler(void);

// is_in_env.c
int		is_inenv(const char *name);

// check_path.c
int		isit_path(const char *path);

// protected_malloc.c
void	*protected_malloc(size_t size);

// ft_realloc.c
void	*ft_realloc(void *ptr, size_t o_size, size_t d_size);

// join_multiple_str.c
char	*join3(char *str1, char *str2, char *str3);

// quotes.c
char	update_quote_state(char c, char cur_state);
bool	is_quote(char c);

// space.c
int		is_space(char x);

// mini_env.c
char	**ft_init_env(char **env);
char	**ft_getenv(void);
char	*get_envvar_value(char *var);

#endif
