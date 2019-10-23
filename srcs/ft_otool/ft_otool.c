/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:09:37 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:09:38 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

int				otool(t_otool core)
{
	uint32_t	magic;

	magic = *(uint32_t *)core.ptr;
	if (magic == FAT_MAGIC_64 || magic == FAT_CIGAM_64
	|| magic == FAT_MAGIC || magic == FAT_CIGAM)
		handle_fat(core);
	else if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
		handle_64(core);
	else if (magic == MH_MAGIC || magic == MH_CIGAM)
		handle_32(core);
	else
		return (0);
	return (1);
}

int				main(int argc, char **argv)
{
	int			file;
	uint8_t		arg;

	file = parse_arg(&arg, argc, argv);
	if (!(parse_file(file, argc, argv, arg)))
		return (EXIT_FAILURE);
}
