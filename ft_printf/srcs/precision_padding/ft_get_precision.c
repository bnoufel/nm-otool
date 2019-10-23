/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:29:43 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:29:45 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static size_t	ft_get_precision_s(t_core *core, size_t size)
{
	if (!(core->flags & 32) && core->padding == 0 && core->precision == 0)
		return (size);
	else if (core->precision > 0 && size < core->precision)
		return (size);
	else if (!(core->flags & 32) && core->precision == 0)
		return (core->padding - (core->padding - size));
	else
		return (core->precision);
}

int				ft_return_precision(t_core *core, size_t len)
{
	if ((int)(core->padding - core->precision - len) < 0)
		return (len);
	else
		return (int)(core->padding - core->precision - len);
}

int				ft_get_precision(t_core *core, char *str)
{
	size_t		s;
	size_t		len;

	s = (str) ? ft_strlen(str) : 0;
	len = (core->prefix[0] != '\0') ? ft_strlen(core->prefix) : 0;
	if (core->flags & 16)
	{
		if (core->type & 16)
			len = 1;
		else if (core->type & 64 || core->type & 128)
			len = 2;
	}
	if (core->type & 1)
		return (int)ft_get_precision_s(core, s);
	else if (s > core->precision)
	{
		if (core->precision == 0 && core->flags & 32)
			return ((int)(core->padding - s) < 0 ? (0) : core->padding - s);
		return (int)(core->padding - s - len);
	}
	else
		return (ft_return_precision(core, len));
}
