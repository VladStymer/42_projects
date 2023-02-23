/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:14:47 by vnicoud           #+#    #+#             */
/*   Updated: 2023/01/04 13:35:13 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

int	env_main(int argc, char **argv, char **env)
{
	(void)argv;
	if (argc > 1 || !is_inenv("PATH"))
	{
		if (!is_inenv("PATH"))
		{
			ft_putstr_fd(ft_strjoin("bash: env: ",
					": No such file or directory\n"), 2);
			return (127);
		}
		else if (argv[1][0] == '-' )
			return (1);
		return (127);
	}
	while (*env != NULL)
	{
		if (ft_strchr(*env, '=') != NULL)
		{
			ft_putstr_fd(*env, 1);
			ft_putstr_fd("\n", 1);
		}
		env++;
	}
	return (0);
}
