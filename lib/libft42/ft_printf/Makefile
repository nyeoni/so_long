
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 22:59:15 by nkim              #+#    #+#              #
#    Updated: 2021/09/25 11:40:00 by nkim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC_DIR = .
LIBFT = libft.a
LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/$(LIBFT)
INCS = .

AFLAGS = rus

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c print_number.c print_string.c utils.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

clean :
	rm -rf $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean : clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re : fclean all

$(NAME) : $(OBJS) $(LIBFT)
	cp $(LIBFT_LIB) $@
	ar $(AFLAGS) $@ $(OBJS)

# Libft
$(LIBFT) : $(LIBFT_LIB)

$(LIBFT_LIB) :
	make -C $(LIBFT_DIR)

%.o : %.c
	$(CC) $(CFLAGS) -c $?

test : $(NAME)
	$(CC) main.c -L $(SRC_DIR) -l ftprintf

.PHONY : all clean fclean re 
