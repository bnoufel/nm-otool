/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:35:18 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:35:47 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ulltoa_base(unsigned long long n, int base)
{
	uint64_t	tmpn;
	uint64_t	len;
	char		*str;

	tmpn = n;
	len = 2;
	while (tmpn /= base)
		len++;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % base + ((n % base > 9) ? ('A' - 10) : ('0'));
		n = n / base;
	}
	return (str);
}
