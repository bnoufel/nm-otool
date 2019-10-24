/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools64.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:08:56 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:08:58 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

bool			handle_no_cmds(uint32_t i, uint32_t ncmds, t_nm *p_l)
{
	if (i > ncmds)
		return (err_nm(p_l, true, NULL));
	return (true);
}

static char		*hexdump_64(size_t ptr, t_mh64 *header)
{
	int			len;
	char		*str;

	if (!(str = ft_strnew(7)))
		malloc_failed("hexdump_64");
	len = (header->filetype == MH_DYLIB) ? 6 : 5;
	str[len + 1] = '\0';
	while (len--)
	{
		str[len] = ptr % 16 + ((ptr % 16 > 9) ? ('a' - 10) : ('0'));
		ptr = ptr / 16;
	}
	return (str);
}

char			*get_value_if_null_64(void)
{
	char		*value;
	int			i;

	i = 0;
	if (!(value = ft_memalloc(17)))
		malloc_failed("get_value_if_null_64");
	while (i < 16)
	{
		value[i] = ' ';
		i++;
	}
	value[i] = '\0';
	return (value);
}

static char		*put_value_64(char *value, char *tmp, t_mh64 *h, uint64_t n_va)
{
	if (h->filetype == MH_BUNDLE || h->filetype == MH_DYLIB
		|| h->filetype == MH_OBJECT || n_va == 0)
	{
		if (!(value = ft_strjoinfree(value, "0000", 1)))
			malloc_failed("put_value_64");
	}
	else
	{
		if (!(value = ft_strjoinfree(value, "1000", 1)))
			malloc_failed("put_value_64");
	}
	if (!(value = ft_strjoinfree(value, tmp, 3)))
		malloc_failed("put_value_64");
	return (value);
}

char			*get_value_64(uint64_t n_value, t_mh64 *header)
{
	char		*tmp;
	char		*value;
	int			i;
	int			len;

	i = -1;
	tmp = hexdump_64((size_t)n_value, header);
	len = ft_strlen(tmp);
	if (!(value = ft_memalloc(20)))
		malloc_failed("put_value_64");
	if (ft_strcmp(tmp, "0") == 0)
		len += 3;
	while (++i < (12 - len))
		value[i] = '0';
	value[i] = '\0';
	value = put_value_64(value, tmp, header, n_value);
	return (value);
}
