/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools32.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:08:54 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:08:55 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static char		*hexdump_32(size_t ptr)
{
	int			len;
	char		*str;

	if (!(str = ft_strnew(9)))
		malloc_failed("hexdump_32");
	len = 8;
	str[len + 1] = '\0';
	while (len--)
	{
		str[len] = ptr % 16 + ((ptr % 16 > 9) ? ('a' - 10) : ('0'));
		ptr = ptr / 16;
	}
	return (str);
}

char			*get_value_if_null_32(void)
{
	char		*value;
	int			i;

	i = 0;
	if (!(value = ft_memalloc(9)))
		malloc_failed("get_value_if_null_32");
	while (i < 8)
	{
		value[i] = ' ';
		i++;
	}
	value[i] = '\0';
	return (value);
}

char			*get_value_32(t_h *s, int j, t_mh *header)
{
	char		*tmp;
	char		*value;
	int			len;
	int			i;

	i = -1;
	tmp = hexdump_32((u_int32_t)s->symoff32[j].n_value);
	len = ft_strlen(tmp);
	if (header->filetype == MH_OBJECT)
	{
		if (!(value = ft_memalloc(9)))
			malloc_failed("get_value_32");
		while (++i < (8 - len))
			value[i] = '0';
		value[i] = '\0';
	}
	else
	{
		if (!(value = ft_strnew(0)))
			malloc_failed("get_value_32");
	}
	if (!(value = ft_strjoinfree(value, tmp, 3)))
		malloc_failed("get_value_32");
	return (value);
}
