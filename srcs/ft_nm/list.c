/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:08:29 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:08:31 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void		init_tmp_lst(t_tmp_lst *tmp, int size, t_core core, void *ptr)
{
	tmp->size = size;
	tmp->core = core;
	tmp->ptr = ptr;
}

void			build_list(t_l **list, t_cont cont)
{
	if (*list == NULL)
	{
		if (!(*list = (t_l *)ft_memalloc(sizeof(t_l))))
			malloc_failed("build_list");
		(*list)->head = *list;
		(*list)->data = cont;
		(*list)->next = NULL;
		(*list)->prev = NULL;
	}
	else
	{
		if (!((*list)->next = (t_l *)ft_memalloc(sizeof(t_l))))
			malloc_failed("build_list");
		(*list)->next->head = (*list)->head;
		(*list)->next->data = cont;
		(*list)->next->next = NULL;
		(*list)->next->prev = (*list);
		*list = (*list)->next;
	}
}

static void		init_not_exist(t_nm **p_list, t_tmp_lst tmp)
{
	if (!(*p_list = (t_nm *)ft_memalloc(sizeof(t_nm))))
		malloc_failed("init_not_exist");
	(*p_list)->name = tmp.core.name;
	(*p_list)->big_n_strx_val = 0;
	(*p_list)->index = tmp.core.index;
	(*p_list)->size = tmp.size;
	(*p_list)->arg = tmp.core.arg;
	(*p_list)->ptr = tmp.ptr;
	(*p_list)->end_ptr = tmp.ptr + tmp.size;
	(*p_list)->head = *p_list;
	(*p_list)->next = NULL;
	if (!((*p_list)->s = (t_h *)ft_memalloc(sizeof(t_h))))
		malloc_failed("init_list_nm");
	if (!((*p_list)->s->segment = (t_segment *)malloc(sizeof(t_segment))))
		malloc_failed("init_not_exist: (*p_list)->s->segment ");
	(*p_list)->s->segment->index = 1;
	(*p_list)->s->segment->text = 0;
	(*p_list)->s->segment->data = 0;
	(*p_list)->s->segment->bss = 0;
}

static void		init_exist(t_nm **p_list, t_tmp_lst tmp)
{
	if (!((*p_list)->next = ft_memalloc(sizeof(t_nm))))
		malloc_failed("init_exist");
	if (!((*p_list)->next->s = (t_h *)ft_memalloc(sizeof(t_h))))
		malloc_failed("init_list_nm");
	if (!((*p_list)->next->s->segment = (t_segment *)malloc(sizeof(t_segment))))
		malloc_failed("init_not_exist: (*p_list)->s->segment ");
	(*p_list)->next->name = tmp.core.name;
	(*p_list)->next->big_n_strx_val = 0;
	(*p_list)->next->index = tmp.core.index;
	(*p_list)->next->size = tmp.size;
	(*p_list)->next->arg = tmp.core.arg;
	(*p_list)->next->ptr = tmp.ptr;
	(*p_list)->next->end_ptr = tmp.ptr + tmp.size;
	(*p_list)->next->head = (*p_list)->head;
	(*p_list)->next->next = NULL;
	(*p_list) = (*p_list)->next;
}

void			init_list_nm(t_nm **p_list, int size, t_core core, void *ptr)
{
	t_tmp_lst	tmp_lst;

	init_tmp_lst(&tmp_lst, size, core, ptr);
	if (!*p_list)
		init_not_exist(p_list, tmp_lst);
	else
		init_exist(p_list, tmp_lst);
}
