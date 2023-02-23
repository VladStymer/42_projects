/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:13:36 by loichu            #+#    #+#             */
/*   Updated: 2023/01/11 19:27:48 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_handler_p.h>

int	open_read(char *path)
{
	if (DEBUG)
		printf("open READ file %s", path);
	return (_open(path, O_RDONLY));
}

int	open_heredoc(char *eof)
{
	int		hfd[2];
	int		nbytes;
	char	buff[BUFFERSIZE + 1];

	if (DEBUG)
		printf("start HEREDOC with %s as delimiter\n", eof);
	if (pipe(hfd) == -1)
		return (-1);
	write(1, "> ", 2);
	nbytes = read(0, buff, BUFFERSIZE);
	while (nbytes > 0)
	{
		buff[nbytes] = 0;
		if (nbytes == (int)ft_strlen(eof) + 1
			&& (ft_strncmp(eof, buff, ft_strlen(eof)) == 0)
			&& buff[nbytes - 1] == '\n')
		{
			break ;
		}
		write(hfd[1], buff, nbytes);
		write(1, "> ", 2);
		nbytes = read(0, buff, BUFFERSIZE);
	}
	close(hfd[1]);
	return (hfd[0]);
}
