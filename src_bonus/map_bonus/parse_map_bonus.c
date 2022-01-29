/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:50:12 by nkim              #+#    #+#             */
/*   Updated: 2022/01/30 00:19:37 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_map(t_map *map, char *line)
{
	map->map = (char **)malloc(sizeof(char *) * 1);
	map->cols = ft_strlen(line);
	map->rows = 1;
	map->map[0] = line;
	map->p_cnt = 0;
	map->c_cnt = 0;
	map->e_cnt = 0;
}

void	read_map(t_game *game, char *fileName)
{
	int		fd;
	char	*line;
	t_map	*map;

	fd = open(fileName, O_RDONLY);
	if (fd == -1)
		throw_error("FileError : error when open file");
	line = ft_get_line(fd);
	map = &game->map;
	if (line)
		init_map(map, line);
	else
		throw_error("EmptyFileError : file is empty!");
	line = ft_get_line(fd);
	while (line)
	{
		valid_characters(line);
		valid_length(line, game->map.cols);
		map->rows++;
		game->map.map = (char **)ft_ptr_realloc(game->map.map, \
									map->rows - 1, map->rows);
		game->map.map[map->rows - 1] = line;
		line = ft_get_line(fd);
	}
	close(fd);
}

void	count_component(t_map *map)
{
	int		row_idx;
	int		idx;
	char	*row;

	row_idx = 0;
	while (row_idx < map->rows)
	{
		valid_wall(map, row_idx);
		row = map->map[row_idx];
		idx = 0;
		while (idx < map->cols)
		{
			if (row[idx] == 'P')
				map->p_cnt++;
			else if (row[idx] == 'C')
				map->c_cnt++;
			else if (row[idx] == 'E')
				map->e_cnt++;
			idx++;
		}
		row_idx++;
	}
	valid_least(map);
}

void	parse_map(t_game *game, char *fileName)
{
	valid_extension(fileName);
	read_map(game, fileName);
	count_component(&game->map);
}
