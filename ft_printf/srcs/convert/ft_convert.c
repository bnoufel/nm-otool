/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:28:58 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:28:59 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

/*
** short type
** s == 1
** S == 2
** p == 4
** d == 8
** o == 16
** u == 32
** x == 64
** X == 128
** c == 256
** C == 512
** (d i c) => int  (o u x X) unsigned int => bigfat
** p s => char * / void *
** C et S TODO
*/

void			ft_assign(t_core *core)
{
	if (core->type & 2 || (core->type & 1 && core->modifier & 8))
		ft_convert_big_s(core);
	else if (core->type & 1)
		ft_convert_s(core);
	else if (core->type & 4)
		ft_convert_p(core);
	else if (core->type & 8)
		ft_convert_d(core);
	else if (core->type & 16)
		ft_convert_o(core);
	else if (core->type & 32)
		ft_convert_u(core);
	else if (core->type & 64)
		ft_convert_x(core);
	else if (core->type & 128)
		ft_convert_big_x(core);
	else
		ft_assign2(core);
}

void			ft_convert_va_arg_int(t_core *core, va_list ap)
{
	if (core->star_preci & 1)
	{
		core->padding = va_arg(ap, int);
		if (!(core->flags & 2) && (int)core->padding < 0)
		{
			core->flags += 2;
			core->padding *= -1;
		}
	}
	if (core->star_padd & 2)
	{
		core->precision = va_arg(ap, int);
		if ((int)core->precision < 0)
			core->precision = (core->flags & 32) ? 0 : (core->precision *= -1);
	}
	if (core->modifier & 2)
		core->var.value = va_arg(ap, int64_t);
	else if ((core->modifier & 8) || (core->modifier & 16))
		core->var.value = va_arg(ap, intmax_t);
	else if (core->modifier & 32)
		core->var.uvalue = va_arg(ap, size_t);
	else
		core->var.value = va_arg(ap, int);
}

void			ft_convert_va_arg_uint(t_core *core, va_list ap)
{
	if (core->star_preci & 1)
	{
		core->padding = va_arg(ap, int);
		if (!(core->flags & 2) && (int)core->padding < 0)
		{
			core->flags += 2;
			core->padding *= -1;
		}
	}
	if (core->star_padd & 2)
	{
		core->precision = va_arg(ap, int);
		if ((int)core->precision < 0)
		{
			core->precision *= -1;
			core->precision = (core->flags & 32) ? 0 : core->precision;
		}
	}
	if (core->modifier & 2)
		core->var.uvalue = va_arg(ap, unsigned long long);
	else if ((core->modifier & 8) || (core->modifier & 16)
			|| (core->modifier & 32))
		core->var.uvalue = va_arg(ap, uintmax_t);
	else
		core->var.uvalue = va_arg(ap, unsigned int);
}

void			ft_convert2(t_core *core, va_list ap)
{
	if (core->star_preci & 1)
	{
		core->padding = va_arg(ap, size_t);
		if (!(core->flags & 2) && (int)core->padding < 0)
		{
			core->flags += 2;
			core->padding *= -1;
		}
	}
	if (core->star_padd & 2)
	{
		core->precision = va_arg(ap, size_t);
		if ((int)core->precision < 0)
		{
			core->precision *= -1;
			if (core->flags & 32)
				core->precision = 0;
		}
	}
	core->var.ptr = va_arg(ap, void *);
}

void			ft_convert(t_core *core, va_list ap)
{
	if (core->type & 2 || (core->type & 1 && core->modifier & 8)
		|| (core->type & 4) || (core->type & 1 && core->modifier & 8) ||
		core->type & 2048 || core->type & 4096 || core->type & 8192)
		ft_convert2(core, ap);
	else if (core->type & 1)
	{
		if (core->star_preci & 1)
			core->padding = va_arg(ap, size_t);
		if (core->star_padd & 2)
			core->precision = va_arg(ap, size_t);
		core->var.ptr = va_arg(ap, char *);
	}
	if (core->type & 8 || core->type & 256 || core->type & 512)
		ft_convert_va_arg_int(core, ap);
	else if (core->type & 16 || core->type & 32 || \
			core->type & 64 || core->type & 128)
		ft_convert_va_arg_uint(core, ap);
	ft_assign(core);
}
