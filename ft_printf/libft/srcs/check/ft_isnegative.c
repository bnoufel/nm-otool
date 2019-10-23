/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnegative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 08:07:25 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:30:47 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isnegative(int *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (1);
	}
	return (0);
}