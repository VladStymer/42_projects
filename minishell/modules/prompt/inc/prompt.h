/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:47:55 by vnicoud           #+#    #+#             */
/*   Updated: 2023/01/01 12:07:48 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include "minishell.h"
# include "libft.h"
# include "utils.h"
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>

# define GREENB		"\033[1;32m"
# define GREEN		"\033[0;32m"
# define REDB		"\033[1;31m"
# define RED		"\033[0;31m"
# define YELLOWB	"\033[1;33m"
# define YELLOW		"\033[0;33m"
# define BLUEB		"\033[1;34m"
# define BLUE		"\033[0;34m"
# define PURPLEB	"\033[1;35m"
# define PURPLE		"\033[0;35m"
# define CYANB		"\033[1;36m"
# define CYAN		"\033[0;36m"
# define WHITEB		"\033[1;37m"
# define WHITE		"\033[0;37m"
# define RESET 		"\033[0m"

char		*prompt(void);

extern void	rl_replace_line(const char *str, int i);

#endif
