/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:08:59 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:09:09 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void		print_list2(t_nm *p_list, t_l *tmp)
{
	char	*value;
	char	symbol;
	char	*name;

	while (tmp)
	{
		value = tmp->data.value;
		symbol = tmp->data.symbol;
		name = tmp->data.name;
		if (tmp->data.print)
		{
			if (p_list->arg & FLAG_A)
				ft_printf("%s: ", p_list->name);
			if (p_list->arg & FLAG_u || p_list->arg & FLAG_j)
				ft_printf("%s\n", name);
			else
				ft_printf("%s %c %s\n", value, symbol, name);
		}
		tmp = tmp->next;
	}
}

char			*putnamesymbol(char *str, char symbol)
{
	char		*tmp;

	if (symbol != 'I')
		return (str);
	tmp = str;
	if (!(str = ft_strjoinfree(str, " (indirect for ", 0)))
		malloc_failed("print_line");
	if (!(str = ft_strjoinfree(str, tmp, 3)))
		malloc_failed("print_line");
	if (!(str = ft_strjoinfree(str, ")", 1)))
		malloc_failed("print_line");
	return (str);
}

static void		print_list(t_nm *p_list)
{
	t_l			*list;
	t_l			*tmp;

	if (!p_list->list)
		return ;
	list = p_list->list->head;
	while (list->prev)
		list = list->prev;
	if (!(p_list->arg & FLAG_p) && !(p_list->arg & FLAG_r))
		merge_sort(&list);
	else if (!(p_list->arg & FLAG_p) && (p_list->arg & FLAG_r))
		rmerge_sort(&list);
	tmp = list;
	while (list)
	{
		if (p_list->arg & FLAG_U && list->data.symbol == 'U')
			list->data.print = false;
		if (p_list->arg & FLAG_u && list->data.symbol != 'U')
			list->data.print = false;
		if (p_list->arg & FLAG_g && ft_islower(list->data.symbol))
			list->data.print = false;
		list = list->next;
	}
	print_list2(p_list, tmp);
}

static int		nb_bin(t_nm *p_list)
{
	int			i;

	i = 0;
	p_list = p_list->head;
	while (p_list)
	{
		i++;
		p_list = p_list->next;
	}
	return (i);
}

int				display_p_list(t_nm *p_list)
{
	if (!p_list)
		return (0);
	p_list = p_list->head;
	while (p_list)
	{
		if (!(p_list->is_fat) && !(p_list->type & IS_ERROR)
			&& nb_bin(p_list) > 1 && !(p_list->arg & FLAG_A))
			ft_printf("%c%s:\n", 10, p_list->name);
		if (!(p_list->type & IS_ERROR))
			print_list(p_list);
		p_list = p_list->next;
	}
	return (1);
}
