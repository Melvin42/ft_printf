/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_neg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 08:47:17 by melperri          #+#    #+#             */
/*   Updated: 2021/01/25 12:32:21 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flag_zero_int_neg(t_flags *flags, char *s)
{
	int	i;

	i = -1;
	if (flags->moins)
	{
		flags->ret += write(1, "-", 1);
		while (++i < flags->preci - flags->len)
			flags->ret += write(1, "0", 1);
		flags->ret += write(1, s, flags->len);
		i += flags->len;
		while (++i < flags->width)
			flags->ret += write(1, " ", 1);
		return ;
	}
	if (flags->len < flags->preci)
		while (++i < flags->width - flags->preci - 1)
			flags->ret += write(1, " ", 1);
	else
		while (++i < flags->width - flags->len - 1)
			flags->ret += write(1, " ", 1);
	flags->ret += write(1, "-", 1);
	i = 0;
	while (++i <= flags->preci - flags->len)
		flags->ret += write(1, "0", 1);
	flags->ret += write(1, s, flags->len);
}

static void	ft_nopreci_int_neg(t_flags *flags, char *s)
{
	int	i;

	i = -1;
	if (!flags->moins && !flags->zero)
	{
		while (++i < flags->width - flags->len - 1)
			flags->ret += write(1, " ", 1);
		flags->ret += write(1, "-", 1);
		flags->ret += write(1, s, flags->len);
	}
	else if (flags->moins && !flags->zero)
	{
		flags->ret += write(1, "-", 1);
		flags->ret += write(1, s, flags->len);
		i = flags->len;
		while (++i < flags->width)
			flags->ret += write(1, " ", 1);
	}
	else
	{
		flags->ret += write(1, "-", 1);
		while (++i < flags->width - flags->len - 1)
			flags->ret += write(1, "0", 1);
		flags->ret += write(1, s, flags->len);
	}
}

static void	ft_preci_int_neg(t_flags *flags, char *s)
{
	if (!flags->zero)
		no_flag_zero_int_neg(flags, s);
	else
		flag_zero_int_neg(flags, s);
}

void		ft_flags_int_neg(t_flags *flags, char *s)
{
	char *tofree;
	if (s[0] == '-')
	{
		tofree = s;
		s = ft_substr(s, 1, (size_t)flags->len - 1);
		flags->len--;
		free(tofree);
		tofree = NULL;
	}
	if (!flags->point)
		ft_nopreci_int_neg(flags, s);
	else
		ft_preci_int_neg(flags, s);
}
