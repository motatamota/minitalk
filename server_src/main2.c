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

extern t_signal	g_signal;

void	handler_sigusr1(int sig, siginfo_t *si, void *unused)
{
	(void)sig;
	(void)unused;
	g_signal.ans = g_signal.ans * 2;
	g_signal.pid = si->si_pid;
}

void	handler_sigusr2(int sig, siginfo_t *si, void *unused)
{
	(void)si;
	(void)unused;
	(void)sig;
	g_signal.ans = g_signal.ans * 2 + 1;
}

void	set_act(void)
{
	struct sigaction	sig1;
	struct sigaction	sig2;

	sigemptyset(&sig1.sa_mask);
	sig1.sa_sigaction = handler_sigusr1;
	sig1.sa_flags = SA_SIGINFO;
	sigemptyset(&sig2.sa_mask);
	sig2.sa_sigaction = handler_sigusr2;
	sig2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig1, NULL);
	sigaction(SIGUSR2, &sig2, NULL);
}

void	get_byte(void)
{
	int	n;

	n = 0;
	g_signal.ans = 0;
	while (n < 8)
	{
		pause();
		g_signal.ch = 1;
		g_signal.ch2 = 1;
		n++;
	}
}

int	ccal(void)
{
	get_byte();
	if (g_signal.ans == 0)
		return (-1);
	if (g_signal.ans < 192)
		byte1();
	else if (g_signal.ans < 224)
		byte2();
	else if (g_signal.ans < 240)
		byte3();
	else
		byte4();
	return (0);
}
