/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:58:46 by loichu            #+#    #+#             */
/*   Updated: 2023/01/07 18:44:26 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser_p.h>

t_error	validate_syntaxe(t_parser *parser)
{
	char	*token;

	token = next_token(parser, false);
	if (!token)
	{
		abort_parsing(parser);
		return (unexpected_end_of_file());
	}
	if (is_priority_token(token))
	{
		abort_parsing(parser);
		return (unexpected_token(token));
	}
	return (no_error());
}

void	switch_next_node(t_parser *parser)
{
	t_node	*next;

	next = parser->current->pipe->node;
	parser->parent = parser->current;
	parser->current = next;
	parser->from = parser->to;
	if (DEBUG)
		printf("\n[parser] switched to next node\n");
}

t_pipe	*init_pipe(t_node *node)
{
	t_pipe	*pipe;

	node->type = PIPE;
	node->pipe = (t_pipe *)protected_malloc(sizeof(t_pipe));
	pipe = node->pipe;
	if (DEBUG)
		printf("[parser] pipe (%p) created in node (%p)\n", pipe, node);
	pipe->node = init_node();
	if (DEBUG)
		printf("[parser] pipe next node created (%p)\n", pipe);
	return (pipe);
}

/*
 *	ENTRYPOINT FOR PIPES
 */
t_error	parse_pipe(t_parser *parser)
{
	t_pipe	*pipe;
	t_error	error;

	if (DEBUG)
		printf("\n[parser] started parsing pipe\n");
	error = validate_syntaxe(parser);
	if (!error.ok)
	{
		if (DEBUG)
			printf("[parser] pipe syntaxe KO - ERROR\n");
		return (error);
	}
	else if (DEBUG)
		printf("[parser] pipe syntaxe OK\n");
	pipe = init_pipe(parser->current);
	pipe->cmd = parse_cmd(parser);
	if (!pipe->cmd && !parser->last_error.ok)
		return (parser->last_error);
	if (DEBUG)
		printf("[parser] pipe left command parsed (%p)\n", pipe->cmd);
	switch_next_node(parser);
	return (no_error());
}
