/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:39:34 by tashiget          #+#    #+#             */
/*   Updated: 2024/04/06 16:39:34 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

extern t_signal	g_signal;

void	byte1(void)
{
	if (g_signal.ans == 0)
	{
		g_signal.ch2 = 0;
		return ;
	}
	write(1, (unsigned char *)&g_signal.ans, 1);
}

void	byte2(void)
{
	write(1, (unsigned char *)&g_signal.ans, 1);
	get_byte();
	write(1, (unsigned char *)&g_signal.ans, 1);
}

void	byte3(void)
{
	write(1, (unsigned char *)&g_signal.ans, 1);
	get_byte();
	write(1, (unsigned char *)&g_signal.ans, 1);
	get_byte();
	write(1, (unsigned char *)&g_signal.ans, 1);
}

void	byte4(void)
{
	write(1, (unsigned char *)&g_signal.ans, 1);
	get_byte();
	write(1, (unsigned char *)&g_signal.ans, 1);
	get_byte();
	write(1, (unsigned char *)&g_signal.ans, 1);
	get_byte();
	write(1, (unsigned char *)&g_signal.ans, 1);
}
