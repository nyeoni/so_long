/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:59:15 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 04:34:01 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_bonus.h"
#include "utils_bonus.h"
#include <stdio.h>

void	handle_wall(t_game *game, int offsetX, int offsetY)
{
	char	**map;
	int		row;
	int		col;

	map = game->map.map;
	row = game->player.y / TILE_SIZE;
	col = game->player.x / TILE_SIZE;
	if (offsetX > 0)
		col++;
	else if (offsetY > 0)
		row++;
	else
	{
		row = (game->player.y + offsetY) / TILE_SIZE;
		col = (game->player.x + offsetX) / TILE_SIZE;
	}
	if (map[row][col] != '1')
	{
		game->player.x = game->player.x + offsetX;
		game->player.y = game->player.y + offsetY;
	}
	if (map[row][col] == '1')
		game->is_stop = TRUE;
}

void	handle_collect(t_game *game, int offsetX, int offsetY)
{
	char	**map;
	int		row;
	int		col;

	map = game->map.map;
	row = (game->player.y + offsetY);
	col = (game->player.x + offsetX);
	if (!(row % TILE_SIZE) && !(col % TILE_SIZE) && map[row / TILE_SIZE][col
		/ TILE_SIZE] == 'C')
	{
		ft_lstc_delete(&game->collect.collections,
			game->player.x + offsetX,
			game->player.y + offsetY);
		ft_put_img(game, game->tiles.ground, game->player.x + offsetX,
			game->player.y + offsetY);
	}
}

void	handle_exit(t_game *game, int offsetX, int offsetY)
{
	char	**map;
	int		row;
	int		col;

	map = game->map.map;
	row = (game->player.y + offsetY);
	col = (game->player.x + offsetX);
	if (!(row % TILE_SIZE) && !(col % TILE_SIZE) && map[row / TILE_SIZE][col
		/ TILE_SIZE] == 'E')
	{
		if (!game->collect.collections)
		{
			game->status = SUCCESS;
			printf("\033[1;32m== Success!! ==\033[0m\n");
		}
	}
}

void	handle_enemy(t_game *game, int offsetX, int offsetY)
{
	char	**map;
	int		row;
	int		col;

	map = game->map.map;
	row = (game->player.y + offsetY);
	col = (game->player.x + offsetX);
	if (!(row % TILE_SIZE) && !(col % TILE_SIZE)
		&& map[row / TILE_SIZE][col / TILE_SIZE] == 'F')
	{
		game->status = FAIL;
		printf("\033[1;31m== FAIL!! ==\033[0m\n");
	}
}

void	handle_location(t_game *game, int offsetX, int offsetY)
{
	handle_wall(game, offsetX, offsetY);
	handle_collect(game, offsetX, offsetY);
	handle_exit(game, offsetX, offsetY);
	handle_enemy(game, offsetX, offsetY);
}
