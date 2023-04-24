/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 08:46:07 by yabad             #+#    #+#             */
/*   Updated: 2022/10/15 11:59:27 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*s1p;
	char	*s2p;

	i = 0;
	s1p = (char *)s1;
	s2p = (char *)s2;
	if (n == 0)
		return (0);
	while (s1p[i] == s2p[i] && i < n - 1)
		i++;
	return ((unsigned char)s1p[i] - (unsigned char)s2p[i]);
}
