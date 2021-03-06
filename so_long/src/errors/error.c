/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:43:20 by vnicoud           #+#    #+#             */
/*   Updated: 2022/05/09 10:15:04 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	error(char *str)
{
	printf("\033[31;1;4m" " Error\n    %s\n" "\033[0m", str);
	return (0);
}

void	*null_error(char *str)
{
	printf("\033[31;1;4m" " Error\n    %s\n" "\033[0m", str);
	return (0);
}
