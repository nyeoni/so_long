/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:56:18 by nkim              #+#    #+#             */
/*   Updated: 2022/01/23 18:57:15 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	printf("close_game\n");
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);

	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game game;
	// int width;
	// int height;
	// void *img;

	if (argc != 2)
		throw_error("ArgError : no / over argument!");
	parse_map(&game, argv[1]);
	start_game(&game);

	// img = mlx_xpm_file_to_image(game.mlx_ptr,"./asset/player.xpm", &width, &height);
	// mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, img, 0, 0);
	// mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, img, 64, 0);
	mlx_hook(game.win_ptr, X_EVNET_KEY_EXIT, 0, &close_game, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
