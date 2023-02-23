/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:11:51 by loichu            #+#    #+#             */
/*   Updated: 2023/01/06 10:35:03 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser_p.h>

bool	is_read(char *token)
{
	return (!ft_strncmp(token, "<", 2));
}

bool	is_heredoc(char *token)
{
	return (!ft_strncmp(token, "<<", 3));
}

bool	is_write(char *token)
{
	return (!ft_strncmp(token, ">", 2));
}

bool	is_append(char *token)
{
	return (!ft_strncmp(token, ">>", 3));
}
