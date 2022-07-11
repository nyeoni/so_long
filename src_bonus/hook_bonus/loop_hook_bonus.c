/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:07:20 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 07:06:10 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_bonus.h"
#include "hook_bonus.h"

int	loop_hook(t_game *game)
{
	if (game->status == NOTSTARTED)
		draw_screen(game);
	else if (game->status == SUCCESS)
		draw_screen(game);
	else
		handle_player(game);
	return (0);
}
