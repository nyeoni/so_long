/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:52:11 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 00:25:12 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_exit(t_game *game)
{
	char	*line;
	int		row_idx;
	int		col_idx;

	row_idx = 0;
	while (row_idx < game->map.rows)
	{
		line = game->map.map[row_idx];
		col_idx = 0;
		while (col_idx < game->map.cols)
		{
			if (line[col_idx] == 'E')
			{
				if (game->collect.collections)
					ft_put_img(game, game->tiles.exit, col_idx * TILE_SIZE,
							row_idx * TILE_SIZE);
				else
					ft_put_img(game, game->tiles.open_exit, col_idx * TILE_SIZE,
							row_idx * TILE_SIZE);
			}
			col_idx++;
		}
		row_idx++;
	}
}

void	draw_tiles(t_game *game)
{
	t_map	map;
	char	*line;
	int		row_idx;
	int		col_idx;

	map = game->map;
	row_idx = 0;
	while (row_idx < map.rows)
	{
		line = map.map[row_idx];
		col_idx = 0;
		while (col_idx < map.cols)
		{
			if (line[col_idx] == '1')
				ft_put_img(game, game->tiles.wall, col_idx * TILE_SIZE, row_idx
						* TILE_SIZE);
			else
				ft_put_img(game, game->tiles.ground, col_idx * TILE_SIZE,
						row_idx * TILE_SIZE);
			col_idx++;
		}
		row_idx++;
	}
}

void	draw_enemies(t_game *game)
{
	char	*line;
	int		row_idx;
	int		col_idx;

	row_idx = 0;
	while (row_idx < game->map.rows)
	{
		line = game->map.map[row_idx];
		col_idx = 0;
		while (col_idx < game->map.cols)
		{
			if (line[col_idx] == 'F')
				ft_lstc_add(&game->enemy.enemies,
							col_idx * TILE_SIZE,
							row_idx * TILE_SIZE);
			col_idx++;
		}
		row_idx++;
	}
}

void	draw_sprites(t_game *game)
{
	char	*line;
	int		row_idx;
	int		col_idx;

	row_idx = 0;
	while (row_idx < game->map.rows)
	{
		line = game->map.map[row_idx];
		col_idx = 0;
		while (col_idx < game->map.cols)
		{
			if (line[col_idx] == 'P')
			{
				game->player.x = col_idx * TILE_SIZE;
				game->player.y = row_idx * TILE_SIZE;
				ft_put_img(game, game->player.sprites->img, game->player.x,
						game->player.y);
			}
			else if (line[col_idx] == 'C')
				ft_lstc_add(&game->collect.collections,
							col_idx * TILE_SIZE,
							row_idx * TILE_SIZE);
			col_idx++;
		}
		row_idx++;
	}
}

void	draw_init(t_game *game)
{
	draw_tiles(game);
	draw_step(game);
	draw_animate_collect(game);
	draw_animate_enemy(game);
	draw_exit(game);
	game->player.sprites = game->player.initial;
	ft_put_img(game, game->player.sprites->img, game->player.x, game->player.y);
	game->move_status = NONE;
	game->is_running = FALSE;
	game->is_stop = FALSE;
}
