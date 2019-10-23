/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_buffer2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:28:49 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:28:50 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

/*
** @brief
** On prend le plus grand entre la
** taille de la chaine et la precision
** en rapport si on met un 0 ou non
** 32 '.'
** 8 '0'
** 2 '-'
** @param core
** @param c
** @param str
** @param neg
*/

size_t			ft_get_size_putbuff_s2(t_core *core, size_t len, size_t size)
{
	if (!(core->flags & 2))
	{
		if (len <= core->padding)
			size = core->padding - core->precision;
	}
	else if (core->padding >= len && core->flags & 2 && core->precision > len)
		size = core->padding - len;
	else
		size = core->padding - core->precision;
	return (size);
}

int				ft_get_size_putbuff_s(t_core *core, int null)
{
	size_t		size;
	size_t		len;

	len = 6;
	size = 0;
	if (!null && core->var.ptr)
		len = ft_strlen(core->var.ptr);
	if (core->padding >= len && (((core->flags & 2) && !(core->flags & 32))
			|| (!(core->flags & 2) && !(core->flags & 32))))
		size = core->padding - len;
	else if (core->precision > len)
	{
		if (core->padding > core->precision)
			size = ((core->precision - len) +
					(core->padding - core->precision));
		else
			size = ((core->precision - core->padding) +
					(core->padding - len) - (core->precision - core->padding));
	}
	else
		size = ft_get_size_putbuff_s2(core, len, size);
	return ((int)size);
}

void			ft_put_null_in_buffer(t_core *core)
{
	size_t		len;
	int			size;
	int			i;

	len = core->precision;
	if ((!(core->flags & 32) && core->precision == 0) || core->precision > 6)
		len = 6;
	size = ft_get_size_putbuff_s(core, 1);
	i = 0;
	if (!(core->flags & 2))
		while (i < size)
		{
			ft_reset_buffer(core, 1, ' ', NULL);
			i++;
		}
	ft_reset_buffer(core, len, 0, "(null)");
	if ((core->flags & 2) ||
		(core->flags & 2 && core->precision > 0
		&& core->precision < core->padding))
		while (i < size)
		{
			ft_reset_buffer(core, 1, ' ', NULL);
			i++;
		}
}

void			ft_putbuff_s(t_core *core, char *str)
{
	int			i;
	int			size;

	size = ft_get_size_putbuff_s(core, 0);
	i = -1;
	if (!(core->flags & 2))
		while (++i < size)
			ft_reset_buffer(core, 1, ' ', NULL);
	i = -1;
	while (++i < ft_get_precision(core, core->var.ptr))
		ft_reset_buffer(core, 1, str[i], NULL);
	i = -1;
	if ((core->flags & 2) || \
	(core->precision > 0 && core->flags & 2 && core->precision < core->padding))
		while (++i < size)
			ft_reset_buffer(core, 1, ' ', NULL);
}
