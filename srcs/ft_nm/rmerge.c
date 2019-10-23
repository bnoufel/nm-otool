/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmerge.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:08:46 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:08:47 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static t_l		*rmerge(t_l *left, t_l *right)
{
	t_l			*result;
	int			comp;

	result = NULL;
	if (!left)
		return (right);
	else if (!right)
		return (left);
	if ((comp = ft_strcmp(left->data.name, right->data.name)) > 0)
	{
		result = left;
		result->next = rmerge(left->next, right);
	}
	else if (comp < 0)
	{
		result = right;
		result->next = rmerge(left, right->next);
	}
	else
		rmerge2(&result, &left, &right);
	return (result);
}

void			rmerge2(t_l **result, t_l **left, t_l **right)
{
	int			comp;

	if ((comp = ft_strcmp((*left)->data.value, (*right)->data.value)) > 0)
	{
		(*result) = (*left);
		(*result)->next = rmerge((*left)->next, (*right));
	}
	else
	{
		(*result) = (*right);
		(*result)->next = rmerge((*left), (*right)->next);
	}
}

static void		rsplit(t_l *list, t_l **left, t_l **right)
{
	t_l			*slow;
	t_l			*fast;

	slow = list;
	fast = list->next;
	if (list == NULL || list->next == NULL)
	{
		*left = list;
		*right = NULL;
		return ;
	}
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*left = list;
	*right = slow->next;
	slow->next = NULL;
}

void			rmerge_sort(t_l **list)
{
	t_l			*left;
	t_l			*right;

	if (!*list || !(*list)->next)
		return ;
	rsplit(*list, &left, &right);
	rmerge_sort(&left);
	rmerge_sort(&right);
	*list = rmerge(left, right);
}
