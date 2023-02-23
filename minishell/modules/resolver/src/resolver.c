/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:28:45 by vnicoud           #+#    #+#             */
/*   Updated: 2023/01/05 19:03:41 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "resolver.h"

char	**mk_tab(char *path, char *cmd, int cmdl)
{
	char	**ret;
	char	*path_i;
	int		i;
	int		j;

	path_i = path;
	ret = protected_malloc((path_len(path) + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	j = 0;
	while (*path_i)
	{
		while (*path_i == ':')
			path_i++;
		i = 0;
		while (path_i[i] && path_i[i] != ':')
			i++;
		ret[j] = add_cmd(path_i, cmd, i, cmdl);
		if (!ret[j++])
			return (NULL);
		path_i += i;
	}
	ret[j] = NULL;
	return (ret);
}

char	*get_absolute_path(char *cmd, char *path)
{
	char	**tab;
	char	*ret;
	int		i;

	if (!path || !*path)
		return (NULL);
	tab = mk_tab(path, cmd, ft_strlen(cmd));
	if (!tab)
		return (ft_strdup(cmd));
	i = 0;
	while (tab[i] && access(tab[i], X_OK) == -1)
		i++;
	if (!tab[i])
	{
		free_nd(tab, NULL);
		return (NULL);
	}
	ret = ft_strdup(tab[i]);
	free_nd(tab, NULL);
	return (ret);
}

char	*resolve(char *exec)
{
	char	*ret;

	if (!exec)
		return (NULL);
	ret = get_absolute_path(exec, get_envvar_value("PATH"));
	return (ret);
}
