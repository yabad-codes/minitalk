/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:06:45 by yabad             #+#    #+#             */
/*   Updated: 2022/12/15 17:50:14 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*from_int_to_bin(unsigned char n)
{
	unsigned char	*res;
	int				i;

	i = 8;
	res = (unsigned char *)malloc(i + 1);
	if (!res)
		return (NULL);
	res[i] = '\0';
	while (--i >= 0)
	{
		res[i] = n % 2 + '0';
		n = n / 2;
	}
	return (res);
}

void	send_char(unsigned char *str, char *pid)
{
	int	i;
	int	k;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			k = kill(ft_atoi(pid), SIGUSR1);
		else
			k = kill(ft_atoi(pid), SIGUSR2);
		if (k == -1)
		{
			ft_putstr_fd("PID does not exist\n", 1);
			exit(-1);
		}
		usleep(200);
		i++;
	}
}

void	throught_string(char *str, char *pid)
{
	int				i;
	unsigned char	*bin;

	i = 0;
	while (i <= (int)ft_strlen(str))
	{
		bin = from_int_to_bin(str[i]);
		send_char(bin, pid);
		free(bin);
		i++;
	}
}

void	handler1(int signum)
{
	if (signum == SIGUSR1)
		ft_putstr_fd("MSG RECEIVED!!\n", 1);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					i;

	sa.sa_handler = &handler1;
	sigaction(SIGUSR1, &sa, NULL);
	if (ac == 3)
	{
		i = 0;
		while (av[1][i])
		{
			if (!ft_isdigit(av[1][i]) || ft_strncmp(av[1], "0", 1) == 0)
				exit(-1);
			i++;
		}
		throught_string(av[2], av[1]);
	}
	else
		exit(-1);
}
