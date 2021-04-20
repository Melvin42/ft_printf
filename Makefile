SRCS	= ft_printf.c \
		  ft_flags.c \
		  ft_pars_flags.c \
		  ft_printf_convert.c \
		  ft_printf_convert2.c \
		  ft_printf_string.c \
		  ft_printf_string2.c \
		  ft_printf_addr.c \
		  ft_printf_null_addr.c \
		  ft_printf_int_pos.c \
		  ft_printf_int_neg.c \
		  ft_printf_int_plus.c \
		  ft_printf_hexmin.c \
		  ft_printf_hexmin2.c \
		  ft_printf_hexmaj.c \
		  ft_printf_hexmaj2.c \
		  ft_printf_hex_long.c \
		  ft_printf_hex_ll.c \
		  ft_printf_hex_hh.c \
		  ft_printf_modifier.c \
		  ft_printf_short.c \
		  ft_printf_long.c \
		  ft_printf_ll.c \
		  ft_printf_hh.c \

CC = clang

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = libftprintf.a

AR = ar rcs

LIB = libft/libft.a

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

bonus: all

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(AR) $(NAME) $(OBJS) ./libft/*.o

$(LIB):
	make -C ./libft/

clean:
	$(RM) $(OBJS)
	make clean -C ./libft/

fclean:	clean
	$(RM) $(NAME) $(LIB)

re:	fclean all

.PHONY: .c.o all clean fclean re bonus
