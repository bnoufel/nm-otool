/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <golliet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 07:59:35 by bnoufel           #+#    #+#             */
/*   Updated: 2018/06/21 13:19:26 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		**ft_sstrdup(char **s1)
{
	char	**dest;
	int		i;

	i = 0;
	if (!(dest = (char **)malloc(sizeof(char *) * (ft_sstrlen(s1) + 1))))
		return (NULL);
	while (s1[i])
	{
		if (!(dest[i] = ft_strdup(s1[i])))
			return (NULL);
		i++;
	}
	dest[i] = 0;
	return (dest);
}
