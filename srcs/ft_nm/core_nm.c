/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_nm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:06:33 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/16 06:34:00 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int		check_file(char *ptr, char *name)
{
	uint32_t	magic;

	magic = *(uint32_t *)ptr;
	if (magic != FAT_MAGIC && magic != FAT_MAGIC_64
	&& magic != FAT_CIGAM && magic != FAT_CIGAM_64
	&& magic != MH_CIGAM_64 && magic != MH_CIGAM
	&& magic != MH_MAGIC_64 && magic != MH_CIGAM_64
	&& magic != MH_MAGIC && magic != MH_CIGAM)
	{
		ft_dprintf(2, "ft_nm: %s The file was not", name);
		ft_dprintf(2, " recognized as a valid object file.\n");
		return (0);
	}
	return (1);
}

static int		init(char *name)
{
	int			fd;
	t_stat		st;

	if ((fd = open(name, O_RDONLY)) < 0)
	{
		if (errno == EACCES)
			ft_dprintf(2, "%s: Permission denied.\n", name);
		else
			ft_dprintf(2, "%s: Not found.\n", name);
		return (0);
	}
	if (fstat(fd, &st) < 0)
	{
		close(fd);
		return (0);
	}
	if (S_ISDIR(st.st_mode))
	{
		ft_dprintf(2, "%s: is a directory.\n", name);
		return (0);
	}
	return (fd);
}

static void		init_core(t_core *core, char *name, uint32_t arg, uint8_t i)
{
	core->name = name;
	core->index = i;
	core->arg = arg;
}

int				core(char *name, t_nm **p_list, uint32_t arg, uint8_t i)
{
	int			fd;
	char		*ptr;
	t_stat		st;
	t_core		core;

	if (!(fd = init(name)))
		return (0);
	fstat(fd, &st);
	if ((ptr = mmap(NULL, (size_t)st.st_size, PROT, MAP, fd, 0)) == MAP_FAILED)
		return (err_nm(*p_list, false, name));
	else
	{
		if (check_file(ptr, name))
		{
			init_core(&core, name, arg, i);
			init_list_nm(p_list, st.st_size, core, ptr);
			if (!(nm(p_list)))
			{
				ft_munmap(ptr, st.st_size);
				return (0);
			}
			ft_munmap(ptr, st.st_size);
		}
	}
	return (1);
}

bool			check_memory_file(void *ptr, t_nm **lst)
{
	if (ptr > (*lst)->end_ptr)
		return (err_nm(*lst, true, NULL));
	return (true);
}
