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

void	handler_sigusr1(int sig, siginfo_t *si, void *unused)
{
	(void)sig;
	(void)unused;
	g_ans = g_ans * 2;
	g_pid = si->si_pid;
}

void	handler_sigusr2(int sig)
{
	(void)sig;
	g_ans = g_ans * 2 + 1;
}

void	set_act(void)
{
	struct sigaction	sig1;
	struct sigaction	sig2;

	sigemptyset(&sig1.sa_mask);
	sig1.sa_sigaction = handler_sigusr1;
	sig1.sa_flags = SA_SIGINFO;
	sigemptyset(&sig2.sa_mask);
	sig2.sa_handler = handler_sigusr2;
	sig2.sa_flags = 0;
	sigaction(SIGUSR1, &sig1, NULL);
	sigaction(SIGUSR2, &sig2, NULL);
}

void	get_byte(t_signal *signal)
{
	int	n;

	n = 0;
	g_ans = 0;
	while (n < 8)
	{
		pause();
		signal->ch = 1;
		signal->ch2 = 1;
		n++;
	}
}

int	ccal(t_signal *signal)
{
	get_byte(signal);
	if (g_ans == 0)
		return (-1);
	if (g_ans < 192)
		byte1(signal);
	else if (g_ans < 224)
		byte2(signal);
	else if (g_ans < 240)
		byte3(signal);
	else
		byte4(signal);
	return (0);
}
