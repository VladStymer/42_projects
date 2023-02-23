/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_p.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:44:30 by loichu            #+#    #+#             */
/*   Updated: 2023/01/08 17:18:34 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_P_H
# define PARSER_P_H

/********************
*	Private includes
********************/

// System libraries
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

// Our own libraries
# include <libft.h>
# include <utils.h>
# include <liberrors.h>

// Other module's headers
# include <parser.h>
# include <parser_defs.h>

// Private constants for module
# define ARGV_REALLOC_SIZE 8

/**************************************
*	Private types/aliases for module
************************************/

typedef t_parser_deps	t_deps;

typedef char			*(*t_expander)(char *);

typedef struct s_parser
{
	int		from;
	int		to;
	char	**tokens;
	t_node	*head;
	t_node	*current;
	t_node	*parent;
	t_deps	deps;
	t_error	last_error;
}	t_parser;

/***********************
*	Private functions
*********************/

// parser.c
void	abort_parsing(t_parser *parser);
t_node	*init_node(void);

// parse_token.c
char	*get_token(t_parser *parser);
char	*next_token(t_parser *parser, bool move_cursor);
t_error	parse_token(char *token, t_parser *parser);

// file_tokens.c
bool	is_read(char *token);
bool	is_heredoc(char *token);
bool	is_write(char *token);
bool	is_append(char *token);
bool	token_expects_file(char *token);

// priority_tokens.c
bool	is_pipe(char *token);
bool	is_and(char *token);
bool	is_or(char *token);
bool	is_short_circuit(char *token);
bool	is_priority_token(char *token);

// tokens_range.c
char	**get_tokens_range(t_parser *parser);

// pipes.c
t_error	parse_pipe(t_parser *parser);

// cmds.c
t_cmd	*parse_cmd(t_parser *parser);
t_error	make_last_cmd(t_parser *parser);

// argv.c
t_error	argv_add(t_cmd *cmd, char *token);

// file_lists.c
t_error	add_file(t_cmd *cmd, char **tokens, int index, t_expander expand);

// files.c
t_error	get_path(char *token, char **real_path, t_expander expand);
t_file	*init_file(char *io_red, char *fpath);

// free_ast.c
void	*free_cmd(t_cmd *cmd);
void	*free_pipe(t_pipe *pipe);
void	*free_shortc(t_shortc *shortc);
void	*free_files(t_file *head);

#endif
