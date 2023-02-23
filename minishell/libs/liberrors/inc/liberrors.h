/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberrors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:35:12 by loichu            #+#    #+#             */
/*   Updated: 2023/01/12 16:25:48 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBERRORS_H
# define LIBERRORS_H
# include <errno.h>
# include <stdbool.h>
# include <parser_defs.h>

# include <liberrors_defs.h>
# if DEBUG
#  include <liberrors_debug.h>
# else
#  include <liberrors_nodebug.h>
# endif

t_error	missing_argument(char *arg_name);
t_error	unexpected_token(char *token);
t_error	not_implemented(void);
t_error	out_of_range_error(int x, char *fail, int y);
t_error	error_errno(char *msg);
t_error	cannot_open_file(char *path);
t_error	command_not_found(char *cmd_name);
t_error	unexpected_end_of_file(void);
t_error	no_error(void);

void	*throw(t_error error);
void	throw_exit(t_error error);
void	throw_void(t_error error);
#endif
