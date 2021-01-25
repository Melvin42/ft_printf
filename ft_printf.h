/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:37:49 by melperri          #+#    #+#             */
/*   Updated: 2021/01/25 12:21:11 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define BASEHEXMIN "0123456789abcdef"
# define BASEHEXMAJ "0123456789ABCDEF"

# include "ft_printf_struct.h"
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>

/*
******** PRINTF ********
*/

int		ft_printf(const char *full, ...);

/*
******** CONVERT *******
*/

void	ft_print_percent(t_flags *flags);
void	ft_print_c(va_list ap, t_flags *flags);
void	ft_print_s(va_list ap, t_flags *flags);
void	ft_print_p(va_list ap, t_flags *flags);
void	ft_print_int(va_list ap, t_flags *flags);
void	ft_print_u(va_list ap, t_flags *flags);
void	ft_print_hexmin(va_list ap, t_flags *flags);
void	ft_print_hexmaj(va_list ap, t_flags *flags);

/*
******** FLAG ********
*/

int		is_flag_on(t_flags *flags);
void	ft_flags_addr(t_flags *flags, char *s);
int		ft_flag_star_width(t_flags *flags, va_list ap);
int		ft_flag_star_preci(t_flags *flags, va_list ap);
void	fill_struct_part1(t_flags *flags, const char **full, va_list ap);

/*
******** STRING ********
*/

void	ft_flags_string(t_flags *flags, char *s);
void	no_flag_zero_string(t_flags *flags, char *s);

/*
******** ADDR ********
*/

void	ft_flags_addr(t_flags *flags, char *s);
void	null_addr(t_flags *flags);

/*
******** INT POS ********
*/

void	ft_flags_int(t_flags *flags, char *s);

/*
******** INT NEG ********
*/

void	ft_flags_int_neg(t_flags *flags, char *s);
void	no_flag_zero_int_neg(t_flags *flags, char *s);

/*
******** LIBFT ********
*/

int		ft_atoi_base(char *str, char *base);
char	*ft_itoa_base(int n, char *base);
char	*ft_utoa_base(unsigned int nb, char *base);
char	*ft_ultoa_base(unsigned long nb, char *base);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		findchar(char c, char *base);
int		stopatoi(char c, char *base);
int		checkbase(char *base);
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
char	*ft_strdup(const char *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
