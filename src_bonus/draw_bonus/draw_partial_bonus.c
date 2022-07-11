/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_partial_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:40:29 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 03:54:32 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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