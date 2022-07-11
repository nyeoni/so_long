/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:56:18 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 06:24:00 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_bonus.h"
#include "game_bonus.h"
#include "hook_bonus.h"
#include "parse_bonus.h"
#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		throw_error("ArgError : no / over argument!");
	parse_map(&game, argv[1]);
	init_game(&game);
	mlx_hook(game.win_ptr, KEY_EXIT, 0, &close_game, &game);
	mlx_key_hook(game.win_ptr, &key_hook, &game);
	mlx_loop_hook(game.mlx_ptr, &loop_hook, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
