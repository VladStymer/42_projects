/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:16:35 by loichu            #+#    #+#             */
/*   Updated: 2023/01/08 17:17:05 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser_p.h>

char	*get_token(t_parser *parser)
{
	return (parser->tokens[parser->to]);
}

char	*next_token(t_parser *parser, bool move_cursor)
{
	int	next;

	next = parser->to + 1;
	if (move_cursor)
		parser->to = next;
	return (parser->tokens[next]);
}

t_error	parse_token(char *token, t_parser *parser)
{
	t_error	error;

	error = no_error();
	if (is_short_circuit(token))
	{
		error = unexpected_token(token);
	}
	else if (is_pipe(token))
	{
		error = parse_pipe(parser);
	}
	return (error);
}
