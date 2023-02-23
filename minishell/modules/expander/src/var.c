/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:28:53 by vnicoud           #+#    #+#             */
/*   Updated: 2023/01/11 20:58:53 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <expander.h>
#include <stdlib.h>
#include <stdio.h>
#include <utils.h>

int	get_var_len(char *str)
{
	int	i;

	if (str[0] == '?')
		return (1);
	if (!ft_isalpha(str[0]))
		return (0);
	i = 0;
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	return (i);
}

static char	*parse_env_var(const char *str, int var_len)
{
	char	*value;
	char	*key;
	int		i;

	if (str[0] == '?')
		return (ft_itoa(g_last_exit_code));
	key = (char *)protected_malloc((var_len + 1) * sizeof(char));
	i = -1;
	while (++i < var_len)
		key[i] = str[i];
	key[i] = '\0';
	value = get_envvar_value(key);
	free(key);
	return (value);
}

void	var_var(t_len *len)
{
	int	var_len;

	var_len = 0;
	len->input_csr++;
	var_len = get_var_len(len->input + len->input_csr);
	if (var_len > 0)
		len->tmp = parse_env_var(len->input + len->input_csr, var_len);
	else
		len->tmp = ft_strdup("$");
	len->input_csr += var_len;
}
