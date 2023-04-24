/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:13:06 by yabad             #+#    #+#             */
/*   Updated: 2022/12/14 12:29:59 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	ls;
	unsigned int	ld;

	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	ls = ft_strlen(src);
	ld = ft_strlen(dst);
	j = ld;
	if (dstsize == 0 || ld >= dstsize)
		return (ls + dstsize);
	while (src[i] && i < dstsize - ld - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (ld + ls);
}
