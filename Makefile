# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 17:00:14 by nkim              #+#    #+#              #
#    Updated: 2022/01/30 01:25:04 by nkim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= so_long
NAME_BONUS				= so_long_bonus

CC						= gcc
CFLAGS					= -Wall -Werror -Wextra
AR						= ar rcs
RM						= rm -f

LIBFT42_DIR				= ./lib/libft42/
LIBFT42_FLAGS			= -L ./$(LIBFT42_DIR) -lft42
LIBFT42_FILE			= $(LIBFT42_DIR)libft42.a

MLX_DIR					= ./lib/mlx/

INCS_DIR				= ./include/
INCS_DIR_BONUS			= ./include_bonus/
SRCS_DIR				= ./src/
SRCS_DIR_BONUS			= ./src_bonus/

INCS					= -I include
INCS_BONUS_DIR			= -I include_bonus
MLX_FLAGS				= -lmlx -framework OpenGL -framework Appkit

PATH_DRAW				= $(SRCS_DIR)draw/
PATH_HOOK				= $(SRCS_DIR)hook/
PATH_ERROR				= $(SRCS_DIR)error/
PATH_MAP				= $(SRCS_DIR)map/
PATH_UTILS				= $(SRCS_DIR)utils/
PATH_GAME 				= $(SRCS_DIR)game/

PATH_DRAW_BONUS			= $(SRCS_DIR_BONUS)draw_bonus/
PATH_HOOK_BONUS			= $(SRCS_DIR_BONUS)hook_bonus/
PATH_ERROR_BONUS		= $(SRCS_DIR_BONUS)error_bonus/
PATH_MAP_BONUS			= $(SRCS_DIR_BONUS)map_bonus/
PATH_UTILS_BONUS		= $(SRCS_DIR_BONUS)utils_bonus/
PATH_GAME_BONUS			= $(SRCS_DIR_BONUS)game_bonus/

SRCS					= $(SRCS_DIR)main.c \
						$(PATH_ERROR)error.c \
						$(PATH_MAP)parse_map.c $(PATH_MAP)validate_map.c \
						$(PATH_UTILS)ft_ptr_realloc.c $(PATH_UTILS)ft_get_line.c $(PATH_UTILS)ft_make_xpm_img.c $(PATH_UTILS)ft_make_iterable_sprites.c \
						$(PATH_UTILS)ft_lst_component.c $(PATH_UTILS)ft_put_img.c \
						$(PATH_GAME)game.c \
						$(PATH_DRAW)draw.c $(PATH_DRAW)draw_animate.c \
						$(PATH_HOOK)key_hook.c $(PATH_HOOK)loop_hook.c $(PATH_HOOK)handlers.c

SRCS_BONUS				= $(SRCS_DIR_BONUS)main_bonus.c \
						$(PATH_ERROR_BONUS)error_bonus.c \
						$(PATH_MAP_BONUS)parse_map_bonus.c $(PATH_MAP_BONUS)validate_map_bonus.c \
						$(PATH_UTILS_BONUS)ft_ptr_realloc_bonus.c $(PATH_UTILS_BONUS)ft_get_line_bonus.c \
						$(PATH_UTILS_BONUS)ft_make_xpm_img_bonus.c $(PATH_UTILS_BONUS)ft_put_img_bonus.c\
						$(PATH_UTILS_BONUS)ft_make_iterable_sprites_bonus.c \
						$(PATH_UTILS_BONUS)ft_lst_component_bonus.c \
						$(PATH_GAME_BONUS)game_bonus.c \
						$(PATH_DRAW_BONUS)draw_bonus.c $(PATH_DRAW_BONUS)draw_animate_bonus.c \
						$(PATH_DRAW_BONUS)draw_step_bonus.c \
						$(PATH_HOOK_BONUS)key_hook_bonus.c $(PATH_HOOK_BONUS)loop_hook_bonus.c \
						$(PATH_HOOK_BONUS)handlers_bonus.c

OBJS					= $(SRCS:.c=.o)
OBJS_BONUS				= $(SRCS_BONUS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -I $(INCS_DIR_BONUS) -o $@ -c $?

$(NAME) : $(OBJS)
	make -C $(LIBFT42_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT42_FLAGS) -I $(INCS_DIR) -L $(MLX_DIR) $(MLX_FLAGS)

all : $(NAME)

clean :
	make -C $(LIBFT42_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS) $(OBJS_BONUS) so_long.dSYM

fclean : clean
	make -C $(LIBFT42_DIR) fclean
	$(RM) $(NAME) $(NAME_BONUS) so_long.dSYM

re : fclean all

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	make -C $(LIBFT42_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT42_FLAGS) -I $(INCS_DIR_BONUS) -L $(MLX_DIR) $(MLX_FLAGS)

bonus_re : fclean bonus

test :
	make -C $(LIBFT42_DIR)
	make -C $(MLX_DIR)
	$(CC) -g3 -o $(NAME) $(SRCS) $(LIBFT42_FLAGS) -I $(INCS_DIR) -L $(MLX_DIR) $(MLX_FLAGS)

leak :
	make -C $(LIBFT42_DIR)
	make -C $(MLX_DIR)
	$(CC) -g3 -fsanitize=address -o $(NAME) $(SRCS) $(LIBFT42_FLAGS) -I $(INCS_DIR) -L $(MLX_DIR) $(MLX_FLAGS)

bonus_leak :
	make -C $(LIBFT42_DIR)
	make -C $(MLX_DIR)
	$(CC) -g3 -fsanitize=address -o $(NAME_BONUS) $(SRCS_BONUS) $(LIBFT42_FLAGS) -I $(INCS_DIR_BONUS) -L $(MLX_DIR) $(MLX_FLAGS)

norm :
	norminette $(SRCS) $(INCS_DIR)*.h

PHONY	: all clean fclean re bonus