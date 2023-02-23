/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:33:55 by vnicoud           #+#    #+#             */
/*   Updated: 2023/01/04 14:31:57 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

// TODO: call exitshell when exit.
int	exit_main(int argc, char **argv, char **env)
{
	int	i;

	(void)env;
	i = -1;
	ft_putstr_fd("exit\n", 2);
	if (argc == 1)
		exit(0);
	if (argv[1][0] == '-')
		i++;
	while (argv[1][++i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_putstr_fd((join3("minishell: exit: ", argv[1],
						": numeric argument required\n")), 2);
			exit(255);
		}
	}	
	exit(ft_atoi(argv[1]));
}
