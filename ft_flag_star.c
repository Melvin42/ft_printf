/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_star.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:46:30 by melperri          #+#    #+#             */
/*   Updated: 2021/01/25 12:26:36 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_star_width(t_flags *flags, va_list ap)
{
	int	star;

	star = va_arg(ap, int);
	if (star < 0)
	{
		flags->moins = TRUE;
		star *= -1;
	}
	return (star);
}

int	ft_flag_star_preci(t_flags *flags, va_list ap)
{
	int	star;

	star = va_arg(ap, int);
	if (star < 0)
	{
		flags->point = FALSE;
		return (FALSE);
	}
	else
		return (star);
}
