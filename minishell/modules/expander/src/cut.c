/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:58:53 by vnicoud           #+#    #+#             */
/*   Updated: 2022/12/02 12:42:02 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*srch_quote(char *str, char c)
{
	int		i;
	char	*tmp;

	i = -1;
	if (str[0] == c)
		return (ft_strdup(&str[1]));
	else
	{
		tmp = make_tmp(str, c);
		while (str[++i] != c)
			;
		if (str[i] == c && (str[i + 1] == '\n' || !str[i + 1]))
		{
			free(str);
			return (tmp);
		}
		str = ft_strjoin(tmp, &str[i + 1]);
		free(tmp);
		return (str);
	}
}

char	*srch_dol(char *str)
{
	int		i;
	char	*tmp;

	i = -1;
	if (str[0] == '$')
		str = cut_from_dol(&str[0]);
	else
	{
		tmp = make_tmp(str, '$');
		while (str[++i] != '$')
			;
		str = cut_from_dol(&str[i]);
		str = reverse_strjoinfree(tmp, str, 0);
		free(tmp);
	}
	return (str);
}

char	*cut_from_dol(char *str)
{
	int	i;

	i = 1;
	if (str[i] == '=')
		i++;
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			i++;
		return (ft_strdup(&str[i]));
	}
	else if (ft_isalpha(str[i]) || str[i] == '_')
		while ((ft_isalpha(str[i]) && str[i] != '=')
			|| ft_isdigit(str[i]) || str[i] == '_')
			i++;
	return (ft_strdup(&str[i]));
}
