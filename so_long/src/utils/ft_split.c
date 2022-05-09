/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:12:15 by vnicoud           #+#    #+#             */
/*   Updated: 2022/03/31 13:08:03 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	count(const char *str, char c)
{
	int	i;
	int	lock;

	i = 0;
	lock = 0;
	while (*str)
	{
		if (*str != c && lock == 0)
		{
			lock = 1;
			i++;
		}
		else if (*str == c)
			lock = 0;
		str++;
	}
	return (i);
}

static char	*copy(const char *str, int first, int last)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((last - first + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (first < last)
		word[i++] = str[first++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	int			first;
	char		**str;

	i = -1;
	j = 0;
	first = -1;
	if (!s)
		return (NULL);
	str = malloc((count(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && first < 0)
			first = i;
		else if ((s[i] == c || i == ft_strlen(s)) && first >= 0)
		{
			str[j++] = copy(s, first, i);
			first = -1;
		}
	}
	str[j] = NULL;
	return (str);
}
