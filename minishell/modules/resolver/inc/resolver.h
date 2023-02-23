/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:29:12 by vnicoud           #+#    #+#             */
/*   Updated: 2022/12/21 12:57:10 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLVER_H
# define RESOLVER_H

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

# include "minishell.h"
# include "libft.h"
# include "utils.h"
# include <unistd.h>

char	**free_nd(char **tab, char *path);
char	*add_cmd(char *path, char *cmd, int pathl, int cmdl);
int		path_len(char *path);
char	*resolve(char *exec);

#endif
