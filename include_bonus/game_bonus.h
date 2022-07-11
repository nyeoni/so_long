/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:49:59 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 03:52:40 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_BONUS_H
# define GAME_BONUS_H

# include "../lib/mlx/mlx.h"
# include "so_long_bonus.h"

void	init_game(t_game *game);
void	start_game(t_game *game);
int		close_game(t_game *game);

#endif