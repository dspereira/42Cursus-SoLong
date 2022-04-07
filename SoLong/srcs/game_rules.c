#include "so_long.h"

t_pos *get_player_corners(t_pos start_pos, t_pos *corners);
int has_collided(t_pos p, char **map, char c);

int is_valid_move(t_pos pos, char **map)
{
	t_pos p[4];
	int i;

	get_player_corners(pos, p);
	i = 0;
	while (i < 4)
	{
		if (has_collided(p[i], map, TREE))
			return (0);
		i++;
	}
	return (1);
}

void get_map_matrix_pos(t_pos p, int *i, int *j)
{
	*i = p.y / IMG_SIZE;
	*j = p.x / IMG_SIZE;
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
	t_pos p[4];
	int i;
	int j;
	int a;

	get_player_corners(data.map.p, p);
	a = 0;
	while(a < 4)
	{
		get_map_matrix_pos(p[a], &i, &j);
		print_image(data, i, j);
		a++;
	}
}

void update_player_pos(t_data *data, int x, int y)
{
	data->map.p.x = x;
	data->map.p.y = y;
}

void move_player(t_data *data, t_pos p)
{
	void *p_img;

	clean_player(*data);
	update_player_pos(data, p.x, p.y);
	p_img = get_image(data->imgs, PLAYER);
	mlx_put_image_to_window(data->win.mlx, data->win.mlx_win, p_img, p.x, p.y);
}


int has_collided(t_pos p, char **map, char c)
{
	int i;
	int j;

	get_map_matrix_pos(p, &i, &j);
	if (map[i][j] == c)
		return (1);
	return (0);
}

int clean_coin(t_data *data, t_pos p)
{
	int i;
	int j;
	get_map_matrix_pos(p, &i, &j);
	data->map.map[i][j] = GRASS;
	return (1);
}


void collect_collectibles(t_data *data)
{
	t_pos p[4];
	int i;

	get_player_corners(data->map.p, p);
	i = 0;
	while (i < 4)
	{
		if (has_collided(p[i], data->map.map, COLLECTIBLE))
			break;
		i++;
	}
	if (i < 4)
		clean_coin(data, p[i]);
}

t_pos *get_player_corners(t_pos start_pos, t_pos *corners)
{
	corners[0].x = start_pos.x;
	corners[0].y = start_pos.y;
	corners[1].x = start_pos.x + PLAYER_SIZE;
	corners[1].y = start_pos.y;
	corners[2].x = start_pos.x;
	corners[2].y = start_pos.y + PLAYER_SIZE;
	corners[3].x = start_pos.x + PLAYER_SIZE;
	corners[3].y = start_pos.y + PLAYER_SIZE;
	return (corners);
}