/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:28:42 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:28:44 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void			ft_prefix_x(t_core *core)
{
	if (core->flags & 16 && core->var.uvalue != 0)
	{
		if (core->type & 128)
			ft_strcat(core->prefix, "0X");
		else if (core->type & 64)
			ft_strcat(core->prefix, "0x");
		else
			core->prefix[0] = '\0';
	}
	else
		core->prefix[0] = '\0';
}

void			ft_prefix_d(t_core *core, int neg, size_t len)
{
	len = 0;
	if (core->var.value == 128)
		core->prefix[0] = '\0';
	else if (neg && (core->var.value != 32768 &&
				core->var.value != 128 && core->var.value != 2147483648 &&
				core->var.value != LONG_MIN))
		ft_strcat(core->prefix, "-");
	else if (!neg && !(core->type & 1024) && core->flags & 1 &&
		core->precision == 0 && core->padding == 0)
		ft_strcat(core->prefix, "+");
	else if (!neg && core->flags & 1 && core->padding == 0)
		ft_strcat(core->prefix, "+");
	else if (!(core->type & 1024) && (core->flags & 1 && core->flags & 32))
		ft_strcat(core->prefix, "+");
	else if ((core->type & 8 && core->flags & 4 && core->padding == 0) ||
		(!(core->flags & 32) && core->flags & 16 && core->padding > 0 &&
		core->var.uvalue == 0))
		ft_strcat(core->prefix, " ");
	else
		core->prefix[0] = '\0';
}

static void		ft_prefix2(t_core *core)
{
	if ((core->type & 8 && core->flags & 4 && core->padding == 0)
			|| (!(core->flags & 32) && core->flags & 16
			&& core->padding > 0 && core->var.uvalue == 0))
		ft_strcat(core->prefix, " ");
	else if (core->flags & 16 && core->var.uvalue != 0 && core->type & 128)
		ft_strcat(core->prefix, "0X");
	else if (core->type & 4 ||
		(core->flags & 16 && core->var.uvalue != 0 && core->type & 64))
		ft_strcat(core->prefix, "0x");
	else if (core->type & 16 && core->flags & 16 && core->var.uvalue > 0)
		ft_strcat(core->prefix, "0");
	else
		core->prefix[0] = '\0';
}

void			ft_prefix(t_core *core, int neg)
{
	if (neg && (core->flags & 2) && !(core->flags & 32)
		&& (core->var.value != SHRT_MIN || core->var.value != CHAR_MIN ||
			core->var.value != INT_MIN || core->var.value != LONG_MIN ||
			core->var.value != LLONG_MIN))
		ft_strcat(core->prefix, "*");
	else if (neg && (core->var.value != SHRT_MIN || core->var.value != CHAR_MIN
				|| core->var.value != INT_MIN || core->var.value != LONG_MIN ||
				core->var.value != LLONG_MIN))
		ft_strcat(core->prefix, "/");
	else if (neg && (core->flags & 8)
		&& !(core->flags & 32) &&
		(core->var.value != SHRT_MIN || core->var.value != CHAR_MIN ||
		core->var.value != INT_MIN || core->var.value != LONG_MIN ||
		core->var.value != LLONG_MIN))
		ft_strcat(core->prefix, "=");
	else if (!neg && core->flags & 1
		&& core->precision == 0 && core->padding == 0 &&
		!(core->type & 1024))
		ft_strcat(core->prefix, "+");
	else
		ft_prefix2(core);
}
