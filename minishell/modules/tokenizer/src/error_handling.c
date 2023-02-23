/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:06:23 by loichu            #+#    #+#             */
/*   Updated: 2023/01/10 21:57:59 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer_p.h"

void	*failed_allocation(char **tokens)
{
	if (DEBUG)
		printf("Allocation failed\n");
	errno = ENOMEM;
	free_tokens(tokens);
	return (NULL);
}

void	*unmatched_quote(char quote)
{
	errno = 2;
	ft_putstr_fd("minishell: unexpected EOF while looking for matching `", 2);
	ft_putchar_fd(quote, 2);
	ft_putstr_fd("'\n", 2);
	return (NULL);
}
