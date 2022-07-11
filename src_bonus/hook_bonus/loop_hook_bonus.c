/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:07:20 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 02:22:37 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_player(t_game *game)
{
	draw_partial(game, &draw_partial_tiles);
	draw_step(game);
	draw_exit(game);
	draw_animate_player(game);
	if (game->is_stop)
		game->is_running = FALSE;
}

void	stop_player(t_game *game)
{
	draw_partial(game, &draw_partial_tiles);
	draw_exit(game);
	draw_animate_player(game);
	if (game->offset % TILE_SIZE == 0)
		draw_init(game);
}

int	loop_hook(t_game *game)
{
	static unsigned int	frame;

	frame++;
	if (!(frame % 864))
	{
		draw_animate_collect(game);
		draw_animate_enemy(game);
	}
	if (!(frame % 288) && game->is_running)
		move_player(game);
	else if (!(frame % 288) && game->is_stop)
		stop_player(game);
	else if (!(frame % 432) && game->move_status != NONE)
	{
		move_player(game);
		if (game->offset % TILE_SIZE == 0)
			draw_init(game);
	}
	return (1);
}
