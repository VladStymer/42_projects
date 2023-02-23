/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:10:17 by loichu            #+#    #+#             */
/*   Updated: 2023/01/10 21:39:29 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer_p.h"

static char	*next_token(t_source *src, int len)
{
	char	*next_token;

	next_token = (char *)protected_malloc((len + 1) * sizeof(char));
	ft_strlcpy(next_token, src->str + src->csr, len + 1);
	src->csr += len;
	return (next_token);
}

char	*operator_token(t_source *src)
{
	int		i;
	int		len;
	char	token[4];
	char	c;

	i = 4;
	while (i-- > 0)
		token[i] = 0;
	token[0] = src->str[src->csr];
	c = src->str[src->csr];
	len = 1;
	while (c && is_operator(token))
	{
		c = src->str[src->csr + len];
		token[len++] = c;
	}
	len--;
	return (next_token(src, len));
}

bool	is_same_word(char c, char quote)
{
	if (!c)
		return (false);
	else if (quote)
		return (true);
	else if (is_separator(c) || is_operator_char(c))
		return (false);
	return (true);
}

char	*word_token(t_source *src)
{
	int		len;
	char	quote;

	len = 0;
	quote = update_quote_state(src->str[src->csr], '\0');
	while (is_same_word(src->str[src->csr + len], quote))
	{
		len++;
		quote = update_quote_state(src->str[src->csr + len], quote);
	}
	if (!src->str[src->csr + len] && quote)
		return (unmatched_quote(quote));
	return (next_token(src, len));
}
