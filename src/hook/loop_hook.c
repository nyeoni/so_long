/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:07:20 by nkim              #+#    #+#             */
/*   Updated: 2022/01/29 18:25:05 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_player(t_game *game)
{
	draw_tiles(game);
	draw_animate_collect(game);
	draw_exit(game);
	draw_animate_player(game);
	if (game->offset % TILE_SIZE == 0)
		draw_init(game);
}

int loop_hook(t_game *game)
{
	static unsigned int frame;

	if (!(++frame % 500))
	{
		// mlx_string_put(game->mlx_ptr, game->win_ptr, 30, 30, 0xffffffff, "100");
		if (game->move_status != NONE)
			move_player(game);
		else
			draw_animate_collect(game);
	}
	return 1;
}