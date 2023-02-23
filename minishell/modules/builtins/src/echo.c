/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:14:47 by vnicoud           #+#    #+#             */
/*   Updated: 2023/01/04 13:34:55 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

void	echo(char **str, int strict)
{
	int	i;

	i = 0;
	if (strict)
		i++;
	while (str[++i])
	{
		ft_putstr_fd(str[i], 1);
		if (str[i + 1])
			ft_putstr_fd(" ", 1);
	}
	if (strict)
		return ;
	ft_putstr_fd("\n", 1);
}

int	echo_main(int argc, char **argv, char **env)
{
	int	strict;

	(void)env;
	strict = 0;
	if (argc == 1)
	{
		ft_putstr_fd("\n", 1);
		return (0);
	}
	if (!(ft_strncmp(argv[1], "-n", 2)) && !argv[1][2])
		strict = 1;
	echo(argv, strict);
	return (0);
}
