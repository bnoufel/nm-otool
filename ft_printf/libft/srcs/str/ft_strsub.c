/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:32:30 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:32:31 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = NULL;
	if (!(str = (char *)(malloc(sizeof(char) * (len + 1)))))
		return (NULL);
	if (!s)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i + start] != '\t' ? s[i + start] : ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}
