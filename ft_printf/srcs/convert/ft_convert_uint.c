/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:29:10 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:29:12 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void			ft_convert_o(t_core *core)
{
	char		*tmp;

	if (core->modifier & 1)
		tmp = ft_ulltoa_base((unsigned char)core->var.uvalue, 8);
	else if (core->modifier & 4)
		tmp = ft_ulltoa_base((unsigned short)core->var.uvalue, 8);
	else
		tmp = ft_ulltoa_base(core->var.uvalue, 8);
	ft_flag_padding_preci(core, tmp, 0);
	free(tmp);
}

void			ft_convert_u(t_core *core)
{
	char		*tmp;

	tmp = ft_ulltoa_base(core->var.uvalue, 10);
	ft_put_d(core, tmp, 0);
	free(tmp);
}

void			ft_convert_x(t_core *core)
{
	char		*tmp;
	char		*ltmp;

	tmp = ft_ulltoa_base(core->var.uvalue, 16);
	ltmp = ft_strlowcase(tmp);
	ft_put_x(core, ltmp, 0);
	free(tmp);
}

void			ft_convert_big_x(t_core *core)
{
	char		*tmp;

	tmp = ft_ulltoa_base(core->var.uvalue, 16);
	ft_put_x(core, tmp, 0);
	free(tmp);
}
