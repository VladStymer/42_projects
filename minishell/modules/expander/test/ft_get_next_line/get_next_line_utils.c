/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:34:03 by vlad              #+#    #+#             */
/*   Updated: 2022/10/28 15:14:58 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = -1;
	while (s[++i]
	);
	return (i);
}

int	ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char) c)
			return (1);
		i++;
	}
	if (s[i] == (char)c)
		return (1);
	return (0);
}

char	*ft_strjoin_gnl(char *str_line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!str_line)
	{
		str_line = (char *)malloc(1 * sizeof(char));
		str_line[0] = '\0';
	}
	if (!str_line || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(str_line) + ft_strlen(buff)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (str_line[++i])
		str[i] = str_line[i];
	while (buff[++j])
		str[i + j] = buff[j];
	str[i + j] = '\0';
	free(str_line);
	return (str);
}

char	*get_line(char *str_line)
{
	int		i;
	char	*str;

	i = -1;
	if (!str_line[0])
		return (NULL);
	while (str_line[++i]
		&& str_line[i] != '\n');
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = -1;
	while (str_line[++i] && str_line[i] != '\n')
		str[i] = str_line[i];
	if (str_line[i] == '\n')
	{
		str[i] = str_line[i];
		str[i + 1] = '\0';
		return (str);
	}
	str[i] = '\0';
	return (str);
}

char	*new_line(char *str_line)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	while (str_line[++i]
		&& str_line[i] != '\n');
	if (!str_line[i])
	{
		free (str_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(str_line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (str_line[i])
		str[j++] = str_line[i++];
	str[j] = '\0';
	free(str_line);
	return (str);
}
