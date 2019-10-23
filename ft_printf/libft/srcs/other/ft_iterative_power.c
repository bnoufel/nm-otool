/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:38:44 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:38:45 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long		ft_iterative_power(long long nb, long long power)
{
	long long temp;

	temp = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (power > 1)
	{
		nb *= temp;
		power--;
	}
	return (nb);
}
