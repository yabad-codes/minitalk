/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:06:30 by yabad             #+#    #+#             */
/*   Updated: 2022/12/15 16:33:16 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_pow(int num, int p)
{
	int	res;

	res = 1;
	while (p)
	{
		res *= num;
		p--;
	}
	return (res);
}

void	binary_to_char(unsigned char *str, siginfo_t *info)
{
	int	i;
	int	p;
	int	c;

	i = 8;
	c = 0;
	p = 0;
	while (--i >= 0)
	{
		c += (str[i] - '0') * ft_pow(2, p);
		p++;
	}
	if (c == '\0')
		kill(info->si_pid, SIGUSR1);
	ft_putchar_fd(c, 1);
}

void	handler_sigusr(int signum, siginfo_t *info, void *ucontext)
{
	static unsigned char	var[8];
	static int				i;
	static int				pid;

	if (info->si_pid != pid)
		i = 0;
	if (signum == SIGUSR1)
		var[i] = '0';
	else
		var[i] = '1';
	i++;
	if (i == 8)
	{
		binary_to_char(var, info);
		i = 0;
	}
	pid = info->si_pid;
	(void)ucontext;
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd((int)getpid(), 1);
	ft_putstr_fd("\n", 1);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = &handler_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
}
