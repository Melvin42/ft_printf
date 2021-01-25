SRCS	= ft_printf.c \
		  ft_flag_star.c \
		  ft_pars_flags.c \
		  ft_printf_convert.c \
		  ft_printf_convert2.c \
		  ft_printf_string.c \
		  ft_printf_string2.c \
		  ft_printf_addr.c \
		  ft_printf_null_addr.c \
		  ft_printf_int_pos.c \
		  ft_printf_int_neg.c \
		  ft_printf_int_neg2.c \
		  ./printlib/ft_strlen.c \
		  ./printlib/ft_isdigit.c \
		  ./printlib/ft_isspace.c \
		  ./printlib/ft_putchar_fd.c \
		  ./printlib/ft_putstr_fd.c \
		  ./printlib/ft_putnbr_fd.c \
		  ./printlib/ft_atoi.c \
		  ./printlib/ft_atoi_base.c \
		  ./printlib/ft_itoa.c \
		  ./printlib/ft_utoa.c \
		  ./printlib/ft_itoa_base.c \
		  ./printlib/ft_utoa_base.c \
		  ./printlib/ft_ultoa_base.c \
		  ./printlib/ft_strdup.c \
		  ./printlib/ft_strcpy.c \
		  ./printlib/ft_substr.c \

SRCS_BONUS = \

CC = clang

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = libftprintf.a

AR = ar rc

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: ${NAME}

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: .c.o all clean fclean re bonus
