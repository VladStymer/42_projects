/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:34:32 by loichu            #+#    #+#             */
/*   Updated: 2023/01/06 17:39:23 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <parser_defs.h>

t_node	*parse(char *input, t_parser_deps deps);
void	*free_tree(t_node *head);

#endif
