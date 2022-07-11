/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 22:18:35 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 02:46:33 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_window(t_game *game)
{
	int	x;
	int	y;

	x = game->map.cols;
	y = game->map.rows;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, TILE_SIZE * x, TILE_SIZE * y,
			"KIRBY");
	game->move_status = NONE;
	game->is_running = FALSE;
	game->is_stop = FALSE;
	game->status = ING;
	game->offset = 0;
	game->collect.collections = NULL;
	game->enemy.enemies = NULL;
	game->step = 0;
}

void	init_imgs(t_game *game)
{
	t_tiles		*tiles;
	t_player	*player;

	tiles = &game->tiles;
	player = &game->player;
	tiles->wall = ft_make_xpm_img(game, "wall.xpm");
	tiles->ground = ft_make_xpm_img(game, "ground.xpm");
	tiles->step = ft_make_xpm_img(game, "step.xpm");
	tiles->exit = ft_make_xpm_img(game, "exit.xpm");
	tiles->open_exit = ft_make_xpm_img(game, "open_exit.xpm");
	ft_make_iterable_sprites(game, &player->r_sprites, "rkirby", 10);
	ft_make_iterable_sprites(game, &player->l_sprites, "lkirby", 10);
	ft_make_iterable_sprites(game, &player->r_run_sprites, "run_kirby", 8);
	ft_make_iterable_sprites(game, &player->l_run_sprites, "run_lkirby", 8);
	ft_make_iterable_sprites(game, &player->r_stop_sprites, "stop_kirby", 10);
	ft_make_iterable_sprites(game, &player->l_stop_sprites, "stop_lkirby", 10);
	ft_make_iterable_sprites(game, &player->fire_sprites, "fire_kirby", 8);
	ft_make_iterable_sprites(game, &game->collect.sprites, "star", 6);
	ft_make_iterable_sprites(game, &game->enemy.sprites, "fire", 4);
	game->player.r_inital = game->player.r_sprites;
	game->player.l_inital = game->player.l_sprites;
	game->player.sprites = game->player.r_sprites;
	game->player.initial = game->player.r_sprites;
}

void	init_game(t_game *game)
{
	init_window(game);
	init_imgs(game);
	draw_tiles(game);
	draw_step(game);
	draw_sprites(game);
	draw_enemies(game);
	draw_exit(game);
}

void	start_game(t_game *game)
{
	init_game(game);
	printf("\033[1;33m== Start Game ==\033[0m\n");
}

int	close_game(t_game *game)
{
	printf("END\n");
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(EXIT_SUCCESS);
}
