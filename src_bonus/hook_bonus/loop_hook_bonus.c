/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:07:20 by nkim              #+#    #+#             */
/*   Updated: 2022/01/30 02:00:36 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_player(t_game *game)
{
	draw_tiles(game);
	draw_step(game);
	draw_animate_collect(game);
	draw_exit(game);
	draw_animate_player(game);
	draw_animate_enemy(game);
	if (game->offset % TILE_SIZE == 0)
		draw_init(game);
}

int	loop_hook(t_game *game)
{
	static unsigned int	frame;

	if (!(++frame % 500))
	{
		if (game->move_status != NONE)
			move_player(game);
		else
		{
			draw_animate_collect(game);
		}
	}
	else if (!(frame % 600))
		draw_animate_enemy(game);
	return (1);
}
