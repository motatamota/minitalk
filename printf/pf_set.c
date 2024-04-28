/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:51:56 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 20:51:56 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	start(const char *str, int *k)
{
	int	c;

	c = 0;
	while (*str == '-' || *str == '0')
	{
		if (*str == '-')
			c = *str;
		if (*str == '0' && c == 0)
			c = *str;
		(*k)++;
		str++;
	}
	return (c);
}

int	len(const char *str, int *k, va_list ap)
{
	int	l;

	if (*str == '*')
	{
		(*k)++;
		return (va_arg(ap, int));
	}
	l = ft_atoi(str);
	while (*str >= '0' && *str <= '9')
	{
		str++;
		(*k)++;
	}
	return (l);
}

int	acc(const char *str, int *k, va_list ap)
{
	int	l;

	if (*str != '.')
		return (-1);
	str++;
	(*k)++;
	if (*str == '*')
	{
		(*k)++;
		return (va_arg(ap, int));
	}
	l = ft_atoi(str);
	while (*str >= '0' && *str <= '9')
	{
		str++;
		(*k)++;
	}
	return (l);
}

int	con(const char *str, int *k)
{
	(*k)++;
	return (*str);
}
