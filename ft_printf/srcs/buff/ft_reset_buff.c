/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:28:56 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:28:57 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void			ft_reset_buffer(t_core *core, size_t len, char c, char *str)
{
	size_t		a;

	if (core->count == -1)
		return ;
	if ((core->index + len) >= BUFFER_SIZE)
	{
		write(core->fd, core->buffer, core->index);
		core->buffer[0] = '\0';
		core->index = 0;
	}
	if (str == NULL)
	{
		ft_charcatindex(core, c);
		a = 1;
	}
	else
	{
		ft_strcatindex(core, str, len);
		if (core->precision < ft_strlen(str))
			a = len;
		else
			a = ft_strlen(str);
	}
	(core->count == -2 || core->count == -1) ? (0) : (core->count += a);
}

void			ft_put_d(t_core *core, char *str, int neg)
{
	int			padd;
	size_t		len;

	len = (str) ? ft_strlen(str) : 0;
	padd = 0;
	ft_prefix_d(core, neg, len);
	if ((neg || (core->var.value >= 0 && core->type & 8 && core->flags & 1)))
		padd = 1;
	if (core->flags & 2)
	{
		ft_reset_buffer(core, ft_strlen(core->prefix), 0, core->prefix);
		ft_put_in_buffer(core, str);
	}
	ft_put_zero_space(neg, padd, str, core);
	if (!(core->flags & 2))
		ft_put_in_buffer(core, str);
}

void			ft_put_x(t_core *core, char *str, int neg)
{
	int			padd;
	size_t		len;

	len = (str) ? ft_strlen(str) : 0;
	padd = 0;
	ft_prefix_x(core);
	if ((neg || (core->var.value >= 0 && core->type & 8 && core->flags & 1)))
		padd = 1;
	if (core->flags & 2)
	{
		ft_reset_buffer(core, ft_strlen(core->prefix), 0, core->prefix);
		ft_put_in_buffer(core, str);
	}
	ft_put_zero_space(neg, padd, str, core);
	if (!(core->flags & 2))
		ft_put_in_buffer(core, str);
}

void			ft_flag_padding_preci(t_core *core, char *str, int neg)
{
	int			padd;

	padd = 0;
	ft_prefix(core, neg);
	if ((neg || (core->var.value >= 0 && core->type & 8 && core->flags & 1)))
		padd = 1;
	if (core->flags & 2)
	{
		ft_reset_buffer(core, ft_strlen(core->prefix), 0, core->prefix);
		ft_put_in_buffer(core, str);
	}
	ft_put_zero_space(neg, padd, str, core);
	if (!(core->type & 1024) && (core->flags & 1 && core->flags & 32))
		ft_reset_buffer(core, 1, 0, "+");
	if (!(core->flags & 2))
		ft_put_in_buffer(core, str);
}
