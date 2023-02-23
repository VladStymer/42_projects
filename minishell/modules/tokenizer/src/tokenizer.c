/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:30:41 by loichu            #+#    #+#             */
/*   Updated: 2023/01/13 15:03:01 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer_p.h"
#include <liberrors.h>

void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = -1;
	while (tokens[++i])
	{
		free(tokens[i]);
	}
	free(tokens);
}

char	**increase_tokens_buffer(char **tokens, int nbuffs)
{
	static int	bufsize = TOKENS_BASE_LEN * sizeof(char *);
	char		**tmp;

	tmp = ft_realloc(
			tokens,
			(nbuffs - 1) * bufsize,
			nbuffs * bufsize);
	if (!tmp)
		throw_exit(unallocated_memory());
	return (tmp);
}

t_source	init_source(char *input)
{
	t_source	src;

	src.str = input;
	src.csr = 0;
	src.ntokens = 0;
	return (src);
}

char	*get_next_token(t_source *src)
{
	char	*token;

	token = NULL;
	if (!src->str[src->csr])
		return (NULL);
	while (is_separator(src->str[src->csr]))
	{
		src->csr++;
	}
	if (!src->str[src->csr])
	{
		return (NULL);
	}
	if (is_operator_char(src->str[src->csr]))
	{
		token = operator_token(src);
	}
	else
	{
		token = word_token(src);
		if (!token)
			return (NULL);
	}
	return (token);
}

char	**tokenize(char *input)
{
	char		**tokens;
	int			nbuffs;
	t_source	src;

	nbuffs = 0;
	tokens = NULL;
	src = init_source(input);
	while (src.str[src.csr])
	{
		if (src.ntokens >= nbuffs * TOKENS_BASE_LEN - 1)
			tokens = increase_tokens_buffer(tokens, ++nbuffs);
		errno = 0;
		tokens[src.ntokens] = get_next_token(&src);
		if (errno)
		{
			free_tokens(tokens);
			return (NULL);
		}
		tokens[++src.ntokens] = NULL;
	}
	return (tokens);
}
