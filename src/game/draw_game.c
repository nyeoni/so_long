/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:52:11 by nkim              #+#    #+#             */
/*   Updated: 2022/01/26 17:36:34 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_exit(t_game *game) {
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
			if (line[col_idx] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
						game->tiles.exit, col_idx * TILE_SIZE, row_idx * TILE_SIZE);
			col_idx++;
		}
		row_idx++;
	}
}

void draw_collect(t_game *game) {
	t_component *collections;

	collections = game->collect.collections;
	while (collections)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->tiles.ground, collections->x, collections->y);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->collect.sprites->img, collections->x, collections->y);
		collections = collections->next;
	}
	game->collect.sprites = game->collect.sprites->next;
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
			else if (line[col_idx] == 'E') // 여기에 나중에 열리면 다른 이미지 줄 것
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
						game->tiles.exit, col_idx * TILE_SIZE, row_idx * TILE_SIZE);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
						game->tiles.ground, col_idx * TILE_SIZE, row_idx * TILE_SIZE);
			col_idx++;
		}
		row_idx++;
	}
}

void draw_sprites(t_game *game) {
	char *line;
	int row_idx;
	int col_idx;

	row_idx = 0;
	while (row_idx < game->map.rows)
	{
		line = game->map.map[row_idx];
		col_idx = 0;
		while (col_idx < game->map.cols)
		{
			if (line[col_idx] == 'P'){
				game->player.x = col_idx * TILE_SIZE;
				game->player.y = row_idx * TILE_SIZE;
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
							game->player.sprites->img, game->player.x, game->player.y);
			}
			else if (line[col_idx] == 'C')
				ft_lstc_add(&game->collect.collections,
							col_idx * TILE_SIZE, row_idx * TILE_SIZE);
			col_idx++;
		}
		row_idx++;
	}

	// printf("---------test---------\n");
	// int cnt = ft_lstc_size(game->collect.collections);
	// printf("collection cnt: %d\n", cnt);
}

void draw_init(t_game *game)
{
	draw_tiles(game);
	draw_collect(game);
	game->player.sprites = game->player.initial;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player.sprites->img, game->player.x, game->player.y);
	game->move_status = NONE;
}