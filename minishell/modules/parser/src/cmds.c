/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:09:59 by loichu            #+#    #+#             */
/*   Updated: 2023/01/10 22:05:26 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser_p.h>

void	*abort_cmd(t_parser *parser, t_cmd *cmd, t_error error)
{
	t_node	*node;

	if (DEBUG)
		printf("[parser] abort and free cmd, reason: %s\n", error.message);
	free_cmd(cmd);
	parser->last_error = error;
	node = parser->current;
	if (node->type == CMD)
	{
		if (DEBUG)
			printf("[parser] set NULL node->cmd (%p)\n", node->cmd);
		node->cmd = NULL;
		abort_parsing(parser);
	}
	else if (node->type == PIPE)
	{
		if (DEBUG)
			printf("[parser] set NULL node->pipe->cmd (%p)\n", node->pipe->cmd);
		node->pipe->cmd = NULL;
	}
	return (NULL);
}

t_error	make_last_cmd(t_parser *parser)
{
	t_node	*last_node;

	if (DEBUG)
		printf("\n[parser] parsing last command...\n");
	last_node = parser->current;
	last_node->type = CMD;
	last_node->cmd = parse_cmd(parser);
	if (!last_node->cmd)
		return (parser->last_error);
	if (DEBUG)
		printf("[parser] last command successfully created !\n");
	return (no_error());
}

static t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)protected_malloc(sizeof(t_cmd));
	cmd->argc = 0;
	cmd->argv = NULL;
	cmd->input = NULL;
	cmd->output = NULL;
	cmd->fd_in = 0;
	cmd->fd_out = 1;
	return (cmd);
}

/*
 *	ENTRYPOINT FOR COMMANDS
 */
t_cmd	*parse_cmd(t_parser *parser)
{
	t_cmd	*cmd;
	char	**tokens;
	int		i;
	t_error	error;

	error = no_error();
	tokens = get_tokens_range(parser);
	cmd = init_cmd();
	i = -1;
	while (tokens[++i])
	{
		if (DEBUG)
			printf("[parser] parsing token `%s' in command\n", tokens[i]);
		if (token_expects_file(tokens[i]))
			error = add_file(cmd, tokens, i++, parser->deps.expand);
		else
			error = argv_add(cmd, parser->deps.expand(tokens[i]));
		if (!error.ok)
			break ;
	}
	free(tokens);
	if (!error.ok)
		return (abort_cmd(parser, cmd, error));
	return (cmd);
}
