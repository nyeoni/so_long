/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 22:18:35 by nkim              #+#    #+#             */
/*   Updated: 2022/01/23 19:05:01 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
						game->tiles.ground, col_idx * TILE_SIZE, row_idx * TILE_SIZE);
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
	game->win_ptr = mlx_new_window(game->mlx_ptr, TILE_SIZE * x, TILE_SIZE * y, "nkim's so_long");
}

void init_tiles(t_game *game) {
	t_tiles *tiles;

	tiles = &game->tiles;
	tiles->wall = ft_make_xpm_img(game, "wall.xpm");
	tiles->ground = ft_make_xpm_img(game, "ground.xpm");
}

void init_game(t_game *game) {
	init_window(game);
	init_tiles(game);
	draw_tiles(game);
}

void start_game(t_game *game) {
	init_game(game);
}