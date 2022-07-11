/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:07:36 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 04:14:49 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"
#include "hook_bonus.h"

void	move_key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_D)
	{
		game->move_status = RIGHT;
		game->offset = game->player.x;
		game->player.sprites = game->player.r_sprites;
		game->player.initial = game->player.r_inital;
	}
	else if (keycode == KEY_A)
	{
		game->move_status = LEFT;
		game->offset = game->player.x;
		game->player.sprites = game->player.l_sprites;
		game->player.initial = game->player.l_inital;
	}
	else if (keycode == KEY_W)
	{
		game->move_status = TOP;
		game->offset = game->player.y;
	}
	else if (keycode == KEY_S)
	{
		game->move_status = BOTTOM;
		game->offset = game->player.y;
	}
}

void	run_key_hook(t_game *game)
{
	t_player	player;

	player = game->player;
	if (player.initial == player.r_inital)
		game->player.sprites = game->player.r_run_sprites;
	else
		game->player.sprites = game->player.l_run_sprites;
	game->is_running = TRUE;
}

void	stop_key_hook(t_game *game)
{
	t_player	player;

	player = game->player;
	if (player.initial == player.r_inital)
		game->player.sprites = player.r_stop_sprites;
	else
		game->player.sprites = player.l_stop_sprites;
	game->is_stop = TRUE;
}

int	key_hook(int keycode, t_game *game)
{
	if (game->move_status == NONE && (keycode == KEY_A || keycode == KEY_D
			|| keycode == KEY_S || keycode == KEY_W))
		move_key_hook(keycode, game);
	if (keycode == KEY_ESC)
		close_game(game);
	if (keycode == KEY_SPACE)
		run_key_hook(game);
	if (keycode == KEY_B)
		stop_key_hook(game);
	return (1);
}
