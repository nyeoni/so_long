/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:44:26 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 03:51:32 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	start_game(t_game *game)
{
	init_game(game);
	draw_tiles(game);
	draw_step(game);
	draw_sprites(game);
	draw_enemies(game);
	draw_exit(game);
	printf("\033[1;33m== Start Game ==\033[0m\n");
}