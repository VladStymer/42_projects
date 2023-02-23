/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:15:32 by loichu            #+#    #+#             */
/*   Updated: 2023/01/13 12:34:24 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_handler_p.h>

int	open_write(char *path)
{
	if (DEBUG)
		printf("[file handler] open WRITE file: '%s'\n", path);
	return (_open(path, O_WRONLY | O_TRUNC | O_CREAT));
}

int	open_append(char *path)
{
	if (DEBUG)
		printf("[file handler] open APPEND file: '%s'\n", path);
	return (_open(path, O_WRONLY | O_APPEND | O_CREAT));
}
