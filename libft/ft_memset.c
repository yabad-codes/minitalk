/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:35:43 by yabad             #+#    #+#             */
/*   Updated: 2022/09/30 10:30:37 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*bprime;
	size_t	i;

	i = 0;
	bprime = b;
	while (i < len)
	{
		bprime[i] = (unsigned char)c;
		i++;
	}
	return (bprime);
}
