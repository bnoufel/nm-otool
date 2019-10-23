/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:32:25 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:32:27 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int			ft_count_words(char const *s, char c)
{
	int				words;
	int				wrd;
	int				i;

	wrd = 1;
	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			wrd = 1;
		else if (wrd == 1)
		{
			words++;
			wrd = 0;
		}
		i++;
	}
	return (words);
}

static int			ft_len(char const *s, int i, char c)
{
	int				len_word;

	len_word = 0;
	while (s[i] && s[i] != c)
	{
		len_word++;
		i++;
	}
	return (len_word);
}

static void			ft_cpyin_tab(char *str, int *i, char c, char const *s)
{
	int				j;

	j = 0;
	while (s[*i] && s[*i] != c)
	{
		str[j] = s[*i];
		j++;
		(*i)++;
	}
	str[j] = '\0';
}

char				**ft_strsplit(char const *s, char c)
{
	char			**tab;
	int				i;
	int				j;

	if (!s || !c)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char*) * (ft_count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!(tab[j] = (char*)malloc(sizeof(char) * (ft_len(s, i, c) + 1))))
				return (NULL);
			ft_cpyin_tab(tab[j], &i, c, s);
			j++;
		}
		else
			i++;
	}
	tab[j] = 0;
	return (tab);
}
