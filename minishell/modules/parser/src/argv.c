/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:06:41 by loichu            #+#    #+#             */
/*   Updated: 2023/01/10 22:06:41 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser_p.h>

int	get_realloc_size(int nb_chunks)
{
	return (nb_chunks * ARGV_REALLOC_SIZE * sizeof(char *));
}

char	**realloc_argv(int nb_chunks, char **argv)
{
	char	**_tmp_;

	if (DEBUG)
	{
		printf("[parser] realloc argv resize: %i -> %i\n",
			get_realloc_size(nb_chunks),
			get_realloc_size(nb_chunks + 1));
	}
	_tmp_ = NULL;
	_tmp_ = (char **)ft_realloc(argv,
			get_realloc_size(nb_chunks),
			get_realloc_size(nb_chunks + 1));
	if (_tmp_ == NULL)
	{
		throw_exit(unallocated_memory());
	}
	return (_tmp_);
}

/*
 *	ENTRYPOINT FOR ARGV
 */
t_error	argv_add(t_cmd *cmd, char *token)
{
	static int	nb_chunks = 0;
	int			argc;

	if (!cmd->argv && cmd->argc == 0)
	{
		nb_chunks = 0;
	}
	if (!token)
	{
		return (missing_argument("token"));
	}
	if (cmd->argc + 1 >= get_realloc_size(nb_chunks))
	{
		if (DEBUG)
			printf("[parser] realloc argv ptr (before): %p\n", cmd->argv);
		cmd->argv = realloc_argv(nb_chunks++, cmd->argv);
		if (DEBUG)
			printf("[parser] realloc argv ptr (after): %p\n", cmd->argv);
	}
	cmd->argv[cmd->argc] = token;
	argc = ++(cmd->argc);
	cmd->argv[argc] = NULL;
	return (no_error());
}
