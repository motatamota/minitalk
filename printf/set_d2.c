/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_d2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:03:15 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/21 09:03:15 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_minus(t_pf list, long arg, int len)
{
	int	n;

	if (arg < 0)
		write(1, "-", 1);
	n = 0;
	while (n < list.flag_acc - len)
	{
		write(1, "0", 1);
		n++;
	}
	if (arg > 0)
		putnbr_fd(arg, 1);
	else if (arg < 0)
	{
		list.flag_len--;
		putnbr_fd(-arg, 1);
	}
	else if (arg == 0 && list.flag_acc != 0)
		putnbr_fd(arg, 1);
	n = 0;
	while (n < list.flag_len - list.flag_acc && n < list.flag_len - len)
	{
		write(1, " ", 1);
		n++;
	}
}

void	int_no(t_pf list, long arg, int len)
{
	int	n;

	n = 0;
	if (arg < 0)
		list.flag_len--;
	while (n < list.flag_len - list.flag_acc && n < list.flag_len - len)
	{
		write(1, " ", 1);
		n++;
	}
	if (arg < 0)
		write(1, "-", 1);
	n = 0;
	while (n < list.flag_acc - len)
	{
		write(1, "0", 1);
		n++;
	}
	if (arg > 0)
		putnbr_fd(arg, 1);
	else if (arg < 0)
		putnbr_fd(-arg, 1);
	else if (arg == 0 && list.flag_acc != 0)
		putnbr_fd(arg, 1);
}
