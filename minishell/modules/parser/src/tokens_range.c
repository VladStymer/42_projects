/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_range.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:28:26 by loichu            #+#    #+#             */
/*   Updated: 2023/01/08 17:22:42 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser_p.h>

/*
 *	Get tokens in range (from-to) specified by the parser.
 *	From and to are excluded.
 */
char	**get_tokens_range(t_parser *parser)
{
	char	**tokens_in_range;
	int		nb_tokens;
	int		i;
	int		j;

	nb_tokens = parser->to - parser->from;
	if (nb_tokens < 0)
	{
		throw_exit(out_of_range_error(
				parser->from, "is greater than", parser->to));
	}
	tokens_in_range = (char **)protected_malloc(nb_tokens * sizeof(char *));
	i = -1;
	j = parser->from;
	while (++j < parser->to)
	{
		tokens_in_range[++i] = parser->tokens[j];
	}
	tokens_in_range[++i] = NULL;
	return (tokens_in_range);
}
