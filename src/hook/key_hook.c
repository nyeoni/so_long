/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:07:36 by nkim              #+#    #+#             */
/*   Updated: 2022/01/29 23:42:50 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	printf("STEP : %d\n", ++(game->step));
}

int	key_hook(int keycode, t_game *game)
{
	if (game->move_status == NONE
		&& (keycode == KEY_A || keycode == KEY_D
			|| keycode == KEY_S || keycode == KEY_W))
		move_key_hook(keycode, game);
	if (keycode == KEY_ESC)
		close_game(game);
	return (1);
}
