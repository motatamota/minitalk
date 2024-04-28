/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:08:02 by tashiget          #+#    #+#             */
/*   Updated: 2024/04/06 14:08:02 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	killchar(int pd, unsigned int num, int t)
{
	int	a;

	if (t == 0)
	{
		if (num % 2)
			a = kill(pd, SIGUSR2);
		else
			a = kill(pd, SIGUSR1);
		usleep(1000);
		return (a);
	}
	if (killchar(pd, num / 2, t - 1) == -1)
		return (-1);
	if (num % 2)
		kill(pd, SIGUSR2);
	else
		kill(pd, SIGUSR1);
	usleep(1000);
	return (0);
}

int	pushkill(int pd, unsigned char *str)
{
	int	n;

	n = 0;
	while (*(str + n))
	{
		if (killchar(pd, (unsigned int)*(str + n), 7) == -1)
			return (-1);
		n++;
	}
	killchar(pd, 0, 7);
	return (0);
}

int	checkint(char *str)
{
	int	n;

	n = 0;
	while (*(str + n))
	{
		if (!(*(str + n) >= '0' && *(str + n) <= '9'))
			return (0);
		n++;
	}
	return (1);
}

void	handl(int sig)
{
	(void)sig;
	ft_printf("Success!\n");
}

int	main(int ac, char **av)
{
	int					num;
	struct sigaction	sig1;

	if (ac != 3 || !checkint(*(av + 1)))
	{
		ft_printf("Error: Please confirm PID.\n");
		return (1);
	}
	sigemptyset(&sig1.sa_mask);
	sig1.sa_handler = handl;
	sig1.sa_flags = 0;
	sigaction(SIGUSR1, &sig1, NULL);
	num = ft_atoi(*(av + 1));
	num = pushkill(num, (unsigned char *)*(av + 2));
	if (num == -1)
	{
		ft_printf("Error: Check PID.\n");
		return (1);
	}
	if (usleep(1000) == -1)
		ft_printf("Error: Some signals are missing.\n");
}
