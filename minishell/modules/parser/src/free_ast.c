/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:00:42 by loichu            #+#    #+#             */
/*   Updated: 2023/01/08 17:22:09 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser_p.h>

void	*free_tree(t_node *head)
{
	if (!head)
		return (NULL);
	if (DEBUG)
		printf("[parser] FREE WHOLE TREE from head: %p\n", head);
	if (head->type == CMD)
	{
		head->cmd = free_cmd(head->cmd);
	}
	else if (head->type == PIPE)
	{
		head->pipe = free_pipe(head->pipe);
	}
	else if (head->type == SHORTC)
	{
		head->shortc = free_shortc(head->shortc);
	}
	else if (DEBUG)
	{
		printf("free tree undefined node type\n");
	}
	free(head);
	return (NULL);
}

void	*free_cmd(t_cmd *cmd)
{
	int		i;

	if (!cmd)
		return (NULL);
	if (DEBUG)
		printf("[parser] free cmd (%p) => argv (%p)\n", cmd, cmd->argv);
	i = -1;
	while (++i < cmd->argc && cmd->argv[i])
	{
		free(cmd->argv[i]);
		cmd->argv[i] = NULL;
	}
	free(cmd->argv);
	cmd->argv = NULL;
	cmd->input = free_files(cmd->input);
	cmd->output = free_files(cmd->output);
	free(cmd);
	return (NULL);
}

void	*free_files(t_file *head)
{
	t_file	*temp;

	while (head)
	{
		if (DEBUG)
			printf("[parser] free file (%p)\n", head);
		temp = head->next;
		free(head->path);
		head->path = NULL;
		head->next = NULL;
		free(head);
		head = temp;
	}
	return (NULL);
}

void	*free_pipe(t_pipe *pipe)
{
	if (DEBUG)
		printf("[parser] free pipe (%p)\n", pipe);
	pipe->cmd = free_cmd(pipe->cmd);
	if (pipe->node)
		pipe->node = free_tree(pipe->node);
	free(pipe);
	return (NULL);
}

void	*free_shortc(t_shortc *shortc)
{
	if (DEBUG)
		printf("[parser] free shortc (%p)\n", shortc);
	free_tree(shortc->left);
	shortc->left = NULL;
	free_tree(shortc->right);
	shortc->right = NULL;
	free(shortc);
	return (NULL);
}
