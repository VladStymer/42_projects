/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberrors_p.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:13:10 by loichu            #+#    #+#             */
/*   Updated: 2023/01/12 15:54:46 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBERRORS_P_H
# define LIBERRORS_P_H
# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>

# include <libft.h>
# include <liberrors.h>

t_error	real_unallocated_memory(void);
void	set_message(t_error *error, char *message);
void	format_too_long(void);
void	fi(char *format, int i, char *ref);
void	fs(char *format, char *replace, char *ref);

#endif
