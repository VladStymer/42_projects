/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:39:58 by vnicoud           #+#    #+#             */
/*   Updated: 2023/01/12 16:08:48 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

char	**ft_init_env(char **envp)
{
	static char	**env;
	int			i;

	if (!envp)
		return (env);
	i = -1;
	if (env)
	{
		while (env[++i])
			free(env[i]);
		free(env);
	}
	env = envp;
	return (env);
}

char	**ft_getenv(void)
{
	char	**env;
	int		i;

	env = ft_init_env(NULL);
	if (DEBUG)
	{
		i = -1;
		while (env[++i])
			printf("env[%i] = %s\n", i, env[i]);
	}
	return (env);
}

char	*ft_strcpy_fromto(char *src, int start)
{
	int		i;
	int		j;
	int		value_len;
	char	*dst;

	i = -1;
	j = start + 1;
	value_len = 0;
	while (src[j++])
		value_len++;
	dst = (char *)protected_malloc((value_len + 1) * sizeof(char));
	i = 0;
	while (src[++start])
		dst[i++] = src[start];
	dst[i] = '\0';
	return (dst);
}

char	*get_envvar_value(char *var)
{
	int		i;
	int		var_len;
	char	**env;

	i = -1;
	env = ft_getenv();
	var_len = ft_strlen(var);
	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], var, var_len) == 0 && env[i][var_len] == '=')
			return (ft_strcpy_fromto(env[i], var_len));
	}
	return (ft_strdup(""));
}
