/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:40:09 by loichu            #+#    #+#             */
/*   Updated: 2022/11/17 15:50:57 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (true);
	else
		return (false);
}

char	update_quote_state(char c, char cur_state)
{
	char	new_state;

	if (is_quote(c))
	{
		if (c == cur_state)
		{
			new_state = '\0';
		}
		else if (!cur_state)
		{
			new_state = c;
		}
		else
		{
			return (cur_state);
		}
	}
	else
	{
		return (cur_state);
	}
	return (new_state);
}
