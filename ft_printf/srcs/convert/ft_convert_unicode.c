/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_unicode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:29:16 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:29:17 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

/*
** SI un unicode est invalide => on affiche rien
*/

int				ft_count(int value)
{
	int			i;

	i = 0;
	while (value != 0)
	{
		value = value >> 1;
		i++;
	}
	return (i);
}

/*
** 0111 1111 => 0x7F
** 0011 1111 => 0x3F
** 0001 1111 => 0x1F
** 0000 1111 => 0xF
** 0000 0111 => 0x7
**
** 1000 0000 => 0x80
** 1100 0000 => 0xC0
** 1110 0000 => 0xE0
** 1111 0000 => 0xF0
*/

bool			ft_invalid(int unicode)
{
	if (unicode < 0 || unicode > 0x10FFFF ||
		(unicode >= 0xD800 && unicode <= 0xDFFF))
		return (false);
	return (true);
}

void			ft_display(t_f *unicode, t_core *core)
{
	if (unicode->four.four != 0)
	{
		ft_reset_buffer(core, 1, unicode->four.four, NULL);
		ft_reset_buffer(core, 1, unicode->four.three, NULL);
		ft_reset_buffer(core, 1, unicode->four.two, NULL);
		ft_reset_buffer(core, 1, unicode->four.one, NULL);
	}
	else if (unicode->four.three != 0)
	{
		ft_reset_buffer(core, 1, unicode->four.three, NULL);
		ft_reset_buffer(core, 1, unicode->four.two, NULL);
		ft_reset_buffer(core, 1, unicode->four.one, NULL);
	}
	else if (unicode->four.two != 0)
	{
		ft_reset_buffer(core, 1, unicode->four.two, NULL);
		ft_reset_buffer(core, 1, unicode->four.one, NULL);
	}
	else if (unicode->four.one != 0)
		ft_reset_buffer(core, 1, unicode->four.one, NULL);
	else if (unicode->value == 0)
		ft_display_zero(core);
}

int				ft_unicode3(t_f *unicode, int value)
{
	int			nb_bit;
	int			n;

	n = 1;
	unicode->value = 0;
	nb_bit = ft_count(value);
	if (nb_bit < 8)
		unicode->four.one = 0x00 + (value & 0x7F);
	else if (nb_bit < 12)
	{
		unicode->four.one = 0x80 + (value & 0x3F);
		unicode->four.two = 0xC0 + ((value >> 6) & 0x1F);
		n = 2;
	}
	else if (nb_bit < 22)
		ft_unicode2(&n, nb_bit, unicode, value);
	return (n);
}
