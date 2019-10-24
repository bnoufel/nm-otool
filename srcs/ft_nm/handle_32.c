/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:08:08 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:08:10 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static bool		print_output_32(t_s_cmd *sym, t_nm **p_l, t_mh *h)
{
	size_t		i;

	i = 0;
	(*p_l)->s->list = NULL;
	(*p_l)->s->strtable = (void *)(*p_l)->ptr + sym->stroff;
	if (!(check_memory_file((*p_l)->s->strtable, p_l)))
		return (false);
	(*p_l)->s->symoff32 = (void *)(*p_l)->ptr + sym->symoff;
	if (!(check_memory_file((*p_l)->s->symoff32, p_l)))
		return (false);
	while (i < sym->nsyms)
	{
		if (!(put_print_handle_32(p_l, sym, h, i)))
			return (false);
		i++;
	}
	return (true);
}

static bool		lc_seg32(t_l_cmd *lc, t_nm **p_list)
{
	size_t		i;
	t_sc		*seg;
	t_sec		*sect;

	i = 0;
	seg = (t_sc *)lc;
	sect = (t_sec *)((void *)lc + sizeof(t_sc));
	if (!(check_memory_file(sect, p_list)))
		return (false);
	while (i < seg->nsects)
	{
		putlcseg_32(p_list, sect);
		sect = (void *)sect + sizeof(t_sec);
		if (!(check_memory_file(sect, p_list)))
			return (false);
		(*p_list)->s->segment->index += 1;
		i++;
	}
	return (true);
}

bool			handle_32(t_nm **p_list)
{
	t_l_cmd		*lc;
	t_mh		*header;
	uint32_t	ncmds;
	uint32_t	i;

	i = 0;
	header = (t_mh *)(*p_list)->ptr;
	if (!(ncmds = header->ncmds))
		return (err_nm(*p_list, true, NULL));
	lc = (void *)(*p_list)->ptr + sizeof(*header);
	reset_section(p_list);
	while (++i <= ncmds)
	{
		if (!(check_memory_file(lc, p_list)))
			return (false);
		if (lc->cmd == LC_SEGMENT)
			lc_seg32(lc, p_list);
		if (lc->cmd == LC_SYMTAB)
		{
			print_output_32((t_s_cmd *)lc, p_list, header);
			break ;
		}
		lc = (void *)lc + lc->cmdsize;
	}
	return (handle_no_cmds(i, ncmds, *p_list));
}
