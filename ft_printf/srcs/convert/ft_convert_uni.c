/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_uni.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:29:12 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:29:13 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int				ft_count_special(int value)
{
	int			i;

	i = 0;
	while (value != 0)
	{
		value = value >> 1;
		i++;
	}
	if (i < 8)
		return (1);
	else if (i < 12)
		return (2);
	else if (i < 17)
		return (3);
	else if (i < 22)
		return (4);
	return (0);
}

int				ft_count_bytes(int *unicode)
{
	int i;

	i = 0;
	while (unicode[i] > 0)
		i++;
	return (i);
}

int				ft_count_spaces(t_core *core, int *unicode)
{
	int count[5];
	int sum;
	int i;

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	count[3] = 0;
	count[4] = 0;
	i = 0;
	sum = 0;
	while (i < 4 && unicode[i] != '\0')
	{
		count[i] += ft_count_special(unicode[i]);
		if (sum + count[i] <= (((core->flags & 32)) ?
		((int)core->precision) : 15000000))
			sum += count[i];
		i++;
	}
	if (MB_CUR_MAX == 1)
		return (core->padding - ft_count_bytes(unicode));
	return (core->padding - sum);
}

int				ft_convert_big_s2(t_core *core, int rd, int space)
{
	if (rd == -2)
	{
		core->count = -2;
		return (0);
	}
	if (core->flags & 2)
		while (++space < ft_count_spaces(core, ((int*)core->var.ptr)))
			ft_reset_buffer(core, 1, ' ', NULL);
	return (1);
}

void			ft_convert_big_s(t_core *core)
{
	int			i;
	t_f			unicode;
	int			rd;
	int			preci;
	int			space;

	if (core->var.ptr == NULL)
		return (ft_put_null_in_buffer(core));
	core->count_big_s = 0;
	preci = (core->precision == 0 &&
	(!(core->flags & 32))) ? 1000 : core->precision;
	i = 0;
	rd = 0;
	space = -1;
	if (!(core->flags & 2))
		while (++space < ft_count_spaces(core, ((int*)core->var.ptr)))
			ft_reset_buffer(core, 1, ' ', NULL);
	while (((int*)(core->var.ptr))[i] != '\0' && rd != -1 && rd != -2)
	{
		rd = ft_unicode(core, &unicode, ((int*)(core->var.ptr))[i], &preci);
		i++;
	}
	if (!ft_convert_big_s2(core, rd, space))
		return ;
}
