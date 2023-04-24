/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:25:17 by yabad             #+#    #+#             */
/*   Updated: 2022/12/14 12:28:42 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*allocate(int n, int *size)
{
	char	*str;

	if (n >= 0)
		*size = *size + 1;
	else
		*size = *size + 2;
	while (n)
	{
		(*size)++;
		n = n / 10;
	}
	str = (char *)malloc(*size);
	return (str);
}

static char	*neg(int n, int *size, char *str)
{
	unsigned int	np;

	np = n * -1;
	(*size)--;
	str[*size] = '\0';
	str[0] = '-';
	while (--(*size) > 0)
	{
		str[*size] = np % 10 + '0';
		np = np / 10;
	}
	return (str);
}

static char	*pos(int n, int *size, char	*str)
{
	(*size)--;
	str[*size] = '\0';
	while (--(*size) >= 0)
	{
		str[*size] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

static char	*case_0(char	*str)
{
	str = malloc(2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	str = NULL;
	size = 0;
	if (n < 0)
	{
		str = allocate(n, &size);
		if (!str)
			return (NULL);
		str = neg(n, &size, str);
	}
	else if (n > 0)
	{
		str = allocate(n, &size);
		if (!str)
			return (NULL);
		str = pos(n, &size, str);
	}
	else
		str = case_0(str);
	return (str);
}
