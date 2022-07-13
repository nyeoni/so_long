/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 06:38:50 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 07:06:26 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_bonus.h"
#include "game_bonus.h"
#include "hook_bonus.h"
#include "utils_bonus.h"
#include <stdio.h>

static void	move_player(t_game *game)
{
	draw_partial(game, &draw_partial_tiles);
	draw_exit(game);
	draw_animate_player(game);
	if (game->offset % TILE_SIZE == 0)
		printf("STEP : %d\n", ++(game->step));
	if (game->is_stop)
		game->is_running = FALSE;
	draw_step(game);
}

static void	stop_player(t_game *game)
{
	draw_partial(game, &draw_partial_tiles);
	draw_exit(game);
	draw_animate_player(game);
	if (game->offset % TILE_SIZE == 0)
		draw_init(game);
}

static void	fire_player(t_game *game)
{
	static int	cnt;

	cnt++;
	if (game->status == FAIL && cnt < 8)
	{
		ft_put_img(game, game->player.fire_sprites->img, game->player.x,
			game->player.y);
		game->player.fire_sprites = game->player.fire_sprites->next;
	}
	else
	{
		draw_screen(game);
	}
}

void	handle_player(t_game *game)
{
	static unsigned int	frame;

	if (!(++frame % 864))
		draw_animate_collect(game);
	if (!(frame % 864))
		draw_animate_enemy(game);
	if (!(frame % 288) && game->status)
		fire_player(game);
	else if (!(frame % 288) && game->is_running)
		move_player(game);
	else if (!(frame % 288) && game->is_stop)
		stop_player(game);
	else if (!(frame % 432) && game->move_status != NONE)
	{
		move_player(game);
		if (game->offset % TILE_SIZE == 0)
			draw_init(game);
	}
}
