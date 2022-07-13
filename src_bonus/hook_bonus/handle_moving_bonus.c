/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moving.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 05:39:58 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 20:42:04 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"
#include "hook_bonus.h"

static void	handle_direction(int keycode, t_game *game)
{
	if (keycode == KEY_D || keycode == KEY_LEFT)
	{
		game->move_status = RIGHT;
		game->offset = game->player.x;
		game->player.sprites = game->player.r_sprites;
		game->player.initial = game->player.r_inital;
	}
	else if (keycode == KEY_A || keycode == KEY_RIGHT)
	{
		game->move_status = LEFT;
		game->offset = game->player.x;
		game->player.sprites = game->player.l_sprites;
		game->player.initial = game->player.l_inital;
	}
	else if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->move_status = TOP;
		game->offset = game->player.y;
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->move_status = BOTTOM;
		game->offset = game->player.y;
	}
}

static void	handle_run(t_game *game)
{
	t_player	player;

	player = game->player;
	if (player.initial == player.r_inital)
		game->player.sprites = game->player.r_run_sprites;
	else
		game->player.sprites = game->player.l_run_sprites;
	game->is_running = TRUE;
}

static void	handle_stop(t_game *game)
{
	t_player	player;

	player = game->player;
	if (player.initial == player.r_inital)
		game->player.sprites = player.r_stop_sprites;
	else
		game->player.sprites = player.l_stop_sprites;
	game->is_stop = TRUE;
}

void	handle_moving(int keycode, t_game *game)
{
	if (game->move_status == NONE)
		handle_direction(keycode, game);
	if (keycode == KEY_SPACE)
		handle_run(game);
	if (keycode == KEY_B)
		handle_stop(game);
}
