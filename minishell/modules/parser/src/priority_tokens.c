/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:50:10 by loichu            #+#    #+#             */
/*   Updated: 2023/01/06 10:43:34 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser_p.h>

bool	is_pipe(char *token)
{
	return (ft_strncmp("|", token, 2) == 0);
}

bool	is_and(char *token)
{
	return (ft_strncmp("&&", token, 2) == 0);
}

bool	is_or(char *token)
{
	return (ft_strncmp("||", token, 2) == 0);
}

bool	is_short_circuit(char *token)
{
	return (is_and(token) || is_or(token));
}

bool	is_priority_token(char *token)
{
	return (is_pipe(token) || is_short_circuit(token));
}
