/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_xpm_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:04:18 by nkim              #+#    #+#             */
/*   Updated: 2022/01/23 19:04:34 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void *ft_make_xpm_img(t_game *game, char *fileName) {
	char *path;
	void *img;
	int width;
	int height;

	path = ft_strjoin(ASSET_PATH, fileName);
	img = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	free(path);
	if (!img)
		throw_error("XPM Error : check ASSET_PATH or fileName");
	else if (!(width == TILE_SIZE && height == TILE_SIZE))
		throw_error("TILE SIZE Error : incorrect tile size");

	return (img);
}