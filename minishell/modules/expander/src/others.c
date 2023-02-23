/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:38:57 by vnicoud           #+#    #+#             */
/*   Updated: 2023/01/05 15:56:52 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include <liberrors.h>

char	*make_tmp(char *tmp, char *input, int input_csr, t_len *len)
{
	len->new_len++;
	tmp = (char *)protected_malloc(2 * sizeof(char));
	tmp[0] = input[input_csr];
	tmp[1] = '\0';
	len->input_csr++;
	return (tmp);
}

void	quote_me(char c, t_len *len)
{
	len->prev_quote_state = len->quote_state;
	len->quote_state = update_quote_state(c, len->quote_state);
}

void	set_struct(t_len *len, char *input)
{
	len->input = input;
	len->quote_state = '\0';
	len->realloc_count = 0;
	len->new_len = 0;
	len->input_csr = 0;
	len->new = (char *)protected_malloc(2 * sizeof(char));
	len->new[0] = 0;
}
