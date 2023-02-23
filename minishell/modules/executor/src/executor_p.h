/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_p.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:22:36 by loichu            #+#    #+#             */
/*   Updated: 2023/01/13 15:02:27 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_P_H
# define EXECUTOR_P_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

# include <executor_defs.h>
# include <parser_defs.h>

# include <libft.h>
# include <liberrors.h>
# include <utils.h>

typedef t_executor_deps		t_deps;
typedef t_function_pointer	t_builtin;

// pipes.c
int		exec_pipes(t_node *head, t_executor_deps deps);

// exec.c
pid_t	exec_cmd(t_cmd *cmd, pid_t *pfd, t_deps deps);
int		exec_builtin(t_cmd *cmd, t_builtin builtin, pid_t *pfd, t_deps deps);

// execve_errors.c
void	execve_error(char *exec);

// fds.c
int		*get_and_dup_fds(t_cmd *cmd, int *pfd, t_deps deps, int *io);

// save_std_io.c
void	restore_std_io(int *saved_io);
void	save_std_io(t_cmd *cmd, int *saved_io);

#endif
