/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:06:17 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:06:21 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void		parse_arg4(char c, uint32_t *arg, int *ret)
{
	if (c == 'r')
	{
		if (*arg & FLAG_r)
			no_more_defined('r', ret);
		else
			*arg |= FLAG_r;
	}
	else if (c == 'A' || c == 'o')
	{
		if (*arg & FLAG_A)
			no_more_defined(c == 'o' ? 'o' : 'A', ret);
		else
			*arg |= FLAG_A;
	}
	else if (c == 'p')
	{
		if (*arg & FLAG_p)
			no_more_defined('p', ret);
		else
			*arg |= FLAG_p;
	}
	else
		help(c);
}

static void		parse_arg3(char c, uint32_t *arg, int *ret)
{
	if (c == 'U')
	{
		if (*arg & FLAG_U)
			no_more_defined('U', ret);
		else
			*arg |= FLAG_U;
		if (*arg & FLAG_u)
			*arg |= C_FLAG;
	}
	else if (c == 'j')
	{
		if (*arg & FLAG_j)
			no_more_defined('j', ret);
		else
			*arg |= FLAG_j;
	}
	else
		parse_arg4(c, arg, ret);
}

static void		parse_arg2(char c, uint32_t *arg, int *ret)
{
	if (c == 'g')
	{
		if (*arg & FLAG_g)
			no_more_defined('g', ret);
		else
			*arg |= FLAG_g;
	}
	else if (c == 'u')
	{
		if (*arg & FLAG_u)
			no_more_defined('u', ret);
		else
			*arg |= FLAG_u;
		if (*arg & FLAG_U)
			*arg |= C_FLAG;
	}
	else
		parse_arg3(c, arg, ret);
}

static void		parse_multi_arg(char **argv, uint32_t *arg, int *ret, int i)
{
	int			j;
	int			size_arg;

	j = 1;
	size_arg = ft_strlen(argv[i]);
	while (j < size_arg)
	{
		parse_arg2(argv[i][j], arg, ret);
		j++;
	}
}

int				parse_arg(uint32_t *arg, int argc, char **s)
{
	int			i;
	int			ret;

	ret = 0;
	i = 0;
	while (!ret && ++i < argc)
		if (s[1] && s[1][0] != '-')
		{
			*arg |= NO_FLAG;
			break ;
		}
		else if (s[i] && s[i][0] == '-' && s[i][1] == '-' && !s[i][2])
			return (++i);
		else if (s[i][0] == '-' && ft_strlen(s[i]) > 2)
			parse_multi_arg(s, arg, &ret, i);
		else if (s[i] && s[i][0] == '-' && !s[i][1])
			help(s[i][0]);
		else if (s[i] && s[i][0] == '-' && s[i][1])
			if (ft_strlen(s[i]) > 2 || s[i][1] == 'h')
				help(s[i][1] == 'h' ? '\0' : s[i][1]);
			else
				parse_arg2(s[i][1], arg, &ret);
		else
			break ;
	return (ret_parse_arg(arg, ret, i));
}
