/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:06:23 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:06:25 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	help(char c)
{
	ft_printf("USAGE: ./ft_nm [OPTIONS] <files>\n\nOPTIONS:\n\n");
	if (c)
		ft_printf("-%c: not allowed\n", c != '-' ? c : '\0');
	ft_printf("-A, -o : Write the pathname or");
	ft_printf(" library name of an object on each line.\n");
	ft_printf("-p : Don't sort; display in symbol-table order.\n");
	ft_printf("-u : Display only undefined symbols.\n");
	ft_printf("-U : Don't display undefined symbols.\n");
	ft_printf("-j : Just display the symbol names (no value or type).\n");
	ft_printf("-g : Display only global (external) symbols.\n");
	ft_printf("-r : Sort in reverse order.\n");
	ft_printf("-- : Ignore argument.\n");
	exit(EXIT_FAILURE);
}

void	no_more_defined(char c, int *ret)
{
	ft_printf("ft_nm: for the -%c", c);
	ft_printf(" option: may only occur zero or one times!\n");
	*ret = 1;
}

int		ret_parse_arg(uint32_t *arg, int32_t ret, int32_t i)
{
	if (ret || *arg & C_FLAG)
		exit(EXIT_FAILURE);
	return (i);
}
