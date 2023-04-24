/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 20:10:25 by yabad             #+#    #+#             */
/*   Updated: 2022/12/14 12:29:37 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_words(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
				i++;
			n++;
		}
	}
	return (n);
}

static int	l_word(char	const *s, char c, int i)
{
	int	n;

	n = 0;
	while (s[i] && s[i] != c)
	{
		n++;
		i++;
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		*v;

	v = (int []){0, 0, 0};
	tab = (char **)malloc((c_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (s[v[0]])
	{
		v[2] = 0;
		while (s[v[0]] == c)
			v[0]++;
		if (s[v[0]])
		{
			tab[v[1]] = (char *)malloc((l_word(s, c, v[0]) + 1) * sizeof(char));
			if (!tab[v[1]])
				return (NULL);
			while (s[v[0]] && s[v[0]] != c)
				tab[v[1]][v[2]++] = s[v[0]++];
			tab[v[1]][v[2]] = '\0';
			v[1]++;
		}
	}
	tab[v[1]] = NULL;
	return (tab);
}
