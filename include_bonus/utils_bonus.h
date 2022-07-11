/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:49:59 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 06:19:24 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "../lib/libft/include/libft42.h"
# include "../lib/mlx/mlx.h"
# include "error_bonus.h"
# include "so_long_bonus.h"
# include <stdlib.h>

# define ASSET_PATH "./assets/"

void	ft_put_img(t_game *game, void *img, int x, int y);
void	*ft_ptr_realloc(void *buf, int before_size, int after_size);
void	*ft_make_xpm_img(t_game *game, char *fileName);
void	*ft_make_xpm_screen(t_game *game, char *xpmFile);
void	ft_make_iterable_sprites(t_game *game,
			t_sprites **sprites,
			char *imgName,
			int cnt);
char	*ft_get_line(int fd);

void	ft_lstc_add_back(t_component **lst, t_component *new);
int		ft_lstc_size(t_component *lst);
int		ft_lstc_add(t_component **lst, int x, int y);
void	ft_lstc_delete(t_component **lst, int x, int y);

#endif