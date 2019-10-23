/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:29:35 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:29:37 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

/*
** @brief
** @param nb
** @return [int] rank
*/

size_t			ft_return_rank(int nb)
{
	size_t		rank;

	rank = 0;
	while (nb > 0)
	{
		nb /= 10;
		rank++;
	}
	return (rank);
}

/*
** @brief
** @param str
** @param i
** @param core
** Ouaip ya trop moyen de l'optimiser mais je l'ai fait en one shot xD
*/

void			init_struct(t_tmp *s_tmp, const char *str, int *i, int tmp)
{
	s_tmp->str = str;
	s_tmp->i = i;
	s_tmp->tmp = tmp;
}

void			ft_precision2(size_t jump, t_core *core, t_tmp s_tmp, int *i)
{
	if (jump == 0 && s_tmp.str[*i] == '.')
		core->padding = 0;
	else if (jump > 0 && s_tmp.str[*i])
		core->padding = s_tmp.tmp;
	if ((jump > 0 && s_tmp.str[*i] && s_tmp.str[*i] == '.')
		|| (jump == 0 && s_tmp.str[*i + 1] && s_tmp.str[*i] == '.'))
	{
		s_tmp.tmp = ft_atoi(s_tmp.str + *i + 1);
		core->precision = s_tmp.tmp;
		core->flags += 32;
		jump = ft_return_rank(s_tmp.tmp);
		*i += 1 + jump;
		if (s_tmp.str[*i] == '0')
			(*i)++;
		ft_modifier(s_tmp.str, i, core);
	}
	else if (jump > 0 && s_tmp.str[*i] && s_tmp.str[*i] != '.')
		ft_modifier(s_tmp.str, i, core);
	else if (jump == 0 && s_tmp.str[*i] != '.')
		ft_modifier(s_tmp.str, i, core);
}

void			ft_precision(const char *str, int *i, t_core *core)
{
	int			tmp;
	size_t		jump;
	t_tmp		s_tmp;

	tmp = ft_atoi(str + *i);
	init_struct(&s_tmp, str, i, tmp);
	jump = ft_return_rank(tmp);
	*i += jump;
	if (str[*i + 1] && str[*i] == '*')
	{
		core->star_preci += 1;
		*i += 1;
	}
	if (str[*i + 1] && str[*i] == '.' && str[*i + 1] == '*')
	{
		if (!(core->flags & 32))
			core->flags += 32;
		core->star_padd += 2;
		*i += 2;
	}
	if ((core->star_preci & 1) || (core->star_padd & 2))
		ft_modifier(str, i, core);
	else
		ft_precision2(jump, core, s_tmp, i);
}
