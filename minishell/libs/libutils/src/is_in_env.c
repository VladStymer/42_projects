/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:43:28 by vnicoud           #+#    #+#             */
/*   Updated: 2023/01/05 23:32:06 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	comp_until_equal(const char *str1, const char *str2)
{
	while ((*str1 == *str2 && *str1 != '\0') && (*str2 != '\0' && *str1 != '='))
	{
		str1++;
		str2++;
	}
	if ((*str1 == '=' && *str2 == '=') || (*str1 == '\0' && *str2 == '\0'))
		return (1);
	return (0);
}

int	is_inenv(const char *name)
{
	size_t	i;
	size_t	j;
	char	*tmp;
	char	**env;

	j = 0;
	i = ft_strlen(name);
	env = ft_getenv();
	tmp = protected_malloc(sizeof(char *) * i);
	i = -1;
	while (name[++i])
		tmp[i] = name[i];
	tmp[i] = '=';
	tmp[i + 1] = '\0';
	while (env[j] != NULL)
	{
		if (comp_until_equal(tmp, env[j]))
		{	
			free(tmp);
			return (1);
		}
		j++;
	}
	free(tmp);
	return (0);
}
