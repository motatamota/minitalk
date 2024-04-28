/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:24:03 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 20:24:03 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_c(t_pf list, va_list ap)
{
	int	k;
	int	n;

	n = 0;
	k = va_arg(ap, int);
	if (list.flag_start == '-')
		write(1, &k, 1);
	while (n < list.flag_len - 1)
	{
		write(1, " ", 1);
		n++;
	}
	if (list.flag_start != '-')
		write(1, &k, 1);
	return (n + 1);
}
