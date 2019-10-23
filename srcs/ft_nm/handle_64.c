/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:08:13 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:08:15 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static bool		print_output_64(t_s_cmd *sym, t_nm **p_l, t_mh64 *h)
{
	size_t		i;

	i = 0;
	(*p_l)->s->strtable = (void *)(*p_l)->ptr + sym->stroff;
	if (!(check_memory_file((*p_l)->s->strtable, p_l)))
		return (false);
	(*p_l)->s->symoff = (void *)(*p_l)->ptr + sym->symoff;
	if (!(check_memory_file((*p_l)->s->symoff, p_l)))
		return (false);
	while (i < sym->nsyms)
	{
		if (!(put_print_handle_64(p_l, sym, h, i)))
			return (false);
		i++;
	}
	return (true);
}

static bool		lc_seg64(t_l_cmd *lc, t_nm **p_list)
{
	size_t		i;
	t_sc64		*seg;
	t_sec64		*sect;

	i = 0;
	seg = (t_sc64 *)lc;
	sect = (t_sec64	*)((void *)lc + sizeof(t_sc64));
	if (!(check_memory_file(sect, p_list)))
		return (false);
	while (i < seg->nsects)
	{
		putlcseg_64(p_list, sect);
		sect = (void *)sect + sizeof(t_sec64);
		if (!(check_memory_file(sect, p_list)))
			return (false);
		(*p_list)->s->segment->index += 1;
		i++;
	}
	return (true);
}

bool			handle_64(t_nm **p_list)
{
	t_l_cmd		*lc;
	t_mh64		*header;
	size_t		ncmds;
	size_t		i;

	i = -1;
	header = (t_mh64 *)(*p_list)->ptr;
	if (!(ncmds = header->ncmds))
		return (err_nm(*p_list, true));
	lc = (void *)(*p_list)->ptr + sizeof(*header);
	reset_section(p_list);
	while (++i < ncmds)
	{
		if (!(check_memory_file(lc, p_list)))
			return (false);
		if (lc->cmd == LC_SEGMENT_64)
			lc_seg64(lc, p_list);
		if (lc->cmd == LC_SYMTAB)
		{
			print_output_64((t_s_cmd *)lc, p_list, header);
			break ;
		}
		lc = (void *)lc + lc->cmdsize;
	}
	return (handle_no_cmds(i, ncmds, *p_list));
}
