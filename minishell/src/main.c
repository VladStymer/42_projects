/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:13:15 by loichu            #+#    #+#             */
/*   Updated: 2023/01/12 16:26:29 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <tokenizer.h>
#include <parser.h>
#include <expander.h>
#include <builtins.h>
#include <prompt.h>
#include <executor.h>
#include <resolver.h>
#include <file_handler.h>
#include <utils.h>
#include <liberrors.h>

int	g_last_exit_code = 0;

char	**malloc_envp(char **envp)
{
	int		i;
	char	**new_env;

	i = -1;
	new_env = (char **)protected_malloc((count_tab(envp) + 1) * sizeof(char *));
	while (envp[++i])
	{
		new_env[i] = ft_strdup(envp[i]);
		if (!new_env[i])
			throw_exit(unallocated_memory());
	}
	new_env[i] = NULL;
	return (new_env);
}

static t_parser_deps	init_parser(void)
{
	t_parser_deps	parser_deps;

	parser_deps.expand = &expander;
	parser_deps.tokenize = &tokenize;
	parser_deps.free_tokens = &free_tokens;
	return (parser_deps);
}

t_executor_deps	init_executor(void)
{
	t_executor_deps	executor_deps;

	executor_deps.open_file = &open_file;
	executor_deps.resolve = &resolve;
	executor_deps.resolve_builtin = &resolve_builtin;
	executor_deps.close_fd = &close_fd;
	return (executor_deps);
}

void	run_main(char *input, t_node *ast)
{
	input = prompt();
	if (ft_strlen(input) == 0)
	{
		g_last_exit_code = 0;
		return ;
	}
	ast = parse(input, init_parser());
	if (!ast)
	{
		if (DEBUG)
			printf("AST error\n");
		g_last_exit_code = errno;
		return ;
	}
	g_last_exit_code = execute(ast, init_executor());
	free_tree(ast);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_node	*ast;

	input = NULL;
	ast = NULL;
	signal(SIGINT, signal_handler);
	ft_init_env(malloc_envp(envp));
	if (argc == 3 && !ft_strncmp(argv[1], "-c", 3))
	{
		input = argv[2];
		ast = parse(input, init_parser());
		if (!ast)
		{
			return (errno);
		}
		g_last_exit_code = execute(ast, init_executor());
		free_tree(ast);
		return (g_last_exit_code);
	}
	while (1)
		run_main(input, ast);
}
