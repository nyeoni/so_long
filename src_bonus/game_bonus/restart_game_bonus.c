/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restart_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 06:00:04 by nkim              #+#    #+#             */
/*   Updated: 2022/07/15 19:44:11 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"
#include "draw_bonus.h"
#include <stdio.h>
#include <stdlib.h>

void	free_enemies(t_component *enemies)
{
	t_component	*tmp;

	while (enemies)
	{
		tmp = enemies;
		enemies = enemies->next;
		free(tmp);
	}
}

void	free_collections(t_component *collections)
{
	t_component	*tmp;

	while (collections)
	{
		tmp = collections;
		collections = collections->next;
		free(tmp);
	}
}

void	free_game(t_game *game)
{
	free_collections(game->collect.collections);
	free_enemies(game->enemy.enemies);
}

void	restart_game(t_game *game)
{
	free_game(game);
	init_props(game);
	draw_tiles(game);
	draw_step(game);
	draw_sprites(game);
	draw_enemies(game);
	draw_exit(game);
	printf("\033[1;33m== Restart Game ==\033[0m\n");
	game->status = PLAYING;
	game->step = 0;
}
