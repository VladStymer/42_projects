/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:07:54 by lhumbert          #+#    #+#             */
/*   Updated: 2023/01/13 17:55:39 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executor_p.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void	print_error_start(char *exec)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(exec, 2);
	ft_putstr_fd(": ", 2);
}

int	error_noaccess(char *exec)
{
	struct stat	path_stat;

	stat(exec, &path_stat);
	print_error_start(exec);
	if (S_ISDIR(path_stat.st_mode))
		ft_putstr_fd("Is a directory\n", 2);
	if (access(exec, X_OK) == -1)
		ft_putstr_fd("Permission denied\n", 2);
	return (126);
}

void	execve_error(char *exec)
{
	int	error;

	if (errno == 2)
	{
		print_error_start(exec);
		ft_putstr_fd("No such file or directory\n", 2);
		error = 127;
	}
	else if (errno == 13)
		exit(error_noaccess(exec));
	else
	{
		throw(error_errno("execve failed"));
		error = errno;
	}
	exit(error);
}
