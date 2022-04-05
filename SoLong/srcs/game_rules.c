#include "so_long.h"

int is_valid_move1(t_map map, int x, int y, int d)
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
		i = y / IMG_SIZE;
		j = (x + p_offset) / IMG_SIZE;
		k = (y + PLAYER_SIZE) / IMG_SIZE;
		if (map.map[i][j] == '1' || map.map[k][j] == '1')
			return (0);	
	}
	else 
	{
		i = (y + p_offset) / IMG_SIZE;
		j = x / IMG_SIZE;
		k = (x + PLAYER_SIZE) / IMG_SIZE;
		if (map.map[i][j] == '1' || map.map[i][k] == '1')
			return (0);		
	}
	return (1);
}

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

void *get_image(t_data data, char map_comp)
{
	void *img;

	if (map_comp == GRASS)
		img = data.imgs.grass;
	else if (map_comp == TREE)
		img = data.imgs.tree;
	else if (map_comp == PLAYER)
		img = data.imgs.player;
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
	img = get_image(data, data.map.map[i][j]);
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
	p_img = get_image(*data, 'P');
	mlx_put_image_to_window(data->win.mlx, data->win.mlx_win, p_img, x, y);
}