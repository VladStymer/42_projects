/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:14:47 by vnicoud           #+#    #+#             */
/*   Updated: 2023/01/11 21:21:06 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <errno.h>

int	cd_error(char **argv)
{
	if (errno == ENOTDIR)
		ft_putstr_fd((join3("cd: ", argv[1],
					": not a directory\n")), 2);
	else if (errno == ENOENT)
		ft_putstr_fd((join3("cd: ", argv[1],
					": No such file or directory\n")), 2);
	else if (errno == EACCES)
		ft_putstr_fd((join3("cd: ", argv[1],
					": Permission denied\n")), 2);
	else if (errno == ELOOP)
		ft_putstr_fd((join3("cd: ", argv[1],
					": too many levels of symbolic links\n")), 2);
	else if (errno == ENAMETOOLONG)
		ft_putstr_fd((join3("cd: ", argv[1],
					": File name too long\n")), 2);
	else
		ft_putstr_fd("unknow error\n", 2);
	return (1);
}

char	*get_home(void)
{
	char	*home;

	home = get_envvar_value("HOME");
	if (!home || !(home[1]))
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (NULL);
	}
	return (home);
}

int	cd_main(int argc, char **argv, char **env)
{
	int		ret;

	(void)env;
	ret = 0;
	if (argc > 2)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (1);
	}
	if (argc == 1)
	{
		if (get_home())
			ret = chdir(get_home());
		else
			return (1);
	}
	if (argc == 2)
		ret = chdir(argv[1]);
	if (ret != 0)
		return (cd_error(argv));
	return (0);
}
