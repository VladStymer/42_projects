/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:15:45 by loichu            #+#    #+#             */
/*   Updated: 2023/01/12 18:22:22 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer_p.h"

bool	is_in_charset(char c, char *charset)
{
	int			i;

	if (!c)
		return (false);
	i = -1;
	while (charset[++i])
	{
		if (c == charset[i])
			return (true);
	}
	return (false);
}

bool	is_separator(char c)
{
	return (is_in_charset(c, SEPARATORS));
}

bool	is_operator_char(char c)
{
	return (is_in_charset(c, OPERATOR_CHARS));
}

bool	is_operator(char *token)
{
	const char	*operators[] = {"<", "<<", "|", ">>", ">", NULL};
	int			i;

	i = -1;
	while (operators[++i])
	{
		if (ft_strncmp(token, operators[i], 4) == 0)
		{
			return (true);
		}
	}
	return (false);
}
