/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:55:51 by nkim              #+#    #+#             */
/*   Updated: 2022/01/24 15:52:28 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

// Common Lib
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

// My Lib
#include "../lib/libft42/include/libft42.h"
#include "../lib/mlx/mlx.h"

#define TRUE 1
#define FALSE 0

#define ASSET_PATH "./asset/"


#define PLAYER_NAME "kirby"

#define TILE_SIZE 64

#define X_EVNET_KEY_EXIT 17

// Structures
typedef struct s_sprites {
	void	*img;
	struct s_sprites	*next;
}	t_sprites;

typedef struct s_player
{
	int x;
	int y;
	t_sprites *sprites;
}	t_player;

typedef struct s_tiles {
	void	*wall;
	void	*ground;
	void	*exit;
} t_tiles;

typedef struct s_map
{
	char **map;
	int rows;
	int cols;
	int p_cnt;
	int c_cnt;
	int e_cnt;
}	t_map;

typedef struct s_game
{
	void *mlx_ptr;
	void *win_ptr;
	void *win_bak_ptr;
	t_map map;
	t_tiles tiles;
	t_player player;
	t_sprites *collect;
	t_sprites *exit;
} t_game;

// Directory functions
// ERROR DIR
void throw_error(char *message);

// MAP DIR
// parse_map.c
void parse_map(t_game *game, char *fileName);

// validate_map.c
void valid_extension(char *fileName);
void valid_characters(char *line);
void valid_length(char *src, int length);
void valid_wall(t_map *map, int row_idx);
void valid_least(t_map *map);

// UTILS DIR
// FT_POINTER_REALLOC.C
void *ft_ptr_realloc(void *buf, int before_size, int after_size);
void *ft_make_xpm_img(t_game *game, char *fileName);
char *ft_get_line(int fd);

// GAME DIR
void start_game(t_game *game);

#endif