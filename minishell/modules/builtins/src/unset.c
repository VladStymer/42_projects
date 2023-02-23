/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:33:59 by vnicoud           #+#    #+#             */
/*   Updated: 2023/01/11 21:46:36 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include <utils.h>

void	printgetenv(void)
{
	char	**env;
	int		i;

	i = -1;
	env = ft_getenv();
	while (env[++i])
		printf("env == %s\n", env[i]);
}

char	**copy_to_new_env(char **env, int i, char **new_env, int j)
{
	int	len;

	len = ft_strlen(env[i]);
	new_env[j] = (char *)protected_malloc(len + 1 * sizeof(char));
	ft_strlcpy(new_env[j], env[i], len + 1);
	return (new_env);
}

int	count_envvars(char **env, char *name)
{
	int	i;
	int	len;
	int	count;

	count = 0;
	len = ft_strlen(name);
	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], name, len))
			count++;
	}
	if (DEBUG)
		printf("[unset] nb env vars: %i\n", count);
	return (count);
}

int	ft_unsetenv(char *name)
{
	int		len;
	char	**env;
	char	**new_env;
	int		i;
	int		j;

	new_env = NULL;
	env = ft_getenv();
	len = ft_strlen(name);
	new_env = (char **)protected_malloc(
			(count_envvars(env, name) + 1) * sizeof(char *));
	i = -1;
	j = 0;
	while (env[++i])
	{
		if (ft_strncmp(env[i], name, len))
			copy_to_new_env(env, i, new_env, j++);
	}
	new_env[j] = NULL;
	ft_init_env(new_env);
	return (0);
}

int	unset_main(int argc, char **argv, char **env)
{
	int		i;

	(void)env;
	i = 0;
	if (argc <= 1)
		return (0);
	while (++i < argc)
	{
		if (DEBUG)
		{
			printf("[unset]\n argc == %d\n", argc);
			printf(" i == %d\n", i);
			printf(" argv[i] == %s\n", argv[i]);
		}
		ft_unsetenv(argv[i]);
	}
	return (0);
}
