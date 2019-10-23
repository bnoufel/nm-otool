/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:29:06 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:29:08 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void			ft_convert_d(t_core *core)
{
	char		*str;
	int			neg;

	neg = 0;
	if (core->var.value < 0 && core->var.value != LONG_MIN)
	{
		core->var.value *= -1;
		neg = 1;
	}
	if (core->modifier & 1)
		str = ft_lltoa((signed char)core->var.value);
	else if (core->modifier & 2)
		str = ft_lltoa(core->var.value);
	else if (neg && core->modifier & 4)
		str = ft_itoa((short)core->var.value);
	else if ((core->modifier & 8) || (core->modifier & 4))
		str = ft_ltoa(core->var.value);
	else if (core->modifier & 16)
		str = ft_ltoa(core->var.value);
	else if (core->modifier & 32)
		str = ft_ltoa((unsigned long)core->var.uvalue);
	else
		str = ft_lltoa(core->var.value);
	ft_put_d(core, str, neg);
	free(str);
}

void			ft_convert_c(t_core *core)
{
	int			i;

	i = -1;
	if (!(core->flags & 2))
		while (++i < (int)(core->padding - 1))
			ft_reset_buffer(core, 1, ' ', NULL);
	if ((unsigned char)core->var.value == '\0')
		ft_display_zero(core);
	else
		ft_reset_buffer(core, 1, (unsigned char)core->var.value, NULL);
	if (core->flags & 2)
		while (++i < (int)(core->padding - 1))
			ft_reset_buffer(core, 1, ' ', NULL);
}

void			ft_convert_r(t_core *core)
{
	int			i;
	char		*str;

	i = -1;
	if (!(core->flags & 2))
		while (++i < (int)(core->padding - 1))
			ft_reset_buffer(core, 1, ' ', NULL);
	str = ft_itoa_base((int)core->var.ptr, 16);
	ft_reset_buffer(core, 2, 0, "0x");
	ft_reset_buffer(core, ft_strlen(str), 0, ft_strlowcase(str));
	if (core->flags & 2)
		while (++i < (int)(core->padding - 1))
			ft_reset_buffer(core, 1, ' ', NULL);
	free(str);
}

void			ft_convert_big_r(t_core *core)
{
	int			i;
	char		*str;

	i = -1;
	if (!(core->flags & 2))
		while (++i < (int)(core->padding - 1))
			ft_reset_buffer(core, 1, ' ', NULL);
	str = ft_lltoa_base((int)core->var.ptr, 16);
	ft_reset_buffer(core, 2, 0, "0X");
	ft_reset_buffer(core, ft_strlen(str), 0, str);
	if (core->flags & 2)
		while (++i < (int)(core->padding - 1))
			ft_reset_buffer(core, 1, ' ', NULL);
	free(str);
}
