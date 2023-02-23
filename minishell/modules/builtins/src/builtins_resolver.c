/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_resolver.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:23:36 by vnicoud           #+#    #+#             */
/*   Updated: 2023/01/02 16:55:51 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <stdio.h>
#include <string.h>

t_function_pointer	resolve_builtin(char *str)
{
	if (!(ft_strncmp(str, "cd", 5)))
		return (&cd_main);
	else if (!(ft_strncmp(str, "echo", 5)))
		return (&echo_main);
	else if (!(ft_strncmp(str, "env", 5)))
		return (&env_main);
	else if (!(ft_strncmp(str, "exit", 5)))
		return (&exit_main);
	else if (!(ft_strncmp(str, "export", 7)))
		return (&export_main);
	else if (!(ft_strncmp(str, "pwd", 5)))
		return (&pwd_main);
	else if (!(ft_strncmp(str, "unset", 6)))
		return (&unset_main);
	else
		return (NULL);
}
