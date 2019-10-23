/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:30:56 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:30:57 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		isbin(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] < 0 || s[i] > 126)
			return (1);
		i++;
	}
	return (0);
}
