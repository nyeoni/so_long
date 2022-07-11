/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_step_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 00:47:17 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 04:19:00 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_bonus.h"
#include "hook_bonus.h"
#include "utils_bonus.h"

void	draw_step(t_game *game)
{
	char	*step;

	step = ft_itoa(game->step);
	ft_put_img(game, game->tiles.step, 0, 0);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 25, 37, 0x00000000, step);
}
