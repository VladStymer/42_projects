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

void	print_export(int size)
{
	int		i;
	int		j;
	char	**env;
	char	*assigned;

	i = -1;
	env = ft_getenv();
	while (++i < size)
	{
		assigned = "";
		ft_putstr_fd("declare -x ", 1);
		j = -1;
		while (env[i][++j] != '\0')
		{
			if (env[i][j] == '=')
			{
				ft_putchar_fd(env[i][j], 1);
				ft_putstr_fd("\"", 1);
				assigned = "\"";
			}
			else
				ft_putchar_fd(env[i][j], 1);
		}
		ft_putstr_fd(ft_strjoin(assigned, "\n"), 1);
	}
}

void	sortnprint_export(char **env)
{
	size_t	i;
	size_t	size;
	char	*temp;

	i = 0;
	size = 0;
	while (env[size] != NULL)
		size++;
	while (1)
	{
		if (ft_strncmp(env[i], env[i + 1], ft_strlen(env[i + 1])) > 0)
		{
			temp = env[i];
			env[i] = env[i + 1];
			env[i + 1] = temp;
			i = 0;
		}
		else
			i++;
		if (i == size - 1)
			break ;
	}
	print_export(size);
}
