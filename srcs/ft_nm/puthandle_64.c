/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthandle_64.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:08:43 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:08:45 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static char		getsymbol(t_h *s, int i)
{
	if (s->symoff[i].n_type == N_INDR)
		return ('I');
	else if (s->symoff[i].n_type == N_INDR + N_EXT)
		return ('I');
	else if ((s->symoff[i].n_type & N_STAB))
		return ('*');
	else if (s->symoff[i].n_sect == s->segment->text)
		return ('t');
	else if (s->symoff[i].n_sect == s->segment->data)
		return ('d');
	else if (s->symoff[i].n_sect == s->segment->bss)
		return ('b');
	else if (s->symoff[i].n_type & N_EXT)
		return ('S');
	else
		return ('s');
}

static void		build_line(t_h *s, int i, t_nm **p_list, t_mh64 *h)
{
	if ((s->symoff[i].n_type == (N_UNDF + N_EXT)
	|| s->symoff[i].n_type == N_UNDF) && s->symoff[i].n_value == 0)
		s->cont.symbol = 'U';
	else if (s->symoff[i].n_type == (N_UNDF + N_EXT))
		s->cont.symbol = 'C';
	else if (s->symoff[i].n_type == N_UNDF)
		s->cont.symbol = 'c';
	else if (s->symoff[i].n_type == N_ABS + N_EXT)
		s->cont.symbol = 'A';
	else if (s->symoff[i].n_type == N_ABS)
		s->cont.symbol = 'a';
	else
		s->cont.symbol = getsymbol(s, i);
	if (s->symoff[i].n_type & N_EXT)
		s->cont.symbol = ft_toupper(s->cont.symbol);
	if (!(s->cont.name = ft_strndup(s->name, s->size_name)))
		malloc_failed("print_line");
	s->cont.name = putnamesymbol(s->cont.name, s->cont.symbol);
	if (s->cont.symbol != 'U' && s->cont.symbol != 'I')
		s->cont.value = get_value_64(
			s->symoff[i].n_value, h);
	else
		s->cont.value = get_value_if_null_64();
	s->cont.print = true;
	build_list(&(*p_list)->list, s->cont);
}

void			putlcseg_64(t_nm **p_list, t_sec64 *sect)
{
	if (!ft_strcmp(sect->segname, SEG_TEXT))
	{
		if (!ft_strcmp(sect->sectname, SECT_TEXT))
			(*p_list)->s->segment->text = (*p_list)->s->segment->index;
	}
	else if (!ft_strcmp(sect->segname, SEG_DATA))
	{
		if (!ft_strcmp(sect->sectname, SECT_DATA))
			(*p_list)->s->segment->data = (*p_list)->s->segment->index;
		if (!ft_strcmp(sect->sectname, SECT_BSS))
			(*p_list)->s->segment->bss = (*p_list)->s->segment->index;
	}
}

bool			put_print_handle_64(t_nm **p_l, t_s_cmd *sym, t_mh64 *h, int i)
{
	(*p_l)->s->name = (*p_l)->s->strtable + (*p_l)->s->symoff[i].n_un.n_strx;
	(*p_l)->big_n_strx_val = (*p_l)->s->symoff[i].n_un.n_strx;
	if (!(check_memory_file((*p_l)->s->name, p_l)))
		return (false);
	(*p_l)->s->size_name = get_size_name(sym->stroff, p_l);
	if ((*p_l)->s->size_name > 0 && !((*p_l)->s->symoff[i].n_type & N_STAB))
		build_line((*p_l)->s, i, p_l, h);
	return (true);
}
