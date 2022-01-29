/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:56:18 by nkim              #+#    #+#             */
/*   Updated: 2022/01/29 23:54:48 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		throw_error("ArgError : no / over argument!");
	parse_map(&game, argv[1]);
	start_game(&game);
	mlx_hook(game.win_ptr, KEY_EXIT, 0, &close_game, &game);
	mlx_key_hook(game.win_ptr, &key_hook, &game);
	mlx_loop_hook(game.mlx_ptr, &loop_hook, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
