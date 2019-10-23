/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:34:48 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:34:58 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isllnegative(long long *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (1);
	}
	return (0);
}

char			*ft_lltoa_base(long long n, int base)
{
	long long	tmpn;
	long long	len;
	int			negative;
	char		*str;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775807"));
	tmpn = n;
	len = 2;
	negative = ft_isllnegative(&n);
	while (tmpn /= base)
		len++;
	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % base + ((n % base > 9) ? ('A' - 10) : ('0'));
		n = n / base;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
