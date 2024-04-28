/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:26:49 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/26 22:26:49 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

typedef struct s_pf
{
	int	flag_start;
	int	flag_len;
	int	flag_acc;
	int	flag_con;
}	t_pf;

int		start(const char *str, int *k);
int		len(const char *str, int *k, va_list ap);
int		acc(const char *str, int *k, va_list ap);
int		con(const char *str, int *k);
int		set_c(t_pf list, va_list ap);
int		set_s(t_pf list, va_list ap);
int		set_p(t_pf list, va_list ap);
int		set_d(t_pf list, va_list ap);
void	int_minus(t_pf list, long arg, int len);
void	int_no(t_pf list, long arg, int len);
void	putnbr_fd(long n, int fd);
int		set_x(t_pf list, va_list ap);
int		set_X(t_pf list, va_list ap);
int		set_xx(t_pf list, va_list ap);
int		set_per(void);
int		ft_printf(const char *str, ...);

#endif
