/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:09:44 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:09:45 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static int		swap32(uint32_t x)
{
	uint32_t	i;
	uint32_t	j;
	uint32_t	k;
	uint32_t	l;

	i = (((x) & 0xff000000) >> 24);
	j = (((x) & 0xff0000) >> 8);
	k = (((x) & 0xff00) << 8);
	l = (((x) & 0xff) << 24);
	return (i | j | k | l);
}

void			handle_fat(t_otool core)
{
	t_fh		*hdr;
	t_fharch	*archs;
	uint32_t	offset;
	uint32_t	off;
	uint32_t	i;

	i = -1;
	off = 0;
	hdr = (void *)core.ptr;
	archs = (t_fharch *)(hdr + 1);
	offset = swap32(hdr->nfat_arch);
	while (++i < offset)
	{
		off = swap32(archs[i].offset);
		core.ptr = core.ptr + off;
		if (!(check_memory_file_otool(core.ptr, core)))
			return ;
		otool(core);
	}
}
