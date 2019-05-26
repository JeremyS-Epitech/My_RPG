##
## EPITECH PROJECT, 2018
## makefile
## File description:
## compilation of lib
##

NAME = libmy.a

SOURCES =\
	my_printf.c		\
	scan_flags.c		\
	modulo_mod.c		\
	modulo_c.c		\
	modulo_i.c		\
	modulo_s.c		\
	modulo_u.c		\
	modulo_o.c		\
	my_strlen.c		\
	my_atoi.c		\
	my_str_upp_case.c	\
	my_str_low_case.c	\
	my_str_is_alpha.c	\
	my_str_is_num.c		\
	my_putchar.c		\
	my_put_nbr.c		\
	my_putstr.c		\
	my_memset.c		\
	my_strcat.c		\
	my_strcmp.c		\
	my_strstr.c		\
	my_print_array.c	\
	my_putstr_error.c	\
	my_str_to_word_array.c	\

OBJECTS = $(SOURCES:%.c=%.o)

CFLAGS = -W -Wall -Wextra -I../../include

CC	=	gcc

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc -o $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
