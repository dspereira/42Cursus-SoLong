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

/* player assets */
# define P_DOWN_0_PATH 	"./assets/player/p_down_0.xpm"
# define P_DOWN_1_PATH 	"./assets/player/p_down_1.xpm"
# define P_DOWN_2_PATH 	"./assets/player/p_down_2.xpm"
# define P_UP_0_PATH 	"./assets/player/p_up_0.xpm"
# define P_UP_1_PATH 	"./assets/player/p_up_1.xpm"
# define P_UP_2_PATH 	"./assets/player/p_up_2.xpm"
# define P_LEFT_0_PATH 	"./assets/player/p_left_0.xpm"
# define P_LEFT_1_PATH 	"./assets/player/p_left_1.xpm"
# define P_LEFT_2_PATH 	"./assets/player/p_left_2.xpm"
# define P_RIGHT_0_PATH "./assets/player/p_right_0.xpm"
# define P_RIGHT_1_PATH "./assets/player/p_right_1.xpm"
# define P_RIGHT_2_PATH "./assets/player/p_right_2.xpm"


# define COIN_PATH 		"./assets/coin.xpm"
# define EXIT_PATH 		"./assets/exit.xpm"

// KEYS for ubuntu linux 
# define KEY_UP			119
# define KEY_DOWN		115
# define KEY_LEFT		97
# define KEY_RIGHT		100
# define KEY_ESC		65307

// KEYS for ubuntu linux 
/*
# define KEY_UP			13
# define KEY_DOWN		1
# define KEY_LEFT		0
# define KEY_RIGHT		2
# define KEY_ESC		53
*/

# define UP				0
# define DOWN			1
# define LEFT			2
# define RIGHT			3

# define IMG_SIZE		60

# define MOVE_RANGE		20

# define PLAYER_SIZE	58

#define PLAYER_H		59
#define PLAYER_W		39

#define PLAYER_H_REAL	59
#define PLAYER_W_REAL	39

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

/*
enum sprites
{
	UP_0, 
	UP_1, 
	UP_2, 
	DOWN_0, 
	DOWN_1, 
	DOWN_2, 
	RIGHT_0,
	RIGHT_1,
	RIGHT_2,
	LEFT_0,
	LEFT_1,
	LEFT_2
};
*/

typedef struct s_pos
{
	int x;
	int y;
}	t_pos;

typedef struct s_map
{
	t_pos p;
	int n_collect;
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
	void *coin;
	void *exit;
	void *player;

}	t_imgs; 

typedef struct s_data
{
	t_map	map;
	t_win	win;
	t_imgs	imgs;
}	t_data;

/* get_map.c */
t_map get_map(char *map_path);
void free_map(t_map map);

/* map_validations.c*/
int map_validation(t_map map);

/* game_init.c */
t_data game_init(t_data *data);

/* key_control.c */
int	key_control(int keycode, t_data *data);

/* catch_coin.c */
void catch_coin(t_data *data);

/* collision.c */
int is_collision(t_pos p, char **map, char c);
int is_player_collision(t_pos start_p, char **map, char c);

/* print_img.c */
void print_img_from_map(t_data data, int i, int j);
void print_img(t_data data, t_pos pos, char c_img);
void clean_player(t_data data);

/* game_utils.c */
void get_map_pos(t_pos pos, int *i, int *j);
t_pos *get_window_pos(int i, int j, t_pos *pos);
t_pos *get_player_corners(t_pos start_pos, t_pos *corners);

/* player_move.c */
void update_player_pos(t_data *data, t_pos pos);
void move_player(t_data *data, t_pos p);


/* game_rules.c */
void make_move(t_data *data, int x_offset, int y_offset);
void finish_game(t_data data);

/* error_handling.c */
void	*oom_guard(void *p);

#endif