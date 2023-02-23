/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_defs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:21:13 by loichu            #+#    #+#             */
/*   Updated: 2023/01/07 19:23:28 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_DEFS_H
# define PARSER_DEFS_H

typedef struct s_parser_deps
{
	char	*(*expand)(char *);
	char	**(*tokenize)(char *);
	void	(*free_tokens)(char **);
}	t_parser_deps;

typedef enum e_open_mode
{
	WRITE,
	APPEND,
	READ,
	HEREDOC,
}	t_open_mode;

typedef struct s_file
{
	char			*path;
	t_open_mode		mode;
	struct s_file	*next;
}	t_file;

typedef struct s_cmd
{
	char	**argv;
	int		argc;
	int		fd_in;
	int		fd_out;
	t_file	*input;
	t_file	*output;
}	t_cmd;

typedef enum e_node_type
{
	CMD,
	PIPE,
	SHORTC,
	UNDEFINED,
}	t_node_type;

typedef struct s_node
{
	t_node_type	type;
	union
	{
		struct s_cmd	*cmd;
		struct s_pipe	*pipe;
		struct s_shortc	*shortc;
	};
}	t_node;

typedef struct s_pipe
{
	t_cmd	*cmd;
	t_node	*node;
}	t_pipe;

typedef struct s_shortc
{
	t_node	*left;
	t_node	*right;
}	t_shortc;

#endif
