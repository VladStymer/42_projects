/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:56:39 by vnicoud           #+#    #+#             */
/*   Updated: 2022/12/02 14:09:44 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*make_tmp(char *str, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)protected_malloc(ft_strlen(str));
	while (str[i] != c)
	{
		tmp[i] = str[i];
		i++;
		tmp[i] = '\0';
	}
	return (tmp);
}

char	*pars(char *str)
{
	int		i;

	i = 0;
	usleep(50000);
	if (ft_strchr(str, '\''))
	{
		while (1)
		{
			if (check_smpl_quote(str))
				break ;
			str = simple_quote(str);
		}
	}
	while (ft_strchr(str, '$'))
		str = srch_dol(str);
	while (ft_strchr(str, '"'))
		str = srch_quote(str, '"');
	return (str);
}

int	quotes_close(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == '"')
			i++;
		*str++;
	}
	if ((i % 2) == 0)
		return (1);
	return (0);
}

char	*cleaner(char *tkn)
{
	int			error;

	error = 0;
	if (!quotes_close(tkn))
	{
		free(tkn);
		error = printf(""RED"_Double quotes are not closed"RESET"\n");
	}
	if (error != 0)
		exit(3);
	while (ft_strchr(tkn, '$') || ft_strchr(tkn, '"'))
		tkn = pars(tkn);
	return (tkn);
}
