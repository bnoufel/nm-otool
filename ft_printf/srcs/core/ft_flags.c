/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:29:25 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:29:26 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

/*
** @brief
** @param c
** @param core
** @return true|false
*/

static bool		ft_is_flag(char c, t_core *core)
{
	if (!(core->flags & 1) && c == '+')
		core->flags += 1;
	else if (!(core->flags & 2) && c == '-')
		core->flags += 2;
	else if (!(core->flags & 4) && c == ' ')
		core->flags += 4;
	else if (!(core->flags & 8) && c == '0')
		core->flags += 8;
	else if (!(core->flags & 16) && c == '#')
		core->flags += 16;
	if (c == '+' || c == '-' || c == ' ' || c == '0' || c == '#')
		return (true);
	return (false);
}

/*
** @brief
** @param str
** @param i
** @param core
*/

void			ft_flag(const char *str, int *i, t_core *core)
{
	(*i)++;
	while (str[*i])
	{
		if (ft_is_flag(str[*i], core) == false)
		{
			ft_precision(str, i, core);
			return ;
		}
		(*i)++;
	}
}
