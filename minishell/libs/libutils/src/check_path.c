/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:45:13 by vnicoud           #+#    #+#             */
/*   Updated: 2023/01/13 17:13:33 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	isit_path(const char *path)
{
	if (!ft_strncmp(path, ".", 2)
		|| !ft_strncmp(path, "./", 2)
		|| !ft_strncmp(path, "/", 1))
		return (true);
	return (false);
}
