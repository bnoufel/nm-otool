/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:06:27 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:06:32 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void		free_t_l(t_l *list)
{
	t_l			*tlist;

	if (!list)
		return ;
	while (list->next)
		list = list->next;
	while (list)
	{
		tlist = list;
		list = list->prev;
		free(tlist->data.name);
		free(tlist->data.value);
		free(tlist);
	}
}

void			ft_byebye(t_nm *p_list)
{
	t_nm		*head;
	t_nm		*tmp;
	t_l			*list;

	head = p_list->head;
	while (head)
	{
		tmp = head;
		head = head->next;
		list = tmp->list;
		free_t_l(list);
		free(tmp->s->segment);
		free(tmp->s);
		free(tmp);
	}
}
