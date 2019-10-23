/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:29:45 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:29:48 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

bool			ft_putzero(t_core *core)
{
	if (core->type & 1)
		return (false);
	if (core->flags & 32 && core->type & 1024)
		return (false);
	return (true);
}

bool			ft_check_if_zero_n_dot(t_core *core)
{
	if ((core->flags & 32 && core->precision == 0))
		return (true);
	return (false);
}

void			ft_display_zero(t_core *core)
{
	char		c;

	c = '\0';
	write(core->fd, core->buffer, core->index);
	core->buffer[0] = '\0';
	core->index = 0;
	write(1, &c, 1);
	(core->count != -1) ? (core->count += 1) : (0);
}
