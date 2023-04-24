/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:30:30 by yabad             #+#    #+#             */
/*   Updated: 2022/12/14 12:30:28 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	tests(const char *needle, \
const char *haystack, size_t *i, size_t *j)
{
	if (needle[*j + 1] && haystack[*i + 1] == needle[*j + 1])
	{
		(*j)++;
		(*i)++;
	}
	else if (needle[*j + 1] && haystack[*i + 1] != needle[*j + 1])
	{
		*i = *i - (*j - 1);
		*j = 0;
	}
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!haystack && n == 0)
		return (NULL);
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < n)
	{
		if (!(haystack[i] == needle[j]))
			i++;
		else
		{
			if (!needle[j + 1])
				return ((char *)haystack + (i - j));
			else
				tests(needle, haystack, &i, &j);
		}
	}
	return (NULL);
}
