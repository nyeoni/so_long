/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 22:18:35 by nkim              #+#    #+#             */
/*   Updated: 2022/01/26 16:13:35 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_window(t_game *game) {
	int x;
	int y;

	x = game->map.cols;
	y = game->map.rows;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, TILE_SIZE * x, TILE_SIZE * y, "KIRBY");
	game->move_status = NONE;
}

void init_imgs(t_game *game) {
	t_tiles *tiles;
	t_player *player;

	tiles = &game->tiles;
	player = &game->player;
	tiles->wall = ft_make_xpm_img(game, "wall.xpm");
	tiles->ground = ft_make_xpm_img(game, "ground.xpm");
	tiles->exit = ft_make_xpm_img(game, "exit.xpm");

	ft_make_iterable_sprites(game, &player->r_sprites, "rkirby", 9);
	ft_make_iterable_sprites(game, &player->l_sprites, "lkirby", 9);
	// collections
	ft_make_iterable_sprites(game, &game->collect.sprites, "star", 2);

	game->player.r_inital = game->player.r_sprites;
	game->player.l_inital = game->player.l_sprites;
	game->player.sprites = game->player.r_sprites;
	game->player.initial = game->player.r_sprites;
}

void init_game(t_game *game) {
	init_window(game);
	init_imgs(game);
	draw_tiles(game);
	draw_sprites(game);
}

void start_game(t_game *game) {
	init_game(game);
}