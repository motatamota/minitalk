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

volatile sig_atomic_t	g_ans = 0;
volatile sig_atomic_t	g_pid = 0;

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
	t_signal			signal;
	pid_t				pd;

	pd = getpid();
	display_pid(pd);
	set_act();
	signal.ch = 0;
	signal.ch2 = 0;
	while (1)
	{
		pd = ccal(&signal);
		if (pd == -1)
		{
			kill(g_pid, SIGUSR1);
			write(1, "\n", 1);
			signal.ch = 0;
			signal.ch2 = 0;
		}
	}
}