/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:06:41 by tashiget          #+#    #+#             */
/*   Updated: 2024/04/06 17:06:41 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_sigusr1(int sig, siginfo_t *si, void *signal)
{
	t_signal	*ss;

	ss = (t_signal *)signal;
	(void)sig;
	ss->ans = ss->ans * 2;
	g_pid = si->si_pid;
}

void	handler_sigusr2(int sig, siginfo_t *si, void *signal)
{
	t_signal	*ss;

	(void)si;
	ss = (t_signal *)signal;
	printf("test%p\n", &ss->ans);
	(void)sig;
	ss->ans = ss->ans * 2 + 1;
	printf("aaaaa%d\n", ss->ans);
}

void	set_act(t_signal *signal)
{
	struct sigaction	sig1;
	struct sigaction	sig2;

	sigemptyset(&sig1.sa_mask);
	sig1.sa_sigaction = handler_sigusr1;
	sig1.sa_flags = SA_SIGINFO;
	sigemptyset(&sig2.sa_mask);
	sig2.sa_sigaction = handler_sigusr2;
	sig2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig1, (void *)signal);
	sigaction(SIGUSR2, &sig2, (void *)signal);
}

void	get_byte(t_signal *signal)
{
	int	n;

	n = 0;
	signal->ans = 0;
	while (n < 8)
	{
		pause();
		printf("???%d\n", signal->ans);
		signal->ch = 1;
		signal->ch2 = 1;
		n++;
	}
}

int	ccal(t_signal *signal)
{
	get_byte(signal);
	if (signal->ans == 0)
		return (-1);
	if (signal->ans < 192)
		byte1(signal);
	else if (signal->ans < 224)
		byte2(signal);
	else if (signal->ans < 240)
		byte3(signal);
	else
		byte4(signal);
	return (0);
}
