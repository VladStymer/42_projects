/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:58:46 by vnicoud           #+#    #+#             */
/*   Updated: 2023/01/05 07:58:06 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

int	set_newvalue(int i, char *name, char *value)
{
	char	**env;
	char	*tmpfree;

	env = ft_getenv();
	tmpfree = env[i];
	env[i] = protected_malloc(ft_strlen(name) + ft_strlen(value) + 2);
	free(tmpfree);
	ft_strlcpy(env[i], name, ft_strlen(name) + 1);
	ft_strlcat(env[i], "=", ft_strlen(name) + 2);
	ft_strlcat(env[i], value, ft_strlen(name) + ft_strlen(value) + 2);
	free(name);
	free(value);
	return (0);
}

int	replace_envvalue(char *string)
{
	char	**env;
	int		i;
	char	*equal_sign;
	char	*name;
	char	*value;

	i = -1;
	env = ft_getenv();
	equal_sign = ft_strchr(string, '=');
	if (!equal_sign)
		return (0);
	name = protected_malloc(equal_sign - string + 1);
	value = protected_malloc(ft_strlen(equal_sign + 1) + 1);
	ft_strlcpy(name, string, equal_sign - string + 1);
	name[equal_sign - string] = '\0';
	ft_strlcpy(value, equal_sign + 1, ft_strlen(equal_sign + 1) + 1);
	value[ft_strlen(equal_sign) - 1] = '\0';
	while (env[++i])
		if (ft_strncmp(env[i], name, ft_strlen(name)) == 0)
			return (set_newvalue(i, name, value));
	free(name);
	free(value);
	return (1);
}

int	add_str_to_env(char **env, char *string)
{
	int		length;
	int		i;
	char	**new_env;

	length = 0;
	i = -1;
	env = ft_getenv();
	if (is_inenv(string))
		return (replace_envvalue(string));
	while (env[++i] != NULL)
		length++;
	new_env = (char **) protected_malloc((length + 2) * sizeof(char *));
	if (new_env == NULL)
		return (1);
	i = -1;
	while (++i < length)
		new_env[i] = ft_strdup(env[i]);
	new_env[length] = (char *) protected_malloc(strlen(string) + 1);
	ft_strlcpy(new_env[length], string, i);
	new_env[length + 1] = NULL;
	ft_init_env(new_env);
	return (0);
}

int	is_validenvarg(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (ft_isdigit(argv[i][0]))
		{
			ft_putstr_fd((join3("minishell: export: ", argv[i],
						": not a valid identifier\n")), 2);
			return (0);
		}
		else if (!ft_isalnum(argv[i][0]) && argv[i][0] != '_')
		{
			ft_putstr_fd((join3("minishell: export: ", argv[i],
						": not a valid identifier\n")), 2);
			return (0);
		}
	}
	return (1);
}

int	export_main(int argc, char **argv, char **env)
{
	int	i;

	i = 0;
	if (argc == 1)
		sortnprint_export(env);
	if (!is_validenvarg(argv))
		return (1);
	else if (argc == 2 && argv[1][0] == '=')
	{
		ft_putstr_fd((join3("bash: export: `", argv[1],
					"': not a valid identifier\n")), 2);
		return (1);
	}
	else
		while (++i != argc)
			add_str_to_env(env, argv[i]);
	return (0);
}
