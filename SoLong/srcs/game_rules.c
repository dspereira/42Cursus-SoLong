#include "so_long.h"

int is_valid_move(t_map map, int x, int y, int d)
{
	int i;
	int j;
	int k;
	int p_offset;

	p_offset = 0;
	if (d == DOWN || d == RIGHT)
		p_offset = PLAYER_SIZE;
	if (d == LEFT || d == RIGHT)
	{
		get_map_matrix_pos(x + p_offset, y, &i, &j);
		get_map_matrix_pos_1(y + PLAYER_SIZE, &k);
		if (map.map[i][j] == TREE || map.map[k][j] == TREE)
			return (0);	
	}
	else 
	{
		get_map_matrix_pos(x, y + p_offset, &i, &j);
		get_map_matrix_pos_1(x + PLAYER_SIZE, &k);
		if (map.map[i][j] == TREE || map.map[i][k] == TREE)
			return (0);		
	}
	return (1);
}

void get_map_matrix_pos(int x, int y, int *i, int *j)
{
	*i = y / IMG_SIZE;
	*j = x / IMG_SIZE;
}

void get_map_matrix_pos_1(int win_pos, int *map_pos)
{
	*map_pos = win_pos / IMG_SIZE;
}

void get_window_pos(int i, int j, int *x, int *y)
{
	*x = j * IMG_SIZE;
	*y = j * IMG_SIZE;
}

void *get_image(t_imgs imgs, char map_comp)
{
	void *img;

	if (map_comp == GRASS)
		img = imgs.grass;
	else if (map_comp == TREE)
		img = imgs.tree;
	else if (map_comp == PLAYER)
		img = imgs.player;
	else if (map_comp == COLLECTIBLE)
		img = imgs.coin;
	else 
		img = 0;
	return (img);	
}

void print_image(t_data data, int i, int j)
{
	void *img;
	int x;
	int y;

	x = j * IMG_SIZE;
	y = i * IMG_SIZE;
	img = get_image(data.imgs, data.map.map[i][j]);
	if (img)
		mlx_put_image_to_window(data.win.mlx, data.win.mlx_win, img, x, y);
}

void clean_player(t_data data)
{
	t_pos pos;
	int i;
	int j;

	pos = data.map.p;
	get_map_matrix_pos(pos.x, pos.y, &i, &j);
	print_image(data, i, j);
	get_map_matrix_pos(pos.x, pos.y + PLAYER_SIZE, &i, &j);
	print_image(data, i, j);
	get_map_matrix_pos(pos.x + PLAYER_SIZE, pos.y, &i, &j);
	print_image(data, i, j);
	get_map_matrix_pos(pos.x + PLAYER_SIZE, pos.y + PLAYER_SIZE, &i, &j);
	print_image(data, i, j);
}

void update_player_pos(t_data *data, int x, int y)
{
	data->map.p.x = x;
	data->map.p.y = y;
}

void move_player(t_data *data, int x, int y)
{
	void *p_img;

	clean_player(*data);
	update_player_pos(data, x, y);
	p_img = get_image(data->imgs, PLAYER);
	mlx_put_image_to_window(data->win.mlx, data->win.mlx_win, p_img, x, y);
}

int has_collided(t_map map, int x_offset, int y_offset, char c)
{
	t_pos pos;
	int i;
	int j;

	pos.x = map.p.x + x_offset;
	pos.y = map.p.y + y_offset;
	get_map_matrix_pos(pos.x, pos.y, &i, &j);
	if (map.map[i][j] == c)
		return (1);
	return (0);
}

int clean_coin(t_data *data, int x, int y)
{
	int i;
	int j;
	get_map_matrix_pos(x, y, &i, &j);
	data->map.map[i][j] = GRASS;
	return (1);
}

void collect_collectibles(t_data *data)
{
	int get_coin;
	t_pos p;

	get_coin = 0;

	if (has_collided(data->map, 0, 0, COLLECTIBLE))
		get_coin = clean_coin(data, data->map.p.x, data->map.p.y);
	else if (has_collided(data->map, PLAYER_SIZE, 0, COLLECTIBLE))
		get_coin = clean_coin(data, data->map.p.x - PLAYER_SIZE, data->map.p.y);
	else if (has_collided(data->map, 0, PLAYER_SIZE, COLLECTIBLE))
		get_coin = clean_coin(data, data->map.p.x, data->map.p.y - PLAYER_SIZE);
	else if (has_collided(data->map, PLAYER_SIZE, PLAYER_SIZE, COLLECTIBLE))
		get_coin = clean_coin(data, data->map.p.x - PLAYER_SIZE, data->map.p.y - PLAYER_SIZE);
}
