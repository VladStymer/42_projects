/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:27:11 by loichu            #+#    #+#             */
/*   Updated: 2023/01/12 10:46:58 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liberrors_p.h>

void	set_message(t_error *error, char *message)
{
	int	i;

	i = -1;
	while (message[++i])
	{
		error->message[i] = message[i];
		if (i > ERROR_MAX_LEN)
			return (format_too_long());
	}
	error->message[i] = 0;
}

void	format_too_long(void)
{
	write(2, "Error message cannot be longer than 50 characters\n", 50);
}

void	*throw(t_error error)
{
	write(2, "minishell: ", 11);
	write(2, error.message, ft_strlen(error.message));
	write(2, "\n", 1);
	errno = error.code;
	return (NULL);
}

void	throw_void(t_error error)
{
	throw(error);
}

void	throw_exit(t_error error)
{
	throw(error);
	exit(error.code);
}
