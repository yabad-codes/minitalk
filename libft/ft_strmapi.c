/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:52:48 by yabad             #+#    #+#             */
/*   Updated: 2022/12/14 12:30:17 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		ls;
	char	*sp;

	i = 0;
	ls = ft_strlen(s);
	sp = (char *)malloc(ls + 1);
	if (!sp)
		return (NULL);
	while (s[i])
	{
		sp[i] = f(i, s[i]);
		i++;
	}
	sp[i] = '\0';
	return (sp);
}
