/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:48:00 by vnicoud           #+#    #+#             */
/*   Updated: 2023/01/10 22:01:15 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include <readline/readline.h>
#include <readline/history.h>

char	*prompt(void)
{
	char	*command;
	char	*tmp2;

	term_handler();
	signal(SIGQUIT, SIG_IGN);
	tmp2 = get_prompt();
	command = readline(tmp2);
	if (command == NULL)
		exit(0);
	add_history(command);
	free(tmp2);
	return (command);
}
