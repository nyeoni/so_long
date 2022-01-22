/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:55:51 by nkim              #+#    #+#             */
/*   Updated: 2022/01/22 18:19:29 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

// Common Lib
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

// My Lib
#include "../lib/libft42/include/libft42.h"
#include "../lib/mlx/mlx.h"

#define TRUE 1
#define FALSE 0

#define X_EVNET_KEY_EXIT 17

// Structures
typedef struct s_map {
	char **map;
	int rows;
	int cols;
	int p_cnt;
	int c_cnt;
	int e_cnt;
}	t_map;

typedef struct s_game
{
	void *mlx_ptr;
	void *win_ptr;
	t_map map;

} t_game;

// Directory functions
// ERROR DIR
void throwError(char *message);

// MAP DIR
// parse_map.c
void parseMap(t_game *game, char *fileName);

// validate_map.c
void extensionValidate(char *fileName);
void charactersValidate(char *line);
void lengthValidate(char *src, int length);
void wallValidate(t_map *map, int row_idx);
void leastValidate(t_map *map);

// UTILS DIR
// FT_POINTER_REALLOC.C
void *ft_ptr_realloc(void *buf, int before_size, int after_size);
char *get_line(int fd);

#endif