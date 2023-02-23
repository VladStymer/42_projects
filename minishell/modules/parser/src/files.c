/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:30:08 by loichu            #+#    #+#             */
/*   Updated: 2023/01/07 17:28:02 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser_p.h>

t_open_mode	get_mode(char *token)
{
	if (is_read(token))
	{
		return (READ);
	}
	else if (is_heredoc(token))
	{
		return (HEREDOC);
	}
	else if (is_write(token))
	{
		return (WRITE);
	}
	else if (is_append(token))
	{
		return (APPEND);
	}
	if (DEBUG)
		printf("get mode\n");
	throw_exit(not_implemented());
	return (0);
}

t_file	*init_file(char *io_red, char *fpath)
{
	t_file	*file;

	file = (t_file *)protected_malloc(sizeof(t_file));
	file->path = fpath;
	file->mode = get_mode(io_red);
	file->next = NULL;
	return (file);
}

bool	is_filename(char *token)
{
	if (is_priority_token(token) || token_expects_file(token))
		return (false);
	return (true);
}

/*
 *	In this function we could implement the bonus for wildcards
 */
t_error	get_path(char *token, char **real_path, t_expander expand)
{
	if (!token)
		return (unexpected_token("newline"));
	if (!is_filename(token))
		return (unexpected_token(token));
	*real_path = expand(token);
	if (!*real_path)
		return (missing_argument("real_path (after expand)"));
	return (no_error());
}
