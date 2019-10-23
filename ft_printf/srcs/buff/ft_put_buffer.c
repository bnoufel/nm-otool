/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:28:45 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:28:48 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

/*
** @brief
** Après preci = -1 & apres le while securiser avec fonction reset
** Cette fonction gere le flag # et la precision
** Sur le while ICI POUR LE %S QUI MET DES ZERO
** @param core
** @param str
** @param c
** @param neg
*/

void			ft_put_in_buffer2(t_core *core, char *str, size_t len)
{
	if (core->type & 1)
		ft_putbuff_s(core, str);
	else if (core->flags & 32 && core->precision == 0
	&& core->var.value == 0 && core->var.uvalue == 0)
		;
	else
		ft_reset_buffer(core, len, 0, str);
}

void			ft_put_in_buffer(t_core *core, char *str)
{
	size_t		precision;
	size_t		size;
	size_t		len;

	if ((core->type & 1 || core->type & 4) && core->var.ptr == NULL)
	{
		ft_put_null_in_buffer(core);
		return ;
	}
	if (ft_putzero(core))
	{
		len = (str) ? ft_strlen(str) : 0;
		size = (core->precision >= len) ? core->precision - len : 0;
		precision = 0;
		while (precision < size)
		{
			ft_reset_buffer(core, 1, '0', NULL);
			precision++;
		}
	}
	else
		len = (str) ? ft_strlen(str) : 0;
	ft_put_in_buffer2(core, str, len);
}

int				ft_get_diff_zero_space(t_core *core, char *str)
{
	int			diff;

	diff = 0;
	if (core->type & 4)
		diff = 2;
	else if ((core->modifier & 8) && core->type & 8 && (core->flags & 8))
		diff = 1;
	if (((core->flags & 16) && core->var.uvalue == 0 && core->flags & 32) ||
		(!(core->type & 1024) && (core->flags & 1 && core->flags & 32)))
		diff += -1;
	if (str && core->prefix[0] != '\0' &&
		ft_strlen(core->prefix) + ft_strlen(str) + 1 == core->padding)
		diff = 1;
	if (!(core->type & 1) && !(core->type & 32) && diff == 1)
		ft_reset_buffer(core, 1, ' ', NULL);
	return (diff);
}

bool			ret_is_true(bool *ret)
{
	*ret = true;
	return (true);
}

bool			ft_put_zero_space(int neg, int padd, char *str, t_core *core)
{
	int			diff;
	int			precision;
	bool		ret;

	ret = false;
	precision = ft_get_precision(core, str);
	diff = ft_get_diff_zero_space(core, str);
	if ((!(core->flags & 2) && ft_putzero(core) && padd >= precision - diff) ||
		(!(core->flags & 32) && (core->flags & 8)))
		ft_reset_buffer(core, ft_strlen(core->prefix), 0, core->prefix);
	if (!(core->type & 1024) && neg &&
		core->flags & 8 && (core->flags & 32 || core->padding > 0))
		ft_reset_buffer(core, 1, '0', NULL);
	while (ft_putzero(core) && padd < precision - diff)
	{
		if (!(core->flags & 32) && (core->flags & 8))
			ft_reset_buffer(core, 1, '0', NULL);
		else if (ret_is_true(&ret))
			ft_reset_buffer(core, 1, ' ', NULL);
		padd++;
	}
	if ((!(core->flags & 2) && !(core->type & 16)) && ret)
		ft_reset_buffer(core, ft_strlen(core->prefix), 0, core->prefix);
	return (ret);
}
