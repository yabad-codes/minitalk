/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:21:07 by yabad             #+#    #+#             */
/*   Updated: 2022/12/14 12:30:38 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	if_exist(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	positions(char const *s1, char const *set, int *r, int *l)
{
	int	len;
	int	ls1;

	len = 0;
	ls1 = ft_strlen(s1);
	*l = ls1 - 1;
	while ((*r) < ls1 && if_exist(s1[*r], set))
	{
		(*r)++;
		len++;
	}
	while ((*l) > 0 && if_exist(s1[*l], set))
	{
		(*l)--;
		len++;
	}
	return (ls1 - len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		r;
	int		l;
	int		flen;
	char	*rslt;

	if (s1 && set)
	{	
		r = 0;
		l = ft_strlen(s1) - 1;
		flen = positions(s1, set, &r, &l);
		if (flen < 0)
			flen = 0;
		rslt = (char *)malloc(flen + 1);
		if (!rslt)
			return (NULL);
		r = 0;
		while (r < (int)ft_strlen(s1) && if_exist(s1[r], set))
			r++;
		ft_strlcpy(rslt, &s1[r], flen + 1);
		return (rslt);
	}
	return (NULL);
}
