/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_defs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:05:38 by loichu            #+#    #+#             */
/*   Updated: 2023/01/05 12:17:45 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_DEFS_H
# define EXECUTOR_DEFS_H

# include <parser_defs.h>
# include <builtins.h>

extern int	g_last_exit_code;
typedef int	(*t_function_pointer)(int argc, char **argv, char **env);

typedef struct s_executor_deps
{
	char				*(*resolve)(char *);
	t_function_pointer	(*resolve_builtin)(char *);
	int					(*open_file)(t_file *file);
	int					(*close_fd)(int);
}	t_executor_deps;

#endif
