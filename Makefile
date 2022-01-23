# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 17:00:14 by nkim              #+#    #+#              #
#    Updated: 2022/01/23 19:05:34 by nkim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= so_long

CC						= gcc
CFLAGS					= -Wall -Werror -Wextra
AR						= ar rcs
RM						= rm -f

LIBFT42_DIR				= ./lib/libft42/
LIBFT42_FLAGS				= -L ./$(LIBFT42_DIR) -lft42
LIBFT42_FILE				= $(LIBFT42_DIR)libft42.a

MLX_DIR					= ./lib/mlx/

INCS_DIR				= ./include/
SRCS_DIR				= ./src/

INCS					= -I include
MLX_FLAGS				= -lmlx -framework OpenGL -framework Appkit

PATH_ERROR				= $(SRCS_DIR)error/
PATH_MAP				= $(SRCS_DIR)map/
PATH_UTILS				= $(SRCS_DIR)utils/
PATH_GAME 				= $(SRCS_DIR)game/

SRCS					= $(SRCS_DIR)main.c \
							$(PATH_ERROR)error.c \
							$(PATH_MAP)parse_map.c $(PATH_MAP)validate_map.c \
							$(PATH_UTILS)ft_ptr_realloc.c $(PATH_UTILS)ft_get_line.c $(PATH_UTILS)ft_make_xpm_img\
							$(PATH_GAME)init_game.c
OBJS					= $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	make -C $(LIBFT42_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT42_FLAGS) -I $(INCS_DIR) -L $(MLX_DIR) $(MLX_FLAGS)

all : $(NAME)

clean :
	make -C $(LIBFT42_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS) a.out.dSYM

fclean : clean
	make -C $(LIBFT42_DIR) fclean
	$(RM) $(NAME) a.out.dSYM

re : fclean all

bonus_re : fclean bonus

test :
	make -C $(LIBFT42_DIR)
	make -C $(MLX_DIR)
	$(CC) -g -o $(NAME) $(SRCS) $(LIBFT42_FLAGS) -I $(INCS_DIR) -L $(MLX_DIR) $(MLX_FLAGS)

leak :
	make -C $(LIBFT42_DIR)
	make -C $(MLX_DIR)
	$(CC) -g -fsanitize=address -o $(NAME) $(SRCS) $(LIBFT42_FLAGS) -I $(INCS_DIR) -L $(MLX_DIR) $(MLX_FLAGS)

norm :
	norminette $(SRCS) $(INCS_DIR)*.h

PHONY	: all clean fclean re