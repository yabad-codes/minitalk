/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:45:24 by yabad             #+#    #+#             */
/*   Updated: 2022/12/14 12:30:43 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*allocate_substr(unsigned int start, size_t ls, size_t len)
{
	char	*sp;

	if (start < ls)
	{
		if (len < ls)
			sp = (char *)malloc(len + 1);
		else
			sp = (char *)malloc(ls - start + 1);
	}
	else
		sp = (char *)malloc(1);
	return (sp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sp;
	int		i;
	size_t	ls;

	if (!s)
		return (NULL);
	ls = ft_strlen(s);
	sp = allocate_substr(start, ls, len);
	i = 0;
	if (!sp)
		return (NULL);
	if (start <= ls)
	{
		while (start < ls && len)
		{
			sp[i] = s[start];
			i++;
			start++;
			len--;
		}
	}
	sp[i] = '\0';
	return (sp);
}
