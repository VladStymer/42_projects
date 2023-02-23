/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:07:35 by loichu            #+#    #+#             */
/*   Updated: 2023/01/10 22:07:39 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HANDLER_H
# define FILE_HANDLER_H

# include <parser_defs.h>
# include "utils.h"
# include <signal.h>

# define BUFFERSIZE 32

int	open_file(t_file *file);
int	close_fd(int fd);

#endif
