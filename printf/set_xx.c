/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_xx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:37:52 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/21 21:37:52 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	xqhow(unsigned int k)
{
	int	n;

	n = 0;
	while (k >= 16)
	{
		k = k / 16;
		n++;
	}
	return (n + 1);
}

void	xqput_x16(unsigned int k)
{
	char	c;

	if (k >= 10)
		c = k - 10 + 'A';
	else
		c = k + '0';
	write(1, &c, 1);
}

void	xqputnbr_x16(unsigned int k)
{
	if (k < 16)
	{
		xqput_x16(k);
		return ;
	}
	xqputnbr_x16(k / 16);
	xqput_x16(k % 16);
}

void	putnbr_x16_xx(unsigned int k, t_pf list, int len)
{
	int	n;
	int	t;

	t = list.flag_acc;
	if (list.flag_start == '0')
		t = list.flag_len;
	n = 0;
	while (n < t - len)
	{
		write(1, "0", 1);
		n++;
	}
	xqputnbr_x16(k);
}

int	set_xx(t_pf list, va_list ap)
{
	unsigned int	k;
	int				len;
	int				n;

	k = va_arg(ap, unsigned int);
	len = xqhow(k);
	n = 0;
	if (list.flag_start == '-')
		putnbr_x16_xx(k, list, len);
	while (list.flag_start != '0' && n < list.flag_len - len
		&& n < list.flag_len - list.flag_acc)
	{
		write(1, " ", 1);
		n++;
	}
	if (list.flag_start != '-')
		putnbr_x16_xx(k, list, len);
	if (list.flag_len > len && list.flag_len > list.flag_acc)
		return (list.flag_len);
	if (len > list.flag_acc)
		return (len);
	return (list.flag_acc);
}
