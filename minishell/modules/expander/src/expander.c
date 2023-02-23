/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:03:53 by vnicoud           #+#    #+#             */
/*   Updated: 2023/01/11 20:58:20 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>
#include <stdlib.h>
#include <errno.h>
#include <liberrors.h>

void	add_tmp_to_new(t_len *len)
{
	char	*free_later;

	free_later = len->new;
	len->new = ft_strjoin(len->new, len->tmp);
	if (!len->new)
		throw_exit(unallocated_memory());
	free(free_later);
	free(len->tmp);
}

void	expand_str(t_len *len)
{
	char	c;

	c = len->input[len->input_csr];
	while (c)
	{
		len->tmp = NULL;
		quote_me(c, len);
		while (c && len->prev_quote_state != len->quote_state)
		{
			c = len->input[++(len->input_csr)];
			quote_me(c, len);
		}
		if (len->input[len->input_csr] == '$' && len->quote_state != '\'')
			var_var(len);
		if (!len->tmp)
		{
			len->tmp = ft_strdup(&c);
			len->tmp[1] = 0;
			++(len->input_csr);
		}
		add_tmp_to_new(len);
		c = len->input[len->input_csr];
	}
}

char	*free_sbi(t_len *len)
{
	free(len->new);
	errno = -1;
	return (NULL);
}

char	*expander(char *input)
{
	t_len	len;

	if (!input)
		return (NULL);
	set_struct(&len, input);
	if (input[0] == '~' && (!input[1] || input[1] == '/'))
	{
		len.tmp = get_envvar_value("HOME");
		++(len.input_csr);
		add_tmp_to_new(&len);
	}
	expand_str(&len);
	if (len.quote_state)
		return (free_sbi(&len));
	if (DEBUG)
		printf("expander return == %s\n", len.new);
	return (len.new);
}
