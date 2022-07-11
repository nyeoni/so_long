/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:49:59 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 04:00:36 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H

# include "../lib/libft/include/libft42.h"
# include "errno.h"
# include "so_long_bonus.h"
# include <fcntl.h>

void	parse_map(t_game *game, char *fileName);
void	valid_extension(char *fileName);
void	valid_characters(char *line);
void	valid_length(char *src, int length);
void	valid_wall(t_map *map, int row_idx);
void	valid_least(t_map *map);

#endif