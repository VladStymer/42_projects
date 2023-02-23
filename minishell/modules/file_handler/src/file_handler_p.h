/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler_p.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:10:15 by loichu            #+#    #+#             */
/*   Updated: 2023/01/10 22:19:06 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HANDLER_P_H
# define FILE_HANDLER_P_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>

# include <liberrors.h>
# include <libft.h>

# include <file_handler.h>
# include <parser_defs.h>

typedef int	(*t_open_mode_func_ptr)(char *);

// open_file.c
int	_open(char *path, int mode);

// read.c
int	open_read(char *path);
int	open_heredoc(char *eof);

// write.c
int	open_write(char *path);
int	open_append(char *path);

#endif
