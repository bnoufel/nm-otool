/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:08:20 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/17 10:21:36 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static uint32_t	swap_uint32(uint32_t n)
{
	n = ((n << 8) & 0xFF00FF00) | ((n >> 8) & 0xFF00FF);
	return ((n << 16) | (n >> 16));
}

static uint64_t	swap_uint64(uint64_t n)
{
	n = ((n << 8) & 0xFF00FF00FF00FF00ULL) \
		| ((n >> 8) & 0x00FF00FF00FF00FFULL);
	n = ((n << 16) & 0xFFFF0000FFFF0000ULL) \
		| ((n >> 16) & 0x0000FFFF0000FFFFULL);
	return ((n << 32) | (n >> 32));
}

static	int		fatarch(cpu_type_t type)
{
	if (type == CPU_TYPE_X86_64)
		return (1);
	else if (type == CPU_TYPE_I386)
		return (1);
	return (0);
}

bool			handle_fat(t_nm **p_list)
{
	uint32_t	i;
	uint32_t	nfat;
	t_fh		*header;
	t_fharch	*arch;

	header = (t_fh *)(*p_list)->ptr;
	if (!(nfat = swap_uint32(header->nfat_arch)))
		return (err_nm(*p_list, true));
	arch = (t_fharch *)(header + 1);
	if (!arch->offset || !(check_memory_file(arch, p_list)))
		return (false);
	i = -1;
	while (++i < nfat)
	{
		if (nfat > 1 && !i && fatarch(swap_uint32(arch[i + 1].cputype)))
			continue ;
		(*p_list)->ptr = (*p_list)->ptr + swap_uint32(arch[i].offset);
		if (!(check_memory_file((*p_list)->ptr, p_list)))
			return (false);
		nm(p_list);
		if (fatarch(swap_uint32(arch[i].cputype)))
			return (true);
	}
	return (true);
}

bool			handle_fat64(t_nm **p_list)
{
	uint32_t	i;
	uint32_t	nfat;
	t_fh		*header;
	t_fharch64	*arch;

	header = (t_fh *)(*p_list)->ptr;
	if (!(nfat = swap_uint64(header->nfat_arch)))
		return (err_nm(*p_list, true));
	arch = (t_fharch64 *)(header + 1);
	if (!arch->offset || !(check_memory_file(arch, p_list)))
		return (false);
	i = -1;
	while (++i < nfat)
	{
		if (nfat > 1 && !i && fatarch(swap_uint32(arch[i + 1].cputype)))
			continue ;
		(*p_list)->ptr = (*p_list)->ptr + swap_uint64(arch[i].offset);
		if (!(check_memory_file((*p_list)->ptr, p_list)))
			return (false);
		nm(p_list);
		if (fatarch(swap_uint32(arch[i].cputype)))
			return (true);
	}
	return (true);
}
