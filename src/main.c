/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:56:18 by nkim              #+#    #+#             */
/*   Updated: 2022/01/24 15:06:18 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	printf("close_game\n");
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);

	exit(EXIT_SUCCESS);
}

int walk_player(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 10) {
		while (j < 10) {
			// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			// 						void *img_ptr, int x, int y);
			mlx_put_image_to_window(game->mlx_ptr, game->win_bak_ptr,
									game->player.sprites->img, game->player.x * 6, game->player.y);
			j++;
		}
		i++;
	}
	game->player.sprites = game->player.sprites->next;
	return 1;
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
	mlx_loop_hook(game.mlx_ptr, &walk_player, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
