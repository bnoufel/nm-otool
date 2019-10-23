/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_unicode2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:29:18 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:29:19 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void			ft_unicode2(int *n, int nb_bit, t_f *unicode, int value)
{
	if (nb_bit < 17)
	{
		unicode->four.one = 0x80 + (value & 0x3F);
		unicode->four.two = 0x80 + ((value >> 6) & 0x3F);
		unicode->four.three = 0xE0 + ((value >> 12) & 0xF);
		*n = 3;
	}
	else if (nb_bit < 22)
	{
		unicode->four.one = 0x80 + (value & 0x3F);
		unicode->four.two = 0x80 + ((value >> 6) & 0x3F);
		unicode->four.three = 0x80 + ((value >> 12) & 0x3F);
		unicode->four.four = 0xF0 + ((value >> 18) & 0x7);
		*n = 4;
	}
}

/*
** @brief
** else => error
** @param core
** @param unicode
** @param value
*/

void			ft_padd_unicode(t_core *core, int n, t_f *unicode, int *ret)
{
	int			i;

	i = -1;
	if (core->flags & 2)
		ft_display(unicode, core);
	while (*ret < -5000 && ++i < (int)core->padding - n)
		ft_reset_buffer(core, 1, ' ', NULL);
	if (!(core->flags & 2))
		ft_display(unicode, core);
}

int				ft_uni_big_c(t_core *core)
{
	int			c;

	if (core->var.value >= 255)
	{
		core->count = -2;
		return (-1);
	}
	c = 0;
	while (!(core->flags & 2) && ++c < (int)core->padding)
		ft_reset_buffer(core, 1, ' ', NULL);
	ft_reset_buffer(core, 1, (char)core->var.value, NULL);
	while ((core->flags & 2) && ++c < (int)core->padding)
		ft_reset_buffer(core, 1, ' ', NULL);
	write(core->fd, core->buffer, core->index);
	core->buffer[0] = '\0';
	core->index = 0;
	return (1);
}

int				ft_uni_big_s(t_core *core, t_f *unicode, int value)
{
	(void)unicode;
	if ((core->flags & 32) && core->count_big_s >= (int)core->precision)
		return (1);
	if (value > 255)
	{
		core->count = -2;
		return (-1);
	}
	ft_reset_buffer(core, 1, (char)value, NULL);
	core->count_big_s += ft_count_special(value);
	return (1);
}

int				ft_unicode(t_core *core, t_f *unicode, int value, int *ret)
{
	int			n;

	if (MB_CUR_MAX == 1 && !(core->type & 2
	|| (core->type & 1 && core->modifier & 8)))
		return (ft_uni_big_c(core));
	if (!ft_invalid(value))
	{
		core->count = -2;
		return (-2);
	}
	n = ft_unicode3(unicode, value);
	if (MB_CUR_MAX == 1 && (core->type & 2 ||
	(core->type & 1 && core->modifier & 8)))
		return (ft_uni_big_s(core, unicode, value));
	*ret = (*ret != -1) ? (*ret -= n) : *ret;
	if (*ret < 0 && *ret > -5000)
		return (-1);
	ft_padd_unicode(core, n, unicode, ret);
	if (*ret < -5000)
	{
		write(1, core->buffer, core->index);
		core->buffer[0] = '\0';
		core->index = 0;
	}
	return (1);
}
