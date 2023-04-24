/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:54:43 by yabad             #+#    #+#             */
/*   Updated: 2022/12/14 12:29:26 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	np;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		np = -1 * n;
	}
	else
		np = n;
	if (np < 10)
		ft_putchar_fd(np + '0', fd);
	else
	{
		ft_putnbr_fd(np / 10, fd);
		ft_putchar_fd(np % 10 + '0', fd);
	}
}
