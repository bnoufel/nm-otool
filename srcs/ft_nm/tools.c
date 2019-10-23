/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:08:49 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:08:51 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"
#include "global.h"

void			reset_section(t_nm **p_list)
{
	(*p_list)->s->segment->index = 1;
	(*p_list)->s->segment->text = 0;
	(*p_list)->s->segment->data = 0;
	(*p_list)->s->segment->bss = 0;
}

size_t			get_size_name(uint32_t stroff, t_nm **p_l)
{
	size_t		i;

	i = 0;
	while ((size_t)((*p_l)->ptr + i + stroff + (*p_l)->big_n_strx_val)
	< (size_t)(*p_l)->end_ptr && (*p_l)->s->name[i])
		i++;
	return (i);
}

void			malloc_failed(char *name)
{
	ft_dprintf(2, "%s: has failed.\n", name);
	exit(EXIT_FAILURE);
}

void			ft_munmap(void *ptr, size_t size)
{
	if (munmap(ptr, size) < 0)
		exit(EXIT_FAILURE);
}

bool			err_nm(t_nm *lst, bool malformed)
{
	if (malformed)
		ft_dprintf(2, "%s: malformed object\n", lst->name);
	else
	{
		ft_dprintf(2, "%s: Invalid file", lst->name);
		ft_dprintf(2, " or can not allocate memory.\n");
	}
	lst->type |= IS_ERROR;
	return (false);
}
