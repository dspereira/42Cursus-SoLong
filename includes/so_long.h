/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:35:07 by dsilveri          #+#    #+#             */
/*   Updated: 2022/05/16 16:09:23 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <time.h>
# include <errno.h>
# include <string.h>
# include "../get_next_line/get_next_line.h"

# define STDERR_FD		2
# define STDOUT_FD		1

# define EXT			".ber"

# define COLLECTIBLE	'C'
# define EXIT			'E'
# define PLAYER			'P'
# define GRASS			'0'
# define TREE			'1'
# define ENEMY			'X'

// KEYS for ubuntu linux 

# define KEY_UP			119
# define KEY_DOWN		115
# define KEY_LEFT		97
# define KEY_RIGHT		100
# define KEY_ESC		65307


// KEYS for MAC
/*
# define KEY_UP			13
# define KEY_DOWN		1
# define KEY_LEFT		0
# define KEY_RIGHT		2
# define KEY_ESC		53
*/

# define IMG_SIZE		60

# define MOVE_RANGE		20

# define PLAYER_H		59
# define PLAYER_W		39

# define N_SPRITES		12
# define N_TEXTURES		6

//# define malloc(x) NULL

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum e_textures
{
	GRASS_1 = 0,
	TREE_1,
	COIN_1,
	EXIT_1
};

enum e_sprites
{
	UP_0 = 0,
	UP_1,
	UP_2,
	DOWN_0,
	DOWN_1,
	DOWN_2,
	LEFT_0,
	LEFT_1,
	LEFT_2,
	RIGHT_0,
	RIGHT_1,
	RIGHT_2,
};

typedef struct s_img
{
	char	path[50];
	void	*img;
}	t_img;

typedef struct s_map_pos
{
	int	i;
	int	j;
}	t_map_pos;

typedef struct s_pos
{
	int	x;
	int	y;
	int	sprite;
}	t_pos;

typedef struct s_map
{
	int		length;
	int		height;
	char	**map;
}	t_map;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
}	t_win;

typedef struct s_data
{
	t_map	map;
	t_win	win;
	t_img	textures[N_TEXTURES];
	t_img	player[N_SPRITES];
	t_img	enemy[N_SPRITES];
	t_pos	*e_pos;
	t_pos	p_pos;
	int		n_coins;
	int		n_moves;
	int		n_enemys;
}	t_data;

/* get_map.c */
t_map		*get_map(t_data *data, char *map_path);

/* map_validation.c */
int			map_validation(t_map map);

/* free_map.c */
void		free_map(t_map map);

/* game_init.c */
t_data		game_init(t_data *data);

/* imgs_init.c */
void		imgs_init(t_data *data);

/* hook_call_func.c */
int			key_down(int keycode, t_data *data);
int			key_up(int keycode, t_data *data);
int			enemy_call(t_data *data);
int			end_game(t_data *data);

/* player.c */
int			player_start_move(int keycode, t_data *data);
int			player_stop_move(int keycode, t_data *data);

/* enemy.c */
int			enemy_move(t_data *data);
int			get_number_of_enemys(t_map map);

/* get_enemy_dir.c */
int			get_enemy_dir(t_pos e_pos, t_pos p_pos);

/* game_rules.c */
void		finish_game(void);
int			is_valid_move(t_pos pos, char **map);
int			is_win(t_data data);
int			is_lose(t_data data);

/* game_utils.c */
t_map_pos	get_map_pos(t_pos pos);
t_pos		get_window_pos(int i, int j);
t_pos		*get_corners(t_pos start_pos, t_pos *corners);

/* game_utils2.c */
t_pos		get_new_pos(t_pos pos, int dir, char c);

/* print_img.c */
void		*get_map_img(t_data data, char c);
void		print_img_from_map(t_data data, int i, int j);
void		print_img(t_win win, t_pos pos, void *img);
void		print_all_character(t_data data);
void		print_number_of_moves(t_data data);

/* clean_all_character.c */
void		clean_all_character(t_data data);

/* catch_coin.c */
void		catch_coin(t_data *data);

/* collisions.c */
int			is_collision(t_pos pos, char **map, char c);
int			is_player_collision(t_pos start_p, char **map, char c);
int			enemy_collision(t_pos player, t_pos enemy);
int			is_collision_btw_enemys(t_data data, t_pos new, int enemy_index);

/* alloc_mem.c */
void		save_alloc_mem(t_data *data);
void		free_alloc_mem(void);

/* error_handling.c */
void		*oom_guard(void *p);
int			map_error(int err, char *msg);
int			sys_error(int err);
void		*mlx_error(void *p);

/* utils.c */
char		*ft_itoa(int n);
void		clean_mlx(t_data data);
void		print_msg(int fd, char *str);

#endif