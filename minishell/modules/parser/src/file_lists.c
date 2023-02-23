/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:57:43 by loichu            #+#    #+#             */
/*   Updated: 2023/01/10 22:03:31 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser_p.h>

/*
 *	Returns a pointer on the correct command's IO file list
 */
t_file	**get_io_file_list(t_cmd *cmd, t_open_mode mode)
{
	if (mode == READ || mode == HEREDOC)
	{
		if (DEBUG)
			printf("[parser] adding file to INPUT redirection\n");
		return (&(cmd->input));
	}
	if (mode == WRITE || mode == APPEND)
	{
		if (DEBUG)
			printf("[parser] adding file to OUTPUT redirection\n");
		return (&(cmd->output));
	}
	if (DEBUG)
		printf("[parser] get_io_file_list: undefined data\n");
	return (throw(not_implemented()));
}

void	append_file(t_file *list, t_file *new)
{
	if (!list)
		return (throw_void(missing_argument("list")));
	while (list->next)
	{
		list = list->next;
	}
	list->next = new;
}

/*
 *  MAIN PARSING FUNCTION FOR FILES
 *
 *	This function gets called by the main loop. Entry point for files.
 */
t_error	add_file(t_cmd *cmd, char **tokens, int index, t_expander expand)
{
	t_error		error;
	char		*real_path;
	t_file		**cmd_io_list;
	t_file		*new_file;
	char		*io_red;

	real_path = NULL;
	io_red = tokens[index];
	error = get_path(tokens[index + 1], &real_path, expand);
	if (!error.ok)
		return (error);
	new_file = init_file(io_red, real_path);
	cmd_io_list = get_io_file_list(cmd, new_file->mode);
	if (!cmd_io_list)
	{
		return (
			error_errno("something went wrong with the command IO files list"));
	}
	if (!*cmd_io_list)
	{
		*cmd_io_list = new_file;
		return (no_error());
	}
	append_file(*cmd_io_list, new_file);
	return (no_error());
}
