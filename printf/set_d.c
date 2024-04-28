/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:51:33 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/21 08:51:33 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	how_d(long arg)
{
	int	n;

	n = 0;
	while (arg >= 10 || arg <= -10)
	{
		arg = arg / 10;
		n++;
	}
	return (n + 1);
}

void	int_zero(t_pf list, long arg, int len)
{
	int	n;

	n = 0;
	if (arg < 0)
	{
		write(1, "-", 1);
		n++;
	}
	while (n < list.flag_len - len)
	{
		write(1, "0", 1);
		n++;
	}
	if (arg > 0)
		putnbr_fd(arg, 1);
	else
		putnbr_fd(-arg, 1);
}

int	set_d(t_pf list, va_list ap)
{
	long	arg;
	int		len;

	if (list.flag_con == 'u')
		arg = (long)va_arg(ap, unsigned int);
	else
		arg = (long)va_arg(ap, int);
	len = how_d(arg);
	if (list.flag_start == '-')
		int_minus(list, arg, len);
	else if (list.flag_start == '0')
		int_zero(list, arg, len);
	else
		int_no(list, arg, len);
	if (arg < 0)
	{
		len++;
		list.flag_acc++;
	}
	if (list.flag_len > list.flag_acc && list.flag_len > len)
		return (list.flag_len);
	if (list.flag_acc > len)
		return (list.flag_acc);
	return (len);
}
