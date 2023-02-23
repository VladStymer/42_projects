/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:05:16 by loichu            #+#    #+#             */
/*   Updated: 2023/01/13 17:47:39 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liberrors_p.h>

t_error	command_not_found(char *cmd_name)
{
	t_error	error;
	char	*msg;
	char	formatted[ERROR_MAX_LEN + 1];

	error.ok = false;
	error.code = 127;
	msg = "%s: command not found";
	fs(msg, cmd_name, formatted);
	set_message(&error, formatted);
	return (error);
}

t_error	unexpected_token(char *token)
{
	t_error	error;
	char	*msg;
	char	formatted[ERROR_MAX_LEN + 1];

	error.ok = false;
	error.code = 2;
	msg = "syntax error near unexpected token `%s'";
	fs(msg, token, formatted);
	set_message(&error, formatted);
	return (error);
}

t_error	unexpected_end_of_file(void)
{
	t_error	error;
	char	*msg;

	error.ok = false;
	error.code = 2;
	msg = "syntax error near unexpected end of file";
	set_message(&error, msg);
	return (error);
}

t_error	cannot_open_file(char *path)
{
	t_error	error;
	char	formatted[ERROR_MAX_LEN + 1];
	char	formatted2[ERROR_MAX_LEN + 1];

	error.ok = false;
	if (errno == 2)
	{
		error.code = 1;
		fs("%s: No such file or directory", path, formatted);
		set_message(&error, formatted);
	}
	else if (errno == 13)
	{
		error.code = 1;
		fs("%s: Permission denied", path, formatted);
		set_message(&error, formatted);
	}
	else
	{
		error.code = GENERIC_ERROR;
		fs("Cannot open file %s, error: %i", path, formatted);
		fi(formatted, error.code, formatted2);
		set_message(&error, formatted2);
	}
	return (error);
}

t_error	error_errno(char *msg)
{
	t_error	error;
	char	fmsg[ERROR_MAX_LEN + 1];
	char	formatted[ERROR_MAX_LEN + 1];

	error.ok = false;
	ft_strlcpy(fmsg, msg, ERROR_MAX_LEN + 1);
	ft_strlcat(fmsg, ": %i", ERROR_MAX_LEN + 1);
	error.code = errno;
	fi(fmsg, error.code, formatted);
	set_message(&error, formatted);
	return (error);
}
