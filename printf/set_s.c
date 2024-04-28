/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:45:57 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 21:45:57 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	set_s_sub(t_pf list, int len, char *str)
{
	int	n;

	n = 0;
	ft_putstr_fd(str, 1);
	while (n < list.flag_len - len)
	{
		write(1, " ", 1);
		n++;
	}
}

int	cal(t_pf list, int len)
{
	if (list.flag_len > len)
		return (list.flag_len);
	return (len);
}

void	set_s2(t_pf list, int len, int n, char *str)
{
	while (n < list.flag_len - len)
	{
		write(1, " ", 1);
		n++;
	}
	ft_putstr_fd(str, 1);
	free (str);
}

int	set_s(t_pf list, va_list ap)
{
	char	*str;
	int		len;
	int		n;

	n = 0;
	str = va_arg(ap, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	str = ft_strdup(str);
	len = ft_strlen(str);
	if (list.flag_acc >= 0 && list.flag_acc < len)
	{
		*(str + list.flag_acc) = '\0';
		len = list.flag_acc;
	}
	if (list.flag_start == '-')
	{
		set_s_sub(list, len, str);
		return (cal(list, len));
	}
	set_s2(list, len, n, str);
	return (cal(list, len));
}
