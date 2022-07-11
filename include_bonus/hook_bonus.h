/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:49:59 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 06:41:27 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_BONUS_H
# define HOOK_BONUS_H

# include "so_long_bonus.h"

# define KEY_EXIT 17
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_A 0
# define KEY_ESC 53
# define KEY_SPACE 49
# define KEY_ENTER 36
# define KEY_B 11
# define KEY_R 15

int		loop_hook(t_game *game);
int		key_hook(int keycode, t_game *game);
void	handle_location(t_game *game, int offsetX, int offsetY);
void	handle_moving(int keycode, t_game *game);
void	handle_player(t_game *game);

#endif