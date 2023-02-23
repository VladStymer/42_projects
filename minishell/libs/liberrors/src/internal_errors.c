/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:47:34 by loichu            #+#    #+#             */
/*   Updated: 2023/01/12 16:29:02 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liberrors_p.h>

t_error	no_error(void)
{
	t_error	error;

	error.ok = true;
	error.code = 0;
	set_message(&error, "success, nothing's wrong");
	return (error);
}

t_error	real_unallocated_memory(void)
{
	t_error	error;
	char	*msg;

	error.ok = false;
	error.code = ENOMEM;
	msg = "Memory allocation failed";
	set_message(&error, msg);
	return (error);
}

t_error	not_implemented(void)
{
	t_error	error;
	char	*msg;

	error.ok = false;
	error.code = GENERIC_ERROR;
	msg = "Required action is not implemented";
	set_message(&error, msg);
	return (error);
}

t_error	missing_argument(char *arg_name)
{
	t_error	error;
	char	*msg;
	char	formatted[ERROR_MAX_LEN + 1];

	error.ok = false;
	error.code = GENERIC_ERROR;
	msg = "Required argument `%s` is NULL";
	fs(msg, arg_name, formatted);
	set_message(&error, formatted);
	return (error);
}

t_error	out_of_range_error(int x, char *fail, int y)
{
	t_error	error;
	char	*msg;
	char	formatted[ERROR_MAX_LEN + 1];
	char	formattmp[ERROR_MAX_LEN + 1];

	error.ok = false;
	error.code = GENERIC_ERROR;
	msg = "index out of range: %i %s %i\n";
	fi(msg, x, formatted);
	fs(formatted, fail, formattmp);
	fi(formattmp, y, formatted);
	set_message(&error, formatted);
	return (error);
}
