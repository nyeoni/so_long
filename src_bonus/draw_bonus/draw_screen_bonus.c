/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 05:52:53 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 07:54:13 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_bonus.h"
#include "utils_bonus.h"

void	draw_start_screen(t_game *game)
{
	int	x;
	int	y;

	x = ((game->map.cols / 2.0) - 3) * TILE_SIZE;
	y = ((game->map.rows / 2.0) - 2.5) * TILE_SIZE;
	ft_put_img(game, game->screen.start, x, y);
}

void	draw_fail_screen(t_game *game)
{
	int	x;
	int	y;

	x = ((game->map.cols / 2.0) - 3) * TILE_SIZE;
	y = ((game->map.rows / 2.0) - 2.5) * TILE_SIZE;
	ft_put_img(game, game->screen.fail, x, y);
}

void	draw_success_screen(t_game *game)
{
	int	x;
	int	y;

	x = ((game->map.cols / 2.0) - 3) * TILE_SIZE;
	y = ((game->map.rows / 2.0) - 2.5) * TILE_SIZE;
	ft_put_img(game, game->screen.success, x, y);
}

void	draw_screen(t_game *game)
{
	if (game->status == NOTSTARTED)
		draw_start_screen(game);
	else if (game->status == FAIL)
		draw_fail_screen(game);
	else if (game->status == SUCCESS)
		draw_success_screen(game);
}
