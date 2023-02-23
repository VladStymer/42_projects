/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:05:15 by vlad              #+#    #+#             */
/*   Updated: 2023/01/03 13:44:44 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# define GREENB		"\033[1;32m"
# define GREEN		"\033[0;32m"
# define REDB		"\033[1;31m"
# define RED		"\033[0;31m"
# define YELLOWB	"\033[1;33m"
# define YELLOW		"\033[0;33m"
# define BLUEB		"\033[1;34m"
# define BLUE		"\033[0;34m"
# define PURPLEB	"\033[1;35m"
# define PURPLE		"\033[0;35m"
# define CYANB		"\033[1;36m"
# define CYAN		"\033[0;36m"
# define WHITEB		"\033[1;37m"
# define WHITE		"\033[0;37m"
# define RESET 		"\033[0m"

# include "minishell.h"
# include "libft.h"
# include "utils.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef int(*t_function_pointer)(int argc, char **argv, char **env);

// builtins_resolver.c
t_function_pointer	resolve_builtin(char *str);

// cd.c
int					cd_main(int argc, char **argv, char **env);

//  echo.c
int					echo_main(int argc, char **argv, char **env);

//  env.c
int					env_main(int argc, char **argv, char **env);

// exit.c
int					exit_main(int argc, char **argv, char **env);

// export_print.c
void				sortnprint_export(char **env);

// export.c
int					export_main(int argc, char **argv, char **env);

// pwd.c
int					pwd_main(int argc, char **argv, char **env);

// unset.c
int					unset_main(int argc, char **argv, char **env);

#endif