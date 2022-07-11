/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_partial_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:40:29 by nkim              #+#    #+#             */
/*   Updated: 2022/07/11 23:23:20 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_partial_enemy(t_game *game, int row, int col)
{
	t_component	*enemies;

	enemies = game->enemy.enemies;
	while (enemies)
	{
		if (enemies->x == col * TILE_SIZE && enemies->y == row * TILE_SIZE)
		{
			ft_put_img(game, game->tiles.ground, enemies->x, enemies->y);
			ft_put_img(game, game->enemy.sprites->img, col * TILE_SIZE, row
					* TILE_SIZE);
		}
		enemies = enemies->next;
	}
	game->collect.sprites = game->collect.sprites->next;
}

void	draw_partial_collect(t_game *game, int row, int col)
{
	t_component	*collections;

	collections = game->collect.collections;
	while (collections)
	{
		if (collections->x == col * TILE_SIZE && collections->y == row
			* TILE_SIZE)
		{
			ft_put_img(game, game->tiles.ground, collections->x,
					collections->y);
			ft_put_img(game, game->collect.sprites->img, col * TILE_SIZE, row
					* TILE_SIZE);
			game->collect.sprites = game->collect.sprites->next;
		}
		collections = collections->next;
	}
}

void	draw_partial_tiles(t_game *game, int row, int col)
{
	char		**map;
	t_component	*collections;

	map = game->map.map;
	collections = game->collect.collections;
	if (map[row][col] == '1')
		ft_put_img(game, game->tiles.wall, col * TILE_SIZE, row * TILE_SIZE);
	else if (map[row][col] == '0' || map[row][col] == 'P')
		ft_put_img(game, game->tiles.ground, col * TILE_SIZE, row * TILE_SIZE);
	else if (map[row][col] == 'C')
	{
		while (collections)
		{
			if (collections->x == col * TILE_SIZE && collections->y == row
				* TILE_SIZE)
				return ;
			collections = collections->next;
		}
		ft_put_img(game, game->tiles.ground, col * TILE_SIZE, row * TILE_SIZE);
	}
}

void	draw_partial(t_game *game, void (*partial_func)(t_game *, int, int))
{
	int row;
	int col;
	int move_status;

	row = (game->player.y) / TILE_SIZE;
	col = (game->player.x) / TILE_SIZE;
	move_status = game->move_status;
	partial_func(game, row, col);
	if (move_status == RIGHT || move_status == LEFT)
		partial_func(game, row, col + 1);
	else if (move_status == TOP || move_status == BOTTOM)
		partial_func(game, row + 1, col);
}