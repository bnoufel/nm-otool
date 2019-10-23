/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:09:33 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:09:36 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static int		check_file(char *ptr, char *name)
{
	int			magic;

	magic = *(int *)ptr;
	if (magic != (int)FAT_MAGIC && magic != (int)FAT_MAGIC_64
	&& magic != (int)FAT_CIGAM && magic != (int)FAT_CIGAM_64
	&& magic != (int)MH_CIGAM_64 && magic != (int)MH_CIGAM
	&& magic != (int)MH_MAGIC_64 && magic != (int)MH_CIGAM_64
	&& magic != (int)MH_MAGIC && magic != (int)MH_CIGAM)
	{
		ft_dprintf(2, "ft_otool: %s The file was not", name);
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
		exit(EXIT_FAILURE);
	}
	if (fstat(fd, &st) < 0)
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (S_ISDIR(st.st_mode))
	{
		ft_dprintf(2, "%s: is a directory.\n", name);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

static void		init_core(t_otool *core, char *name, size_t size, uint8_t arg)
{
	core->name = name;
	core->size = size;
	core->arg = arg;
}

static int		start_core(void *ptr, char *name, size_t size, uint8_t arg)
{
	t_otool		core;
	void		*ptrfree;

	if (check_file(ptr, name))
	{
		init_core(&core, name, size, arg);
		core.ptr = ptr;
		core.end_ptr = (ptr + size);
		core.fatptr = ptr;
		if (!otool(core))
		{
			ptrfree = (core.type & IS_FAT) ? core.fatptr : core.ptr;
			ft_munmap(ptrfree, size);
			return (0);
		}
	}
	ptrfree = (core.type & IS_FAT) ? core.fatptr : core.ptr;
	ft_munmap(ptrfree, size);
	return (1);
}

int				core(char *name, uint8_t arg)
{
	int			fd;
	char		*ptr;
	t_stat		st;

	if (!(fd = init(name)))
		return (0);
	fstat(fd, &st);
	if ((ptr = mmap(NULL, (size_t)st.st_size, PROT, MAP, fd, 0)) == MAP_FAILED)
		mmap_err_alloc(name);
	if (!(start_core(ptr, name, st.st_size, arg)))
		return (0);
	return (1);
}
