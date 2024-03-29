/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:41:51 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:41:52 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoc(const char *s, int *c)
{
	long int	r;
	int			sig;
	int			i;

	r = 0;
	i = 0;
	sig = 1;
	while (s[i])
	{
		while (s[i] == '\t' || s[i] == '\n' || s[i] == '\r'
				|| s[i] == '\v' || s[i] == '\f' || s[i] == ' ')
			i++;
		s[i] == '-' ? sig = -sig : 0;
		if (s[i] == '+' || s[i] == '-')
			i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			r *= 10;
			r += s[i++] - '0';
		}
		r = r * sig;
		*c = r > 2147483647 || r < -2147483648 ? -1 : 0;
		return ((int)r);
	}
	return (0);
}
