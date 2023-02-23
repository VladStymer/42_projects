/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:51:46 by vnicoud           #+#    #+#             */
/*   Updated: 2023/01/04 10:13:07 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include <stdarg.h>
#include <readline/readline.h>
#include <readline/history.h>

void	sig_end_child(int sig)
{
	(void) sig;
	write(2, "\n", 1);
}

char	*get_prompt(void)
{
	char	cwd[1024];
	char	*tmp1;
	char	*tmp2;

	getcwd(cwd, sizeof(cwd));
	tmp1 = ft_strjoin(""GREENB"minishell: "CYANB"[", cwd);
	tmp2 = ft_strjoin(tmp1, "] "REDB"$"RESET" ");
	free(tmp1);
	return (tmp2);
}

void	exit_shell(void)
{
	write(1, "\n", 1);
	exit(0);
}

void	signal_handler(int sig)
{
	(void)sig;
	write(2, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	term_handler(void)
{
	struct termios	term_flag;

	tcgetattr(0, &term_flag);
	term_flag.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &term_flag);
}
