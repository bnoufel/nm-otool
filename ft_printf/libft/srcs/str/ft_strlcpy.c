/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:32:17 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:32:18 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlcpy(char *dst, const char *src, int *len)
{
	size_t i;
	size_t k;

	k = 0;
	i = ft_strlen(src);
	while (k < i)
	{
		dst[k] = src[k];
		k++;
	}
	dst[k] = '\0';
	(*len) += (int)k;
	return (dst);
}
