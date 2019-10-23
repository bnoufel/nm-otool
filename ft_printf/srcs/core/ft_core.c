/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:29:20 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:29:24 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void			ft_core(t_core *core, const char *str, int fd, va_list ap)
{
	int			i;

	i = 0;
	while (str[i] && core->count != -2)
	{
		core->padding = 0;
		core->precision = 0;
		core->fd = fd;
		core->flags = 0;
		core->modifier = 0;
		core->type = 0;
		core->star_preci = 0;
		core->star_padd = 0;
		core->prefix[0] = '\0';
		if (str[i] != '%')
			ft_reset_buffer(core, 1, str[i++], NULL);
		else
		{
			ft_flag(str, &i, core);
			ft_convert(core, ap);
		}
	}
	if (core->count != -2)
		write(core->fd, core->buffer, core->index);
}
