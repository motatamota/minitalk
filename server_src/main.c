/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:02:56 by tashiget          #+#    #+#             */
/*   Updated: 2024/04/03 20:02:56 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_signal	g_signal;

void	display_pid(int process_id)
{
	ft_printf("\t///////////////////////////////////////////////////\n");
	ft_printf("\t██////██//█//██///█//█/███████///█////█/////█///█//\n");
	ft_printf("\t██////██//█//██///█//█////█//////█////█/////█//█///\n");
	ft_printf("\t███//█/█//█//█/█//█//█////█/////█/█///█/////█/█////\n");
	ft_printf("\t█/█//█/█//█//█/██/█//█////█/////█/█///█/////███////\n");
	ft_printf("\t█/█//█/█//█//█//█/█//█////█////█///█//█/////█/█////\n");
	ft_printf("\t█//██//█//█//█///██//█////█////█████//█/////█//█///\n");
	ft_printf("\t█//██//█//█//█///██//█////█////█///█//█/////█///█//\n");
	ft_printf("\t█//////█//█//█////█//█////█///█/////█/█████/█///██/\n");
	ft_printf("\t///////////////////////////////////////////////////\n");
	ft_printf("\tPID: %d\n", process_id);
	ft_printf("\tWaiting for a message...\n");
}

int	main(void)
{
	pid_t				pd;

	g_signal.ch = 0;
	g_signal.ch2 = 0;
	g_signal.ans = 0;
	pd = getpid();
	display_pid(pd);
	set_act();
	while (1)
	{
		pd = ccal();
		if (pd == -1)
		{
			kill(g_signal.pid, SIGUSR1);
			write(1, "\n", 1);
			g_signal.ch = 0;
			g_signal.ch2 = 0;
		}
	}
}
