/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_iterable_sprites_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:49:45 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 04:05:09 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	ft_make_iterable_sprites(t_game *game,
								t_sprites **sprites,
								char *imgName,
								int cnt)
{
	t_sprites	*tmp;
	char		*file_name;
	char		*xpm_file;
	int			num;
	int			idx;

	*sprites = (t_sprites *)malloc(sizeof(t_sprites));
	tmp = *sprites;
	idx = 0;
	while (idx < cnt)
	{
		num = '0' + idx;
		file_name = ft_strjoin(imgName, (char *)&num);
		xpm_file = ft_strjoin(file_name, ".xpm");
		tmp->img = ft_make_xpm_img(game, xpm_file);
		free(file_name);
		free(xpm_file);
		if (idx != cnt - 1)
		{
			tmp->next = (t_sprites *)malloc(sizeof(t_sprites));
			tmp = tmp->next;
		}
		idx++;
	}
	tmp->next = *sprites;
}
