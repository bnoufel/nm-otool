/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:09:30 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:09:31 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

bool			check_binary_l_cmd(size_t nb, t_l_cmd *lc, t_otool core)
{
	size_t		i;

	i = 0;
	while (i < nb)
	{
		if (!(check_memory_file_otool(lc, core)))
			return (false);
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
	return (true);
}

bool			check_binary_l_seg64(size_t nb, t_sec64 *sect, t_otool core)
{
	size_t		i;

	i = 0;
	while (i < nb)
	{
		if (!(check_memory_file_otool(sect, core)))
			return (false);
		sect = (void *)sect + sizeof(t_sec64);
		i++;
	}
	return (true);
}

bool			check_binary_l_seg(size_t nb, t_sec *sect, t_otool core)
{
	size_t		i;

	i = 0;
	while (i < nb)
	{
		if (!(check_memory_file_otool(sect, core)))
			return (false);
		sect = (void *)sect + sizeof(t_sec);
		i++;
	}
	return (true);
}

void			mmap_err_alloc(char *name)
{
	ft_printf("%s: Invalid file or can not allocate memory.\n", name);
	exit(EXIT_FAILURE);
}
