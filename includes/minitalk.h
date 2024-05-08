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

typedef struct s_signal
{
	int	ch;
	int	ch2;
	int	ans;
	int	pid;
}	t_signal;

extern t_signal	g_signal;
void	byte1(void);
void	byte2(void);
void	byte3(void);
void	byte4(void);
void	handler_sigusr1(int sig, siginfo_t *si, void *unused);
void	handler_sigusr2(int sig, siginfo_t *si, void *signal);
void	get_byte(void);
int		ccal(void);
void	set_act(void);

#endif
