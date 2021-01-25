/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 08:56:59 by melperri          #+#    #+#             */
/*   Updated: 2021/01/25 10:13:18 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int(va_list ap, t_flags *flags)
{
	int		d;
	int		i;
	char	*s;

	i = -1;
	d = va_arg(ap, int);
	s = ft_itoa(d);
	flags->len = (int)ft_strlen(s);
	if (is_flag_on(flags))
	{
		if (d == 0 && flags->width && flags->point && !flags->preci)
			while (++i < flags->width)
				flags->ret += write(1, " ", 1);
		else if (d == 0 && !flags->width && flags->point && !flags->preci)
			;
		else if (d < 0)
			ft_flags_int_neg(flags, s);
		else
			ft_flags_int(flags, s);
	}
	else
		flags->ret += write(1, s, flags->len);
	free(s);
	s = NULL;
}

void	ft_print_u(va_list ap, t_flags *flags)
{
	unsigned int	u;
	int				i;
	char			*s;

	u = va_arg(ap, unsigned int);
	s = ft_utoa(u);
	flags->len = (int)ft_strlen(s);
	if (is_flag_on(flags))
	{
		if (u == 0 && flags->width && flags->point && !flags->preci)
		{
			i = -1;
			while (++i < flags->width)
				flags->ret += write(1, " ", 1);
		}
		else if (u == 0 && !flags->width && flags->point && !flags->preci)
			;
		else
			ft_flags_int(flags, s);
	}
	else
		flags->ret += write(1, s, flags->len);
	free(s);
	s = NULL;
}

void	ft_print_hexmin(va_list ap, t_flags *flags)
{
	unsigned int	x;
	int				i;
	char			*s;

	x = va_arg(ap, unsigned int);
	s = ft_utoa_base(x, BASEHEXMIN);
	flags->len = (int)ft_strlen(s);
	if (is_flag_on(flags))
	{
		if (x == 0 && flags->width && flags->point && !flags->preci)
		{
			i = -1;
			while (++i < flags->width)
				flags->ret += write(1, " ", 1);
		}
		else if (x == 0 && !flags->width && flags->point && !flags->preci)
			;
		else
			ft_flags_int(flags, s);
	}
	else
		flags->ret += write(1, s, flags->len);
	free(s);
	s = NULL;
}

void	ft_print_hexmaj(va_list ap, t_flags *flags)
{
	unsigned int	x2;
	int				i;
	char			*s;

	x2 = va_arg(ap, unsigned int);
	s = ft_utoa_base(x2, BASEHEXMAJ);
	flags->len = (int)ft_strlen(s);
	if (is_flag_on(flags))
	{
		if (x2 == 0 && flags->width && flags->point && !flags->preci)
		{
			i = -1;
			while (++i < flags->width)
				flags->ret += write(1, " ", 1);
		}
		else if (x2 == 0 && !flags->width && flags->point && !flags->preci)
			;
		else
			ft_flags_int(flags, s);
	}
	else
		flags->ret += write(1, s, flags->len);
	free(s);
	s = NULL;
}
