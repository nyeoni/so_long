/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_xpm_img_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:04:18 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 04:26:15 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"
#include <stdio.h>

void	*ft_make_xpm_img(t_game *game, char *xpmFile)
{
	char	*path;
	void	*img;
	int		width;
	int		height;

	path = ft_strjoin(ASSET_PATH, xpmFile);
	img = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	free(path);
	if (!img)
	{
		printf("fileName: %s\n", xpmFile);
		throw_error("XPM Error : check ASSET_PATH or fileName");
	}
	else if (!(width == TILE_SIZE && height == TILE_SIZE))
		throw_error("TILE SIZE Error : incorrect tile size");
	return (img);
}
