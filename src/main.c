/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:56:18 by nkim              #+#    #+#             */
/*   Updated: 2022/01/20 00:29:18 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"

typedef struct s_manager {
	void *mlx_ptr;
	void *win_ptr;
} t_manager;

int	close_game(t_manager *manager)
{
	printf("close_game\n");
	mlx_destroy_window(manager->mlx_ptr, manager->win_ptr);
	exit(0);
}

int	main()
{
	t_manager manager;
	int X_EVNET_KEY_EXIT = 17;
	int width;
	int height;

	void *img;

	manager.mlx_ptr = mlx_init(); // connection identifier 생성
	manager.win_ptr = mlx_new_window(manager.mlx_ptr, 500, 500, "Chloe's Project"); // window identifier 생성
	mlx_pixel_put(manager.win_ptr, manager.win_ptr, 0, 0, 0x00FF0000);
	img = mlx_xpm_file_to_image(manager.mlx_ptr,"./asset/tile.xpm", &width, &height);
	mlx_put_image_to_window(manager.mlx_ptr, manager.win_ptr, img, 0, 0);
	mlx_hook(manager.win_ptr, X_EVNET_KEY_EXIT, 0, &close_game, &manager);
	mlx_loop(manager.mlx_ptr);
	return (0);
}
