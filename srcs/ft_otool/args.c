/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:09:25 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:09:26 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static void		help(char *arg)
{
	if (arg)
		ft_printf("%s: not allowed\n", arg);
	ft_printf("USAGE: ./ft_otool [OPTIONS] <files>\n\nOPTIONS:\n\n");
	ft_printf("-t : print the text section\n");
	exit(EXIT_FAILURE);
}

static void		parse_arg2(char **argv, uint8_t *arg, int i)
{
	if (!argv[i][1])
		*arg |= NO_FLAG;
	else if (argv[i][1] == 't')
		*arg |= FLAG_t;
	else
		help(argv[i]);
}

int				parse_arg(uint8_t *arg, int argc, char **s)
{
	int			i;

	i = 0;
	while (++i < argc)
	{
		if (s[1] && s[1][0] != '-')
		{
			*arg |= NO_FLAG;
			break ;
		}
		else if (s[i] && s[i][0] == '-' && s[i][1] == '-' && !s[i][2])
			return (++i);
		else if (s[i] && s[i][0] == '-' && !s[i][1])
			help(s[i][1] == 'h' ? NULL : s[i]);
		else if (s[i] && s[i][0] == '-' && s[i][1])
			if (ft_strlen(s[i]) > 2 || s[i][1] == 'h')
				help(s[i][1] == 'h' ? NULL : s[i]);
			else
				parse_arg2(s, arg, i);
		else
			break ;
	}
	return (i);
}

int				parse_file(int i, int argc, char **argv, uint8_t arg)
{
	if (!argv[i] || arg & NO_FLAG)
		help(NULL);
	while (i < argc)
	{
		core(argv[i], arg);
		i++;
	}
	return (1);
}
