/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:55:51 by nkim              #+#    #+#             */
/*   Updated: 2022/07/12 04:17:33 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define TRUE 1
# define FALSE 0

# define TILE_SIZE 64
# define MAX_OFFSET 6400

# define NONE 0
# define LEFT 1
# define RIGHT 2
# define BOTTOM 3
# define TOP 4

typedef enum s_status
{
	ING,
	FAIL,
	SUCCESS
}						t_status;

// Structures
typedef struct s_sprites
{
	void				*img;
	struct s_sprites	*next;
}						t_sprites;

typedef struct s_player
{
	int					x;
	int					y;

	t_sprites			*initial;
	t_sprites			*sprites;

	t_sprites			*r_inital;
	t_sprites			*l_inital;
	t_sprites			*r_sprites;
	t_sprites			*l_sprites;
	t_sprites			*r_run_sprites;
	t_sprites			*l_run_sprites;
	t_sprites			*r_stop_sprites;
	t_sprites			*l_stop_sprites;
	t_sprites			*fire_sprites;
}						t_player;

typedef struct s_component
{
	int					x;
	int					y;
	struct s_component	*next;

}						t_component;

typedef struct s_collect
{
	t_component			*collections;
	t_sprites			*sprites;
}						t_collect;

typedef struct s_enemy
{
	t_component			*enemies;
	t_sprites			*sprites;
}						t_enemy;

typedef struct s_tiles
{
	void				*wall;
	void				*ground;
	void				*step;
	void				*exit;
	void				*open_exit;
}						t_tiles;

typedef struct s_map
{
	char				**map;
	int					rows;
	int					cols;
	int					p_cnt;
	int					c_cnt;
	int					e_cnt;
}						t_map;

typedef struct s_game
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					move_status;
	int					is_running;
	int					is_stop;
	int					offset;
	int					step;
	t_status			status;
	t_map				map;
	t_tiles				tiles;
	t_player			player;
	t_collect			collect;
	t_enemy				enemy;
}						t_game;

#endif
