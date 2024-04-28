/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:20:51 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 13:20:51 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ncount(const char *str)
{
	int	count;
	int	k;

	count = 0;
	k = 0;
	while (*(str + k))
	{
		if (*(str + k) == '%')
			count++;
		k++;
	}
	return (count);
}

int	put_to_per(const char *str, int *cou)
{
	int	n;

	n = 0;
	while (*(str + n) && *(str + n) != '%')
	{
		write(1, str + n, 1);
		n++;
	}
	*cou += n;
	return (n);
}

int	put(t_pf list, va_list ap)
{
	if (list.flag_con == 'c')
		return (set_c(list, ap));
	else if (list.flag_con == 's')
		return (set_s(list, ap));
	else if (list.flag_con == 'p')
		return (set_p(list, ap));
	else if (list.flag_con == 'd'
		|| list.flag_con == 'i' || list.flag_con == 'u')
		return (set_d(list, ap));
	else if (list.flag_con == 'x')
		return (set_x(list, ap));
	else if (list.flag_con == 'X')
		return (set_xx(list, ap));
	else if (list.flag_con == '%')
		return (set_per());
	return (-1);
}

int	put_per(const char *str, va_list ap, int *n, int *count)
{
	int		k;
	t_pf	list;

	k = 1;
	list.flag_start = start(str + k, &k);
	list.flag_len = len(str + k, &k, ap);
	if (list.flag_len < 0)
	{
		list.flag_len = -list.flag_len;
		list.flag_start = '-';
	}
	list.flag_acc = acc(str + k, &k, ap);
	list.flag_con = con(str + k, &k);
	*count += k;
	k = put(list, ap);
	if (list.flag_con == '%')
		(*n)++;
	(*n)++;
	return (k);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		ans;
	int		n;
	int		how;
	int		count;

	how = ncount(str);
	va_start(ap, str);
	n = 0;
	count = 0;
	ans = 0;
	while (n < how)
	{
		ans += put_to_per(str + count, &count);
		ans += put_per(str + count, ap, &n, &count);
	}
	ans += put_to_per(str + count, &count);
	va_end(ap);
	return (ans);
}

// int main()
// {
// 	printf("m = %d\n", ft_printf(SAMPLE));
// 	printf("m = %d\n", printf(SAMPLE));
// }
