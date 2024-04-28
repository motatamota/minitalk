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

void	byte1(t_signal *signal)
{
	if (g_ans == 0)
	{
		signal->ch2 = 0;
		return ;
	}
	write(1, (unsigned char *)&g_ans, 1);
}

void	byte2(t_signal *signal)
{
	write(1, (unsigned char *)&g_ans, 1);
	get_byte(signal);
	write(1, (unsigned char *)&g_ans, 1);
}

void	byte3(t_signal *signal)
{
	write(1, (unsigned char *)&g_ans, 1);
	get_byte(signal);
	write(1, (unsigned char *)&g_ans, 1);
	get_byte(signal);
	write(1, (unsigned char *)&g_ans, 1);
}

void	byte4(t_signal *signal)
{
	write(1, (unsigned char *)&g_ans, 1);
	get_byte(signal);
	write(1, (unsigned char *)&g_ans, 1);
	get_byte(signal);
	write(1, (unsigned char *)&g_ans, 1);
	get_byte(signal);
	write(1, (unsigned char *)&g_ans, 1);
}
