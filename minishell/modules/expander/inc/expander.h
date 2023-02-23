/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:05:15 by vlad              #+#    #+#             */
/*   Updated: 2023/01/05 16:34:24 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# define REALLOC_SIZE 32

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

# include "libft.h"
# include "utils.h"
# include <executor_defs.h>

# include <unistd.h>

typedef struct s_len
{
	int		input_csr;
	int		new_len;
	int		var_len;
	int		realloc_count;
	char	quote_state;
	char	prev_quote_state;
	char	*ptr;
	char	*new;
	char	*tmp;
	char	*input;
}	t_len;

char		*expander(char *input);

//_ft_mods.c
char		*ft_strchr(const char *s, int c);

// var
void		var_var(t_len *len);

//others
char		*make_tmp(char *tmp, char *input, int input_csr, t_len *len);
void		quote_me(char c, t_len *len);
void		set_struct(t_len *len, char *input);
void		expander_realloc(t_len *len);
void		if_tmp(t_len *len);

//_TEST
int			run_test(int fd);

#endif
