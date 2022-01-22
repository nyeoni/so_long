/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:50:12 by nkim              #+#    #+#             */
/*   Updated: 2022/01/22 20:17:04 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void initMap(t_map *map, char *line) {
	map->map = (char **)malloc(sizeof(char *) * 1);
	map->cols = ft_strlen(line);
	map->rows = 1;
	map->map[0] = line;
	map->p_cnt = 0;
	map->c_cnt = 0;
	map->e_cnt = 0;
}

void readMap(t_game *game, char *fileName) {
	int fd;
	char *line;
	t_map *map;

	fd = open(fileName, O_RDONLY);
	if (fd == -1)
		throwError("FileError : error when open file");
	line = get_line(fd);
	map = &game->map;
	if (line)
		initMap(map, line);
	else
		throwError("EmptyFileError : file is empty!");
	line = get_line(fd);
	while (line)
	{
		charactersValidate(line);
		lengthValidate(line, game->map.cols);
		map->rows++;
		game->map.map = (char **)ft_ptr_realloc(game->map.map, map->rows - 1, map->rows);
		game->map.map[map->rows - 1] = line;
		line = get_line(fd);
	}
	close(fd);
}

void countComponent(t_map *map)
{
	int row_idx;
	int idx;
	char *row;

	row_idx = 0;
	while (row_idx < map->rows) {
		wallValidate(map, row_idx);
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
	leastValidate(map);
}

void parseMap(t_game *game, char *fileName) {
	extensionValidate(fileName);
	readMap(game, fileName);
	countComponent(&game->map);

	// check map parsing
	printf("cols : %d\n", game->map.cols);
	printf("rows : %d\n", game->map.rows);
	printf("p_cnt : %d\n", game->map.p_cnt);
	printf("c_cnt : %d\n", game->map.c_cnt);
	printf("e_cnt : %d\n", game->map.e_cnt);
	int i = 0;
	while (i < game->map.rows)
	{
		printf("%s\n", game->map.map[i]);
		i++;
	}
}
