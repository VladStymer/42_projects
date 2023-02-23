/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_p.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:28:13 by loichu            #+#    #+#             */
/*   Updated: 2023/01/10 21:35:28 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_P_H
# define TOKENIZER_P_H

# include <stdio.h>
# include <stdbool.h>
# include <errno.h>

# include <tokenizer.h>
# include <libft.h>
# include <utils.h>

# define SEPARATORS " \t"
# define OPERATOR_CHARS "<>|"
# define TOKENS_BASE_LEN 32

typedef struct s_source
{
	char	*str;
	int		csr;
	int		ntokens;
}	t_source;	

// check_chars.c
bool	is_separator(char c);
bool	is_operator_char(char c);
bool	is_quote(char c);
bool	is_operator(char *token);

// get_token.c
char	*word_token(t_source *src);
char	*operator_token(t_source *src);

// error_handling.c
void	*failed_allocation(char **tokens);
void	*unmatched_quote(char quote);

#endif
