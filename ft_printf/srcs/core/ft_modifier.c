/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:29:27 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:29:28 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

/*
** @brief
** @param core
** @param i
*/

static void		ft_jump_i_to_next(t_core *core, int *i)
{
	if ((core->modifier & 1) || (core->modifier & 2))
		*i += 2;
	else if ((core->modifier & 4) || (core->modifier & 8)
			|| (core->modifier & 16) || (core->modifier & 32))
		*i += 1;
}

/*
** @brief
** @param str
** @param core
** @param i
** @return true|false
** strncmp return 0 si str est a la fin
*/

static bool		ft_is_a_modifier(const char *str, t_core *core, const int *i)
{
	if (str[*i])
	{
		if (str[*i] == 'h' && str[*i + 1] == 'h')
			core->modifier += 1;
		else if (str[*i] == 'l' && str[*i + 1] == 'l')
			core->modifier += 2;
		else if (str[*i] == 'h')
			core->modifier += 4;
		else if (str[*i] == 'l')
			core->modifier += 8;
		else if (str[*i] == 'j')
			core->modifier += 16;
		else if (str[*i] == 'z')
			core->modifier += 32;
	}
	else
		return (false);
	return (true);
}

/*
** @brief
** @param str
** @param i
** @param core
*/

void			ft_modifier(const char *str, int *i, t_core *core)
{
	ft_is_a_modifier(str, core, i);
	ft_jump_i_to_next(core, i);
	ft_types(str, i, core);
}
