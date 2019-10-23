/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcatindex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:29:39 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:29:40 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void			ft_strcatindex(t_core *core, const char *str, size_t len)
{
	size_t		i;

	if (!str)
		return ;
	i = 0;
	while (i < len)
	{
		core->buffer[core->index] = str[i];
		i++;
		core->index++;
	}
	core->buffer[core->index] = '\0';
}

void			ft_charcatindex(t_core *core, const char str)
{
	if (!str)
		return ;
	core->buffer[core->index] = str;
	core->index++;
	core->buffer[core->index] = '\0';
}
