/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:18:15 by nkim              #+#    #+#             */
/*   Updated: 2022/07/15 18:58:28 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_extension(char *fileName)
{
	char	*extension;
	int		diff;

	extension = ft_strrchr(fileName, '.');
	if (!extension)
		throw_error("ExtensionError : file extension is not .ber file!");
	diff = ft_strncmp(extension, ".ber", 4);
	if (diff)
		throw_error("ExtensionError : file extension is not .ber file!");
}

/* This function validate possible characters : 0, 1, C, E, P */
void	valid_characters(char *line)
{
	int	idx;

	idx = 0;
	while (line[idx])
	{
		if (!(line[idx] == '0' || line[idx] == '1' || line[idx] == 'C' \
			|| line[idx] == 'E' || line[idx] == 'P'))
			throw_error("CharactersError :" \
				"not allowed characters in map file!");
		idx++;
	}
	return ;
}

void	valid_length(char *src, int length)
{
	int	src_len;

	src_len = ft_strlen(src);
	if (src_len == length)
		return ;
	else
		throw_error("LengthError : map file row length is different");
}

void	valid_wall(t_map *map, int row_idx)
{
	char	*row;
	int		idx;

	row = map->map[row_idx];
	if (row_idx == 0 || row_idx == map->rows - 1)
	{
		idx = 0;
		while (idx < map->cols)
		{
			if (row[idx] != '1')
				throw_error("WallError : map must be surrounded by walls");
			idx++;
		}
	}
	else
	{
		if (!(row[0] == '1' && row[map->cols - 1] == '1'))
			throw_error("WallError : map must be surrounded by walls");
	}
}

void	valid_least(t_map *map)
{
	if (map->p_cnt != 1)
		throw_error("ComponentError : map must have one starting position");
	else if (map->c_cnt < 1)
		throw_error("ComponentError: map must have at least one collector");
	else if (map->e_cnt < 1)
		throw_error("ComponentError : map must have at least one exit");
}
