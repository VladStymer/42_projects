/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:29:35 by loichu            #+#    #+#             */
/*   Updated: 2023/01/12 18:58:41 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser_p.h>

void	abort_parsing(t_parser *parser)
{
	free(parser->current);
	if (parser->parent)
		parser->parent->pipe->node = NULL;
	else
		parser->head = NULL;
}

t_node	*init_node(void)
{
	t_node	*new_node;

	new_node = (t_node *)protected_malloc(sizeof(t_node));
	new_node->type = UNDEFINED;
	new_node->cmd = NULL;
	if (DEBUG)
		printf("[parser] created new node (%p)\n", new_node);
	return (new_node);
}

/*
 *	MAIN LOOP FOR ALL THE PARSING
 */
t_node	*parse_loop(t_parser *parser)
{
	t_node	*head;
	char	*token;
	t_error	error;

	head = init_node();
	parser->current = head;
	parser->parent = NULL;
	token = get_token(parser);
	while (token)
	{
		if (DEBUG)
			printf("[parser] get token: %s\n", token);
		error = parse_token(token, parser);
		if (error.ok && !next_token(parser, true))
		{
			error = make_last_cmd(parser);
		}
		if (!error.ok)
		{
			return (throw(error));
		}
		token = get_token(parser);
	}
	return (head);
}

t_parser	init_parser(char *input, t_deps deps)
{
	t_parser	parser;

	parser.from = -1;
	parser.to = 0;
	parser.tokens = deps.tokenize(input);
	if (!parser.tokens)
	{
		if (DEBUG)
			printf("[pasrer] Could not get tokens\n");
		errno = 0;
	}
	parser.current = NULL;
	parser.parent = NULL;
	parser.deps = deps;
	parser.last_error = no_error();
	return (parser);
}

/*
 *	PUBLIC PARSER ENTRYPOINT
 */
t_node	*parse(char *input, t_parser_deps deps)
{
	t_parser	parser;
	t_node		*head;
	int			i;

	if (DEBUG)
		printf("\n[parser] START PARSING %s\n", input);
	parser = init_parser(input, deps);
	if (DEBUG)
		printf("[parser] initialized parser with tokens\n");
	if (!parser.tokens || !parser.tokens[0])
		return (NULL);
	if (is_priority_token(parser.tokens[0]))
	{
		throw(unexpected_token(parser.tokens[0]));
		deps.free_tokens(parser.tokens);
		return (NULL);
	}
	head = parse_loop(&parser);
	if (!head)
		free_tree(parser.head);
	i = -1;
	while (parser.tokens[++i])
		free(parser.tokens[i]);
	free(parser.tokens);
	return (head);
}
