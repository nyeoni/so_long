/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:49:59 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 04:13:19 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_BONUS_H
# define HOOK_BONUS_H

#include "so_long_bonus.h"

# define KEY_EXIT 17
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_A 0
# define KEY_ESC 53
# define KEY_SPACE 49
# define KEY_B 11

int	loop_hook(t_game *game);
int	key_hook(int keycode, t_game *game);
void	handle_location(t_game *game, int offsetX, int offsetY);

#endif