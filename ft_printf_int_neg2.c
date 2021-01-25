/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_neg2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:02:56 by melperri          #+#    #+#             */
/*   Updated: 2021/01/25 12:20:39 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	no_flag_zero_int_neg_moins(t_flags *flags, char *s)
{
	int	i;

	i = -1;
	flags->ret += write(1, "-", 1);
	while (++i < flags->preci - flags->len)
		flags->ret += write(1, "0", 1);
	flags->ret += write(1, s, flags->len);
	i += flags->len;
	while (++i < flags->width)
		flags->ret += write(1, " ", 1);
}

static void	no_flag_zero_int_neg_no_moins(t_flags *flags, char *s)
{
	int	i;

	i = -1;
	if (flags->len < flags->preci)
	{
		while (++i < flags->width - flags->preci - 1)
			flags->ret += write(1, " ", 1);
		flags->ret += write(1, "-", 1);
		i = 0;
		while (++i <= flags->preci - flags->len)
			flags->ret += write(1, "0", 1);
	}
	else
	{
		while (++i < flags->width - flags->len - 1)
			flags->ret += write(1, " ", 1);
		i = 0;
		while (++i <= flags->preci - flags->len)
			flags->ret += write(1, "0", 1);
		flags->ret += write(1, "-", 1);
	}
	flags->ret += write(1, s, flags->len);
}

void		no_flag_zero_int_neg(t_flags *flags, char *s)
{
	if (flags->moins)
		no_flag_zero_int_neg_moins(flags, s);
	else
		no_flag_zero_int_neg_no_moins(flags, s);
}
