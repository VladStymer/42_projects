/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_multiple_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:43:28 by vnicoud           #+#    #+#             */
/*   Updated: 2023/01/05 07:54:49 by vnicoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

char	*join3(char *str1, char *str2, char *str3)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strjoin(str1, str2);
	tmp2 = ft_strjoin(tmp1, str3);
	free(tmp1);
	return (tmp2);
}
