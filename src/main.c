/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:56:18 by nkim              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/01/22 20:56:26 by nkim             ###   ########.fr       */
=======
/*   Updated: 2022/01/22 18:19:51 by nkim             ###   ########.fr       */
>>>>>>> eb38813ddcde02ffdd8262c1c38e2831ff2c95ea
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
	int width;
	int height;
	void *img;

	if (argc != 2)
		throwError("ArgError : no / over argument!");
	parseMap(&game, argv[1]);

	game.mlx_ptr = mlx_init();												  // connection identifier 생성
	game.win_ptr = mlx_new_window(game.mlx_ptr, 500, 500, "Chloe's Project"); // window identifier 생성
	mlx_pixel_put(game.win_ptr, game.win_ptr, 0, 0, 0x00FF0000);
	img = mlx_xpm_file_to_image(game.mlx_ptr,"./asset/player.xpm", &width, &height);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, img, 0, 0);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, img, 64, 0);
	mlx_hook(game.win_ptr, X_EVNET_KEY_EXIT, 0, &close_game, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
