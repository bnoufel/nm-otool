/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:29:40 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:29:41 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static bool		ft_check_types3(t_core *core, const char *str, const int *i)
{
	if (ft_strncmp(str + *i, "%", 1) == 0)
		core->type += 1024;
	else if (ft_strncmp(str + *i, "b", 1) == 0)
		core->type += 2048;
	else if (ft_strncmp(str + *i, "r", 1) == 0)
		core->type += 4096;
	else if (ft_strncmp(str + *i, "R", 1) == 0)
		core->type += 8192;
	else
		return (false);
	return (true);
}

static bool		ft_check_types2(const char *str, const int *i, t_core *core)
{
	if (ft_strncmp(str + *i, "u", 1) == 0)
		core->type += 32;
	else if (ft_strncmp(str + *i, "U", 1) == 0)
	{
		core->type += 32;
		core->modifier += 8;
	}
	else if (ft_strncmp(str + *i, "x", 1) == 0)
		core->type += 64;
	else if (ft_strncmp(str + *i, "X", 1) == 0)
		core->type += 128;
	else if (ft_strncmp(str + *i, "c", 1) == 0)
		core->type += 256;
	else if (ft_strncmp(str + *i, "C", 1) == 0)
		core->type += 512;
	else
		ft_check_types3(core, str, i);
	return (true);
}

static bool		ft_check_types(const char *str, const int *i, t_core *core)
{
	if (ft_strncmp(str + *i, "s", 1) == 0)
		core->type += 1;
	else if (ft_strncmp(str + *i, "S", 1) == 0)
		core->type += 2;
	else if (ft_strncmp(str + *i, "p", 1) == 0)
		core->type += 4;
	else if (ft_strncmp(str + *i, "d", 1) == 0)
		core->type += 8;
	else if (ft_strncmp(str + *i, "D", 1) == 0)
	{
		core->type += 8;
		core->modifier += 8;
	}
	else if (ft_strncmp(str + *i, "i", 1) == 0)
		core->type += 8;
	else if (ft_strncmp(str + *i, "o", 1) == 0)
		core->type += 16;
	else if (ft_strncmp(str + *i, "O", 1) == 0)
	{
		core->type += 16;
		core->modifier += 8;
	}
	else
		return (ft_check_types2(str, i, core));
	return (true);
}

/*
** @brief
** Un type existe, on doit appeler la
** fonction ou le tableau de fonction pour traiter
** @param core
** @param str
** @param i
*/

void			ft_types(const char *str, int *i, t_core *core)
{
	while (str[*i] == 32)
		(*i)++;
	if (ft_check_types(str, i, core))
		(*i)++;
}
