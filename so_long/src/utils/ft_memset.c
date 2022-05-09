/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:39:46 by vnicoud           #+#    #+#             */
/*   Updated: 2022/03/31 09:37:48 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	*ft_memset(void *b, int c, int len)
{
	int		i;
	char	*pointeurb;

	i = 0;
	pointeurb = b;
	while (i < len)
	{		
		pointeurb[i] = c;
		i++;
	}
	return (pointeurb);
}
