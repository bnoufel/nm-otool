/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:29:42 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:29:43 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	ft_init_struct(t_core *core, int fd)
{
	core->padding = 0;
	core->precision = 0;
	core->fd = fd;
	core->flags = 0;
	core->modifier = 0;
	core->type = 0;
	core->count = 0;
	core->index = 0;
	core->buffer[0] = '\0';
	core->prefix[0] = '\0';
	core->var.uvalue = 0;
	core->var.value = 0;
	core->var.ptr = NULL;
	core->var.coma = 0;
	core->var.dot = 0;
	core->star_preci = 0;
	core->star_padd = 0;
}
