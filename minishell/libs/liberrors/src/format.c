/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:44:42 by loichu            #+#    #+#             */
/*   Updated: 2023/01/12 15:55:57 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liberrors_p.h>

char	*itoa_array(int i, char *digits)
{
	char	rev_tmp[10];
	int		rev_pos;
	int		pos;

	pos = 0;
	if (i < 0)
	{
		digits[pos++] = '-';
		i = i * -1;
	}
	rev_pos = 0;
	rev_tmp[rev_pos++] = '0' + i % 10;
	i = i / 10;
	while (i)
	{
		rev_tmp[rev_pos++] = '0' + i % 10;
		i = i / 10;
	}
	while (--rev_pos >= 0)
		digits[pos++] = rev_tmp[rev_pos];
	digits[pos] = 0;
	return (digits);
}

int	str_replace(char *ref, char *replace)
{
	int	i;

	i = -1;
	while (replace[++i])
		ref[i] = replace[i];
	return (i);
}

void	f(char *format, char *replace, char *ref, char flag)
{
	int		fmt_i;
	int		ref_i;
	bool	done;

	done = false;
	fmt_i = -1;
	ref_i = 0;
	while (format[++fmt_i])
	{
		if (!done && format[fmt_i] == '%' && format[fmt_i + 1] == flag)
		{
			ref_i += str_replace(ref + ref_i, replace);
			fmt_i++;
			done = true;
		}
		else
			ref[ref_i++] = format[fmt_i];
		if (ref_i > ERROR_MAX_LEN)
			return (format_too_long());
	}
	ref[ref_i] = '\0';
}

void	fi(char *format, int i, char *ref)
{
	char	replace[INT_MAX_DIGITS];

	itoa_array(i, replace);
	f(format, replace, ref, 'i');
}

void	fs(char *format, char *str, char *ref)
{
	f(format, str, ref, 's');
}
