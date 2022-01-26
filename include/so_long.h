/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:55:51 by nkim              #+#    #+#             */
/*   Updated: 2022/01/26 17:35:48 by nkim             ###   ########.fr       */
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

#define ASSET_PATH "./assets/"


#define PLAYER_NAME "rkirby"

#define TILE_SIZE 64

#define KEY_EXIT 17
#define KEY_W	13
#define KEY_S	1
#define KEY_D	2
#define KEY_A	0
#define KEY_SPACE 49

#define NONE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 3
#define TOP 4
#define STEP 4

// Structures
typedef struct s_sprites {
	void	*img;
	struct s_sprites	*next;
}	t_sprites;

typedef struct s_component {
	int x;
	int y;
	struct s_component *next;

} t_component;

typedef struct s_player
{
	int x;
	int y;

	t_sprites *initial;
	t_sprites *sprites;

	t_sprites *r_inital;
	t_sprites *l_inital;
	t_sprites *r_sprites;
	t_sprites *l_sprites;
} t_player;

typedef struct s_collect
{
	t_component *collections;
	t_sprites *sprites;
} t_collect;

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
	int move_status;
	int *offset;
	t_map map;
	t_tiles tiles;
	t_player player;
	t_collect collect;
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
void ft_make_iterable_sprites(t_game *game, t_sprites **sprites, char *imgName, int cnt);
char *ft_get_line(int fd);
t_component *ft_lstc_new(int x, int y);
void ft_lstc_add_back(t_component **lst, t_component *new);
int ft_lstc_size(t_component *lst);
void ft_lstc_add(t_component **lst, int x, int y);

// GAME DIR
void start_game(t_game *game);

//draw
void draw_tiles(t_game *game);
void draw_sprites(t_game *game);
void draw_collect(t_game *game);
void draw_exit(t_game *game);
void draw_init(t_game *game);

//animate
void animate_sprites(t_game *game, t_sprites **sprites, int x, int y);

#endif