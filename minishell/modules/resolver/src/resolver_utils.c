/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:47:46 by vnicoud           #+#    #+#             */
/*   Updated: 2022/12/21 12:49:32 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resolver.h"

char	**free_nd(char **tab, char *path)
{
	int	i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
			free(tab[i]);
		free(tab);
	}
	if (path)
		free(path);
	return (NULL);
}

char	*add_cmd(char *path, char *cmd, int pathl, int cmdl)
{
	char	*ret;
	int		i;

	ret = protected_malloc((pathl + cmdl + 2) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < pathl)
		ret[i++] = *(path++);
	ret[i++] = '/';
	while (*cmd)
		ret[i++] = *(cmd++);
	ret[i] = 0;
	return (ret);
}

int	path_len(char *path)
{
	int	count;

	count = 0;
	while (*path)
	{
		if (*path && *path != ':' && (!*(path + 1)
				|| *(path + 1) == ':'))
			count++;
		path++;
	}
	return (count);
}
