/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:08:33 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:08:37 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static t_l		*merge(t_l *left, t_l *right)
{
	t_l			*result;
	int			comp;

	result = NULL;
	if (!left)
		return (right);
	else if (!right)
		return (left);
	if ((comp = ft_strcmp(left->data.name, right->data.name)) < 0)
	{
		result = left;
		result->next = merge(left->next, right);
	}
	else if (comp > 0)
	{
		result = right;
		result->next = merge(left, right->next);
	}
	else
		merge2(&result, &left, &right);
	return (result);
}

void			merge2(t_l **result, t_l **left, t_l **right)
{
	int			comp;

	if ((comp = ft_strcmp((*left)->data.value, (*right)->data.value)) < 0)
	{
		(*result) = (*left);
		(*result)->next = merge((*left)->next, (*right));
	}
	else
	{
		(*result) = (*right);
		(*result)->next = merge((*left), (*right)->next);
	}
}

static void		split(t_l *list, t_l **left, t_l **right)
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

void			merge_sort(t_l **list)
{
	t_l			*left;
	t_l			*right;

	if (!*list || !(*list)->next)
		return ;
	split(*list, &left, &right);
	merge_sort(&left);
	merge_sort(&right);
	*list = merge(left, right);
}
