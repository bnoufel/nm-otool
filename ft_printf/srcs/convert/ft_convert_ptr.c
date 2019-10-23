/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:29:09 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:29:10 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void			ft_convert_s(t_core *core)
{
	ft_flag_padding_preci(core, (char *)core->var.ptr, 0);
}

void			ft_convert_perc(t_core *core)
{
	int			i;

	i = -1;
	ft_flag_padding_preci(core, "%", 0);
	if ((core->flags & 2) && core->flags & 32
	&& core->padding > 0 && core->padding > 1)
		while (++i < (int)(core->padding - 1))
			ft_reset_buffer(core, 1, ' ', NULL);
}

void			ft_convert_p(t_core *core)
{
	char		*tmp;
	char		*ltmp;
	int			i;

	i = -1;
	if (core->var.ptr == NULL)
	{
		if (!(core->flags & 2) && core->padding > 0 && core->padding > 3)
			while (++i < (int)(core->padding - 3))
				ft_reset_buffer(core, 1, ' ', NULL);
		ft_reset_buffer(core, 3, 0, "0x0");
		return ;
	}
	tmp = ft_lltoa_base((int64_t)core->var.ptr, 16);
	ltmp = ft_strlowcase(tmp);
	if (!(core->flags & 2))
		while (++i < (int)(core->padding - ft_strlen(ltmp) - 2))
			ft_reset_buffer(core, 1, ' ', NULL);
	ft_reset_buffer(core, 2, 0, "0x");
	ft_reset_buffer(core, ft_strlen(ltmp), 0, ltmp);
	if (core->flags & 2)
		while (++i < (int)(core->padding - ft_strlen(ltmp) - 2))
			ft_reset_buffer(core, 1, ' ', NULL);
	free(tmp);
}

void			ft_convert_b(t_core *core)
{
	int			i;
	char		*str;

	i = -1;
	if (!(core->flags & 2))
		while (++i < (int)(core->padding - 1))
			ft_reset_buffer(core, 1, ' ', NULL);
	str = ft_itoa_base((int)core->var.ptr, 2);
	ft_reset_buffer(core, ft_strlen(str), 0, str);
	if (core->flags & 2)
		while (++i < (int)(core->padding - 1))
			ft_reset_buffer(core, 1, ' ', NULL);
	free(str);
}
