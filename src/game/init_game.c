/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 22:18:35 by nkim              #+#    #+#             */
/*   Updated: 2022/01/24 15:58:39 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_make_iterable_sprites(t_game *game, t_sprites **sprites, char *imgName, int cnt) {
	t_sprites *tmp;
	char *fileName;
	char *xpmFile;
	int num;
	int idx;

	*sprites = (t_sprites *)malloc(sizeof(t_sprites));
	tmp = *sprites;
	idx = 0;
	while (idx < cnt) {
		num = '0' + idx;
		fileName = ft_strjoin(imgName, (char *)&num);
		xpmFile = ft_strjoin(fileName, ".xpm");
		tmp->img = ft_make_xpm_img(game, xpmFile);
		printf("file: %s\n", xpmFile);
		printf("%p\n", tmp->img);
		free(fileName);
		free(xpmFile);
		if (idx != cnt - 1)
		{
			tmp->next = (t_sprites *)malloc(sizeof(t_sprites));
			tmp = tmp->next;
		}
		idx++;
	}
	tmp->next = *sprites;
}

void draw_tiles(t_game *game) {
	t_map map;
	char *line;
	int row_idx;
	int col_idx;

	map = game->map;
	row_idx = 0;
	while (row_idx < map.rows)
	{
		line = map.map[row_idx];
		col_idx = 0;
		while (col_idx < map.cols)
		{
			if (line[col_idx] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->tiles.wall, col_idx * TILE_SIZE, row_idx * TILE_SIZE);
			else if (line[col_idx] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->tiles.exit, col_idx * TILE_SIZE, row_idx * TILE_SIZE);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->tiles.ground, col_idx * TILE_SIZE, row_idx * TILE_SIZE);
			col_idx++;
		}
		row_idx++;
	}
	// backup basic win_ptr
	game->win_bak_ptr = game->win_ptr;
}

void draw_sprites(t_game *game) {
	t_map map;
	char *line;
	int row_idx;
	int col_idx;

	map = game->map;
	row_idx = 0;
	while (row_idx < map.rows)
	{
		line = map.map[row_idx];
		col_idx = 0;
		while (col_idx < map.cols)
		{
			if (line[col_idx] == 'P'){
				game->player.x = col_idx * TILE_SIZE;
				game->player.y = row_idx * TILE_SIZE;
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->player.sprites->img, game->player.x, game->player.y);
			}
			else if (line[col_idx] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->collect->img, col_idx * TILE_SIZE, row_idx * TILE_SIZE);
			col_idx++;
		}
		row_idx++;
	}
}


void init_window(t_game *game) {
	int x;
	int y;

	x = game->map.cols;
	y = game->map.rows;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, TILE_SIZE * x, TILE_SIZE * y, "KIRBY");
}

void init_imgs(t_game *game) {
	t_tiles *tiles;
	t_player *player;

	tiles = &game->tiles;
	player = &game->player;
	tiles->wall = ft_make_xpm_img(game, "wall.xpm");
	tiles->ground = ft_make_xpm_img(game, "ground.xpm");
	tiles->exit = ft_make_xpm_img(game, "exit.xpm");

	ft_make_iterable_sprites(game, &player->sprites, PLAYER_NAME, 9);
	ft_make_iterable_sprites(game, &game->collect, "star", 2);
}

void init_game(t_game *game) {
	init_window(game);
	init_imgs(game);
	draw_tiles(game);
	draw_sprites(game);

	printf("%p\n", game->player.sprites->img);
}

void start_game(t_game *game) {
	init_game(game);
}