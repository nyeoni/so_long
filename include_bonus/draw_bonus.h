/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:49:59 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 04:37:43 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_BONUS_H
# define DRAW_BONUS_H

# include "so_long_bonus.h"

void	draw_tiles(t_game *game);
void	draw_step(t_game *game);
void	draw_sprites(t_game *game);
void	draw_exit(t_game *game);
void	draw_enemies(t_game *game);
void	draw_init(t_game *game);

void	draw_animate_player(t_game *game);
void	draw_animate_collect(t_game *game);
void	draw_animate_enemy(t_game *game);

void	draw_partial(t_game *game,
			void (*partial_func)(t_game *, int, int));
void	draw_partial_tiles(t_game *game, int row, int col);

#endif