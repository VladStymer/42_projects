/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:10:51 by vnicoud           #+#    #+#             */
/*   Updated: 2022/12/29 16:16:54 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "minishell.h"
# include "expander.h"
# include "libft.h"
# include "utils.h"

typedef int(*t_function_pointer)(int argc, char **argv, char **env);

// builtins_resolver.c
t_function_pointer	get_builtin_function(char *str);

// cd.c
int					cd_main(int argc, char **argv, char **env);

//  echo.c
int					echo_main(int argc, char **argv, char **env);

//  env.c
int					env_main(int argc, char **argv, char **env);

// exit.c
int					exit_main(int argc, char **argv, char **env);

// export.c
int					export_main(int argc, char **argv, char **env);

// pwd.c
int					pwd_main(int argc, char **argv, char **env);

// unset.c
int					unset_main(int argc, char **argv, char **env);

#endif
