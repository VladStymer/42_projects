/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberrors_defs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:41:38 by loichu            #+#    #+#             */
/*   Updated: 2023/01/12 09:59:32 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBERRORS_DEFS_H
# define LIBERRORS_DEFS_H

# include <stdbool.h>

# define GENERIC_ERROR -1
# define ERROR_MAX_LEN 50
# define INT_MAX_DIGITS 11

typedef struct s_error
{
	bool	ok;
	int		code;
	char	message[ERROR_MAX_LEN + 1];
}	t_error;

#endif
