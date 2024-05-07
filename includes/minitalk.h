/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitolk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:03:29 by tashiget          #+#    #+#             */
/*   Updated: 2024/04/03 20:03:29 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "libft.h"
# include "ft_printf.h"
# include <signal.h>
#include <stdio.h>

extern volatile sig_atomic_t	g_pid;
typedef struct s_signal
{
	int	ch;
	int	ch2;
	int	ans;
}	t_signal;

void	byte1(t_signal *signal);
void	byte2(t_signal *signal);
void	byte3(t_signal *signal);
void	byte4(t_signal *signal);
void	handler_sigusr1(int sig, siginfo_t *si, void *unused);
void	handler_sigusr2(int sig, siginfo_t *si, void *signal);
void	get_byte(t_signal *signal);
int		ccal(t_signal *signal);
void	set_act(t_signal *signal);

#endif
