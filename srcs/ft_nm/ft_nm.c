/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:08:03 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:08:05 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int		add_type(uint32_t magic, t_nm **p_list)
{
	if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
		(*p_list)->type |= IS_64;
	else if (magic == MH_MAGIC || magic == MH_CIGAM)
		(*p_list)->type |= IS_32;
	else if (magic == FAT_MAGIC_64 || magic == FAT_CIGAM_64)
	{
		(*p_list)->type |= IS_FAT64;
		(*p_list)->is_fat = true;
	}
	else if (magic == FAT_MAGIC || magic == FAT_CIGAM)
	{
		(*p_list)->type |= IS_FAT;
		(*p_list)->is_fat = true;
	}
	else
		return (0);
	return (1);
}

int				nm(t_nm **p_list)
{
	uint32_t	magic;

	magic = *(uint32_t *)(*p_list)->ptr;
	if (!(add_type(magic, p_list)))
		return (0);
	if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
		return (handle_64(p_list));
	else if ((*p_list)->type & IS_32)
		return (handle_32(p_list));
	else if ((*p_list)->type & IS_FAT64)
		return (handle_fat64(p_list));
	else if ((*p_list)->type & IS_FAT)
		return (handle_fat(p_list));
	else
		return (0);
	return (1);
}

static int		parse_file(int i, int argc, char **argv, uint32_t arg)
{
	t_nm		*p_list;

	p_list = NULL;
	if (!argv[i])
	{
		argv[i] = "a.out";
		argc++;
	}
	while (i < argc)
	{
		if (!(core(argv[i], &p_list, arg, (i + 1) == argc ? 0 : 1)))
		{
			i++;
			continue ;
		}
		i++;
	}
	if (!(display_p_list(p_list)))
		return (0);
	ft_byebye(p_list);
	return (1);
}

int				main(int argc, char **argv)
{
	int			file;
	uint32_t	arg;

	file = parse_arg(&arg, argc, argv);
	if (!(parse_file(file, argc, argv, arg)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
