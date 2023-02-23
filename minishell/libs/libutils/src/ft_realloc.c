/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:32:33 by loichu            #+#    #+#             */
/*   Updated: 2022/09/21 16:03:43 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_realloc(void *ptr, size_t o_size, size_t d_size)
{
	void	*new_ptr;

	if (d_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (!ptr)
	{
		return (malloc(d_size));
	}
	else if (d_size <= o_size)
	{
		return (ptr);
	}
	else
	{
		new_ptr = malloc(d_size);
		if (new_ptr)
		{
			ft_memcpy(new_ptr, ptr, o_size);
			free(ptr);
		}
		return (new_ptr);
	}
}
