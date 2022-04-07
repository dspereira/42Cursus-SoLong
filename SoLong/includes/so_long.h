#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
#include "../get_next_line/get_next_line.h"

# define COLLECTIBLE	'C'
# define EXIT			'E'
# define PLAYER			'P'
# define GRASS			'0'
# define TREE			'1'

# define GRASS_PATH 	"./assets/grass.xpm"
# define TREE_PATH 		"./assets/tree.xpm"
# define PLAYER_PATH 	"./assets/player.xpm"
# define COIN_PATH 		"./assets/coin.xpm"

// KEYS for ubuntu linux 
# define KEY_UP			119
# define KEY_DOWN		115
# define KEY_LEFT		97
# define KEY_RIGHT		100
# define KEY_ESC		65307

# define UP				0
# define DOWN			1
# define LEFT			2
# define RIGHT			3

# define IMG_SIZE		60

# define MOVE_RANGE		20

# define PLAYER_SIZE	58


enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_pos
{
	int x;
	int y;
}	t_pos;

typedef struct s_map
{
	t_pos p;
	int length;
	int height;
	char **map;
} t_map;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
}	t_win;

typedef struct s_imgs
{
	void *grass;
	void *tree;
	void *player;
	void *coin;
}	t_imgs; 

typedef struct s_data
{
	t_map	map;
	t_win	win;
	t_imgs	imgs;
}	t_data;

/* get_map.c */
t_map get_map(char *map_path);

/* map_validations.c*/
int map_validation(t_map map);

/* game_init.c */
t_data game_init(t_data *data);

/* key_control.c */
int	key_control(int keycode, t_data *data);

/* game_rules */
int is_valid_move(t_pos pos, char **map);
void move_player(t_data *data, t_pos p);
void clean_player(t_data data);
void print_image(t_data data, int i, int j);
void update_player_pos(t_data *data, int x, int y);
void get_map_matrix_pos(t_pos p, int *i, int *j);
void get_map_matrix_pos_1(int win_pos, int *map_pos);
//int has_collided(t_map map, t_pos pos, char c);
void collect_collectibles(t_data *data);

#endif