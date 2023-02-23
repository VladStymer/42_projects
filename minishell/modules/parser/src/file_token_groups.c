/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_token_groups.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:33:51 by loichu            #+#    #+#             */
/*   Updated: 2023/01/12 15:44:23 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser_p.h>

bool	token_expects_file(char *token)
{
	bool	expect_file;

	expect_file = (
			is_read(token)
			|| is_heredoc(token)
			|| is_write(token)
			|| is_append(token));
	if (DEBUG && expect_file)
		printf("[parser] token `%s' expects next token to be a file\n", token);
	return (expect_file);
}

bool	is_input(char *token)
{
	return (is_read(token) || is_heredoc(token));
}

bool	is_output(char *token)
{
	return (is_write(token) || is_append(token));
}
