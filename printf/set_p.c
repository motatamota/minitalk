/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:23:15 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/21 08:23:15 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	how(unsigned long long ptr)
{
	int	n;

	n = 0;
	while (ptr >= 16)
	{
		ptr = ptr / 16;
		n++;
	}
	return (n + 3);
}

void	put_x16(unsigned long long ptr)
{
	char	c;

	if (ptr >= 10)
		c = ptr - 10 + 'a';
	else
		c = ptr + '0';
	write(1, &c, 1);
}

void	putnbr_x16(unsigned long long ptr)
{
	if (ptr < 16)
	{
		put_x16(ptr);
		return ;
	}
	putnbr_x16(ptr / 16);
	put_x16(ptr % 16);
}

void	set_p2(t_pf list, uintptr_t ptr, int len)
{
	int	n;

	n = 0;
	if (list.flag_start == '-')
	{
		ft_putstr_fd("0x", 1);
		putnbr_x16(ptr);
	}
	while (n < list.flag_len - len)
	{
		write(1, " ", 1);
		n++;
	}
	if (list.flag_start != '-')
	{
		ft_putstr_fd("0x", 1);
		putnbr_x16(ptr);
	}
}

int	set_p(t_pf list, va_list ap)
{
	uintptr_t	ptr;
	int			len;

	ptr = va_arg(ap, uintptr_t);
	if (!ptr)
	{
		write(1, "0x0", 3);
		return (3);
	}
	len = how(ptr);
	set_p2(list, ptr, len);
	if (list.flag_len > len)
		return (list.flag_len);
	return (len);
}
