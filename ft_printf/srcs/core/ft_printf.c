/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:29:37 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:29:38 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int				ft_printf(const char *str, ...)
{
	t_core		core;
	int			fd;
	va_list		ap;

	if (!str)
		return (-1);
	fd = 1;
	ft_init_struct(&core, fd);
	va_start(ap, str);
	ft_core(&core, str, fd, ap);
	va_end(ap);
	if (core.count == -2)
		return (-1);
	return (core.count);
}

int				ft_dprintf(int fd, const char *str, ...)
{
	t_core		core;
	va_list		ap;

	if (!str)
		return (-1);
	ft_init_struct(&core, fd);
	va_start(ap, str);
	ft_core(&core, str, fd, ap);
	va_end(ap);
	if (core.count == -2)
		return (-1);
	return (core.count);
}
