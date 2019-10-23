/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_uni2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:29:14 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:29:15 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void			ft_convert_big_c(t_core *core)
{
	t_f			unicode;
	int			a;

	a = -10000;
	ft_unicode(core, &unicode, core->var.value, &a);
}
