#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
#include <time.h>
# include <errno.h>
# include <string.h>
#include "../get_next_line/get_next_line.h"

# define STDERR_FD		2

# define EXT			".ber"

# define COLLECTIBLE	'C'
# define EXIT			'E'
# define PLAYER			'P'
# define GRASS			'0'
# define TREE			'1'
# define ENEMY			'X'

// KEYS for ubuntu linux 
/*
# define KEY_UP			119
# define KEY_DOWN		115
# define KEY_LEFT		97
# define KEY_RIGHT		100
# define KEY_ESC		65307
*/
// KEYS for MAC


# define KEY_UP			13
# define KEY_DOWN		1
# define KEY_LEFT		0
# define KEY_RIGHT		2
# define KEY_ESC		53

/*
# define UP				0
# define DOWN			1
# define LEFT			2
# define RIGHT			3
*/

# define IMG_SIZE		60

# define MOVE_RANGE		20

# define PLAYER_SIZE	58

#define PLAYER_H		59
#define PLAYER_W		39

#define PLAYER_H_REAL	59
#define PLAYER_W_REAL	39


# define NO_TYPE 		0
# define TYPE_MAP		1

# define N_SPRITES		12
# define N_TEXTURES		6



//#define malloc(x) NULL

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

enum Index_image
{
	GRASS_1,
	TREE_1,
	COIN_1,
	EXIT_1
};

enum sprite_dir
{
	UP_0,
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
	char path[50];
	void *img;
}	t_img;

typedef struct s_map_pos
{
	int i;
	int j;
}	t_map_pos;

typedef struct s_pos
{
	int x;
	int y;
	int sprite;
}	t_pos;

typedef struct s_map
{
	int length;
	int height;
	char **map;
} t_map;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
}	t_win;

typedef struct s_data
{
	t_map	map;
	t_win	win;
	t_img 	imgs[50];
	t_img 	textures[N_TEXTURES];
	t_img	player[N_SPRITES];
	t_img	enemy[N_SPRITES];
	t_pos 	*e_pos;
	t_pos	p_pos;
	int 	n_coins;
	int 	n_moves;
	int 	n_enemys;
}	t_data;


typedef struct s_alloc_mem
{
	char	**map;
}	t_alloc_mem;


/* get_map.c */
//t_map get_map(char *map_path);
t_map *get_map(t_data *data, char *map_path);


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
void print_img(t_win win, t_pos pos, void *img);
void clean_player(t_data data);

/* game_utils.c */
t_pos *get_player_corners(t_pos start_pos, t_pos *corners);
t_map_pos get_map_pos(t_pos pos);

/* player_move.c */
void update_player_pos(t_data *data, t_pos pos);
void move_player(t_data *data, t_pos p);


/* game_rules.c */
void make_move(t_data *data, int dir);
void finish_game(void);

/* error_handling.c */
void	*oom_guard(void *p);
//void	*oom_guard(void *p, t_data data);

// decidir onde colocar esta função
void *get_img(t_data data, int index);

int end_game(t_data *data);


/* move_character */
void move_character(t_data *data, t_img *imgs, t_pos *pos, int dir);


void move_player1(t_data *data, t_pos p, int dir);

int key_up(int keycode, t_data *data);

int is_valid_move(t_pos pos, char **map);

int enemy_collision(t_pos player, t_pos enemy);


void update_character_pos(t_pos *dst_pos, t_pos src_pos);



//void print_img1(t_win win, t_pos pos, void *img);

void print_player(t_data data, int sprite);
//void print_enemy(t_data data, int sprite);

t_pos get_window_pos(int i, int j);

void print_img_from_map(t_data data, int i, int j);

int enemy_call1(t_data *data);

t_map_pos get_map_pos(t_pos pos);

void imgs_init(t_data *data);

t_pos get_new_pos(t_pos pos, int dir);

int get_number_of_enemys(t_map map);


void print_number_of_moves(t_data data);

char	*ft_itoa(int n);


int enemy_call(t_data *data);

int get_random_direction(t_pos e_pos, t_pos p_pos);
int make_move_2(t_data *data, t_pos *e_pos, int dir);

int	key_down(int keycode, t_data *data);


void player_move(t_data *data, int dir);

int is_win(t_data data);

void *get_map_img(t_data data, char c);

int	player_start_move(int keycode, t_data *data);
int player_stop_move(int keycode, t_data *data);


int move_enemy(t_data *data);

int is_lose(t_data data);

int map_error(int err, char *msg);
int	sys_error(int err);

int is_file_type_ber(char *file);

void get_sprites(enum sprite_dir *i_img, int dir);

int enemy_move(t_data *data);

void clean_all_character(t_data data);
void print_all_character(t_data data);

int is_collision_btw_enemys(t_data data ,t_pos new, int enemy_index);

int get_enemy_dir(t_pos e_pos, t_pos p_pos);

void save_data(void *data);
void clean_data(void);

void	*oom_guard2(void *p);


void	save_alloc_mem(t_data *data);
void	free_alloc_mem(void);

void free_map(t_map map);

void clean_mlx(t_data data);

void *mlx_error(void *p);

#endif