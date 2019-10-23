/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:09:46 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:09:49 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"
#include "global.h"

static void		otool_hex_neg(int64_t *res, uint32_t n, int64_t nbr,
								uint32_t size)
{
	static uint32_t		ret = 0;

	if (n == size - 1 && nbr < 0)
	{
		if (*res < 15)
			*res += 1;
		else
		{
			ret = 1;
			*res = 0;
		}
	}
	else if (ret > 0)
	{
		ret = 0;
		if (*res < 15)
			*res += 1;
		else
		{
			ret = 1;
			*res = 0;
		}
	}
}

int				otool_hex(long int nbr, char *bytes, unsigned int size)
{
	int64_t				res;
	uint32_t			n;

	if (!size || !bytes)
		return (0);
	n = 0;
	while (n < size)
		bytes[n++] = (nbr >= 0) ? '0' : 'f';
	n = size - 1;
	while (nbr)
	{
		res = (nbr > 0) ? nbr % 16 : 15 + (nbr % 16);
		otool_hex_neg(&res, n, nbr, size);
		bytes[n] = (res < 10) ? res + '0' : res - 10 + 'a';
		nbr = nbr / 16;
		if (n == 0)
			break ;
		n = n - 1;
	}
	return (size);
}

void			malloc_failed(char *name)
{
	ft_dprintf(2, "%s: has failed.\n", name);
	exit(EXIT_FAILURE);
}

int				check_memory_file_otool(void *ptr, t_otool core)
{
	if (ptr > core.end_ptr)
	{
		core.type |= IS_ERROR;
		ft_dprintf(2, "%s: malformed object\n", core.name);
		return (0);
	}
	return (1);
}

void			ft_munmap(void *ptr, size_t size)
{
	if (munmap(ptr, size) < 0)
		exit(EXIT_FAILURE);
}
