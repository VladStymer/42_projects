/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smpl_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:06:51 by vnicoud           #+#    #+#             */
/*   Updated: 2022/12/02 11:54:06 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*cut_simple(char *str, int *tab)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (tab[j] != -1)
	{
		while (str[++i])
		{
			if (str[i] == '\'' && (i < tab[j] || i > tab[j + 1]))
				return (srch_quote(str, '\''));
		}
		j++;
	}
	return (str);
}

char	*simple_quote(char *str)
{
	int		i;
	int		j;
	int		tab[999];

	i = -1;
	j = 0;
	if (!ft_strchr(str, '"'))
		while (ft_strchr(str, '\''))
			return (srch_quote(str, '\''));
	while (str[++i])
	{
		if (str[i] == '"')
		{
			tab[j] = i;
			j++;
			tab[j] = -1;
		}
	}
	str = cut_simple(str, tab);
	return (str);
}

int	check_simple(char *str, int *tab)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (tab[j] != -1)
	{
		while (str[++i])
		{		
			if (str[i] == '\'')
				if (i < tab[j] || i > tab[j + 1])
					return (0);
		}
		j++;
	}
	return (1);
}

int	check_smpl_quote(char *str)
{
	int		i;
	int		j;
	int		tab[999];

	i = -1;
	j = 0;
	if (!ft_strchr(str, '"') && ft_strchr(str, '\''))
		return (0);
	while (str[++i])
	{
		if (str[i] == '"')
		{
			tab[j] = i;
			j++;
			tab[j] = -1;
		}
	}
	return (check_simple(str, tab));
}
