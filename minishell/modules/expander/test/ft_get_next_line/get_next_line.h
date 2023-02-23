/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:21:48 by vlad              #+#    #+#             */
/*   Updated: 2022/11/08 18:03:58 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "expander.h"
# include "libft.h"
# include "utils.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*read_line(int fd, char *str_line);
int		ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *str_line, char *buff);
char	*get_line(char *str_line);
char	*new_line(char *str_line);
size_t	ft_strlen(const char *s);

#endif
