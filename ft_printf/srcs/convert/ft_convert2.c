/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:29:04 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:29:06 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void			ft_assign2(t_core *core)
{
	if (core->type & 512 || (core->type & 256 && core->modifier & 8))
		ft_convert_big_c(core);
	else if (core->type & 256)
		ft_convert_c(core);
	else if (core->type & 1024)
		ft_convert_perc(core);
	else if (core->type & 2048)
		ft_convert_b(core);
	else if (core->type & 4096)
		ft_convert_r(core);
	else if (core->type & 8192)
		ft_convert_big_r(core);
}
