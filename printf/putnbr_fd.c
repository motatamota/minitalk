/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:13:05 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/21 19:13:05 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set(long k)
{
	char	c;

	if (k < 10)
	{
		c = k + '0';
		write(1, &c, 1);
		return ;
	}
	set(k / 10);
	c = k % 10 + '0';
	write(1, &c, 1);
}

void	putnbr_fd(long n, int fd)
{
	long	k;

	k = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		k = -n;
	}
	set(k);
}
