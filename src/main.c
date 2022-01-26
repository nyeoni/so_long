/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:56:18 by nkim              #+#    #+#             */
/*   Updated: 2022/01/26 17:36:02 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	printf("close_game\n");
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);

	exit(EXIT_SUCCESS);
}

void draw_animate_player(t_game *game)
{
	if (game->move_status == RIGHT)
		game->player.x += STEP;
	else if (game->move_status == LEFT)
		game->player.x -= STEP;
	else if (game->move_status == TOP)
		game->player.y -= STEP;
	else if (game->move_status == BOTTOM)
		game->player.y += STEP;

	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->player.sprites->img, game->player.x, game->player.y);
	game->player.sprites = game->player.sprites->next;
}

void draw_player(t_game *game)
{
	static unsigned int frame;

	if (!(++frame % 500))
	{
		draw_tiles(game);
		draw_collect(game);
		draw_animate_player(game);
		if (*game->offset % TILE_SIZE == 0)
			draw_init(game);
	}
}

int loop_hook(t_game *game)
{
	if (game->move_status != NONE)
		draw_player(game);
	else
		draw_collect(game);
	return 1;
}

int key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_D)
	{
		game->move_status = RIGHT;
		game->offset = &game->player.x;
		game->player.sprites = game->player.r_sprites;
		game->player.initial = game->player.r_inital;
		// game->direction = RIGHT;
	}
	else if (keycode == KEY_A)
	{
		game->move_status = LEFT;
		game->offset = &game->player.x;
		game->player.sprites = game->player.l_sprites;
		game->player.initial = game->player.l_inital;
		// game->direction = LEFT;
	}
	else if (keycode == KEY_W)
	{
		game->move_status = TOP;
		game->offset = &game->player.y;
	}
	else if (keycode == KEY_S)
	{
		game->move_status = BOTTOM;
		game->offset = &game->player.y;
	}
	return 1;
}

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		throw_error("ArgError : no / over argument!");
	parse_map(&game, argv[1]);
	start_game(&game);

	mlx_hook(game.win_ptr, KEY_EXIT, 0, &close_game, &game);
	mlx_key_hook(game.win_ptr, &key_hook, &game);
	mlx_loop_hook(game.mlx_ptr, &loop_hook, &game);
	mlx_loop(game.mlx_ptr);

	// TODO : 전체 메모리 다 프리하는 메소드 필요할듯
	return (0);
}
