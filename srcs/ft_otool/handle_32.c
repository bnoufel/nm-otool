/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:09:40 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:09:41 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static void		hex(uint64_t addr, t_sec *sect, t_otool core)
{
	size_t		i;
	const char	*ptr = core.ptr + sect->offset;
	size_t		size;

	size = 0;
	i = 0;
	while (i < sect->size)
	{
		if (i == 0 || i % 16 == 0)
		{
			addr = i != 0 ? addr + 16 : addr;
			size = otool_hex(addr, core.buffer, 8);
			core.buffer[size++] = '\t';
		}
		otool_hex(ptr[i++], core.buffer + size, 2);
		core.buffer[size + 2] = ' ';
		size += 3;
		if (i == sect->size || i % 16 == 0)
		{
			core.buffer[size] = '\0';
			ft_printf("%s\n", core.buffer);
		}
	}
}

static void		lc_seg32(t_l_cmd *lc, t_otool core)
{
	size_t		i;
	t_sc		*seg;
	t_sec		*sect;

	i = 0;
	if (core.type & IS_ERROR)
		return ;
	seg = (t_sc *)lc;
	sect = (t_sec *)((void *)lc + sizeof(t_sc));
	if (!(check_binary_l_seg(seg->nsects, sect, core)))
		return ;
	while (i < seg->nsects)
	{
		if (!(core.type & IS_ERROR) && !ft_strcmp(sect->segname, SEG_TEXT))
		{
			if (!ft_strcmp(sect->sectname, SECT_TEXT))
			{
				ft_printf("%s:\nContents of", core.name);
				ft_printf(" (__TEXT,__text) section\n");
				hex(sect->addr, sect, core);
			}
		}
		sect = (void *)sect + sizeof(t_sec);
		i++;
	}
}

void			handle_32(t_otool core)
{
	t_l_cmd		*lc;
	t_mh		*header;
	size_t		ncmds;
	size_t		i;

	i = 0;
	header = (t_mh *)core.ptr;
	ncmds = header->ncmds;
	lc = (void *)core.ptr + sizeof(*header);
	if (!(check_binary_l_cmd(ncmds, lc, core)))
		return ;
	while (i < ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
			lc_seg32(lc, core);
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
}
