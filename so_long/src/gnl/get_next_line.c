/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:50:22 by vlad              #+#    #+#             */
/*   Updated: 2022/04/21 10:06:48 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *str_line)
{
	char	buff[BUFFER_SIZE + 1];
	int		bytes_readed;

	bytes_readed = 1;
	while (!ft_strchr(str_line, '\n') && bytes_readed != 0)
	{
		bytes_readed = read(fd, buff, BUFFER_SIZE);
		if (bytes_readed == -1)
			return (NULL);
		buff[bytes_readed] = '\0';
		str_line = ft_strjoin(str_line, buff);
	}
	return (str_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str_line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	str_line = read_line(fd, str_line);
	if (!str_line)
		return (NULL);
	line = get_line(str_line);
	str_line = new_line(str_line);
	return (line);
}
