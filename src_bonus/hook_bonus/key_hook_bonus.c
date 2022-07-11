/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:07:36 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 06:38:01 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"
#include "hook_bonus.h"

int	key_hook(int keycode, t_game *game)
{
	if (game->status == PLAYING)
		handle_moving(keycode, game);
	if (game->status == NOTSTARTED
		&& keycode == KEY_ENTER)
		start_game(game);
	if ((game->status == FAIL || game->status == SUCCESS)
		&& keycode == KEY_R)
		restart_game(game);
	if (keycode == KEY_ESC)
		close_game(game);
	return (1);
}
