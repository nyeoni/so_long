/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_iterable_sprites.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:49:45 by nkim              #+#    #+#             */
/*   Updated: 2022/01/26 15:49:59 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_make_iterable_sprites(t_game *game, t_sprites **sprites, char *imgName, int cnt) {
	t_sprites *tmp;
	char *fileName;
	char *xpmFile;
	int num;
	int idx;

	*sprites = (t_sprites *)malloc(sizeof(t_sprites));
	tmp = *sprites;
	idx = 0;
	while (idx < cnt) {
		num = '0' + idx;
		fileName = ft_strjoin(imgName, (char *)&num);
		xpmFile = ft_strjoin(fileName, ".xpm");
		tmp->img = ft_make_xpm_img(game, xpmFile);
		free(fileName);
		free(xpmFile);
		if (idx != cnt - 1)
		{
			tmp->next = (t_sprites *)malloc(sizeof(t_sprites));
			tmp = tmp->next;
		}
		idx++;
	}
	tmp->next = *sprites;
}