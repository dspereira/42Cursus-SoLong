#include "so_long.h"

t_pos *get_player_corners(t_pos start_pos, t_pos *corners);
int has_collided(t_pos p, char **map, char c);
int player_collision_detected(t_pos start_p, char **map, char c);

int is_valid_move(t_pos pos, char **map)
{
	if (player_collision_detected(pos, map, TREE))
		return (0);
	return (1);
}

void get_map_matrix_pos(t_pos p, int *i, int *j)
{
	*i = p.y / IMG_SIZE;
	*j = p.x / IMG_SIZE;
}

t_pos *get_win_pos(int i, int j, t_pos *pos)
{
	pos->x = j * IMG_SIZE;
	pos->y = i * IMG_SIZE;
	return (pos);
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
	else if (map_comp == EXIT)
		img = imgs.exit;
	else 
		img = 0;
	return (img);	
}

void print_image(t_data data, int i, int j)
{
	void *img;
	void *g_img;
	t_pos p;

	get_win_pos(i, j, &p);
	img = get_image(data.imgs, data.map.map[i][j]);
	g_img = get_image(data.imgs, GRASS);
	if (img && g_img)
	{
		mlx_put_image_to_window(data.win.mlx, data.win.mlx_win, g_img, p.x, p.y);
		mlx_put_image_to_window(data.win.mlx, data.win.mlx_win, img, p.x, p.y);
	}
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

void update_player_pos(t_data *data, t_pos pos)
{
	data->map.p.x = pos.x;
	data->map.p.y = pos.y;
}

void move_player(t_data *data, t_pos p)
{
	void *p_img;

	clean_player(*data);
	update_player_pos(data, p);
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

int player_collision_detected(t_pos start_p, char **map, char c)
{
	t_pos pos[4];
	int a;
	int i;
	int j;
	
	get_player_corners(start_p, pos);
	a = 0;
	while (a < 4)
	{
		get_map_matrix_pos(pos[a], &i, &j);
		if (map[i][j] == c)
			return (1);
		a++;		
	}
	return (0);
}

int single_point_collision(t_pos pos, char **map, char c)
{
	int i;
	int j;

	get_map_matrix_pos(pos, &i, &j);
	if (map[i][j] == c)
		return (1);
	return (0);
}


int clean_coin(t_data *data, t_pos p)
{
	int i;
	int j;
	get_map_matrix_pos(p, &i, &j);
	if (data->map.map[i][j] == COLLECTIBLE)
		data->map.map[i][j] = GRASS;
	return (1);
}

int corner_intersection_num(int *corner)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (i < 4)
	{
		if (corner[i])
			n++;
		i++;
	}
	return (n);
}

t_pos get_intersection_point(t_pos *pos, int *conors)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (conors[i])
			break;
		i++;
	}
	return (pos[i]);
}

void catch_collectible(t_data *data)
{
	t_pos pos[4];
	int corners[4];
	int num;
	int i;
	
	get_player_corners(data->map.p, pos);
	i = 0;
	while (i < 4)
	{
		corners[i] = 0;
		if (has_collided(pos[i], data->map.map, COLLECTIBLE))
			corners[i] = 1;
		i++;
	}
	num = corner_intersection_num(corners);
	if (num >= 2)
	{	
		if (num == 2 && ((corners[0] && corners[2]) || (corners[1] && corners[3])))
			return ;
		clean_coin(data, get_intersection_point(pos, corners));
		data->map.n_collect--;
	}
}


/*
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
	{
		clean_coin(data, p[i]);
		data->map.n_collect--;
		printf("coins missing: %i\n", data->map.n_collect);
	}
}
*/

t_pos *get_player_corners(t_pos start_pos, t_pos *corners)
{
	corners[0].x = start_pos.x;
	corners[0].y = start_pos.y;
	corners[1].x = start_pos.x + PLAYER_W;
	corners[1].y = start_pos.y;
	corners[2].x = start_pos.x;
	corners[2].y = start_pos.y + PLAYER_H;
	corners[3].x = start_pos.x + PLAYER_W;
	corners[3].y = start_pos.y + PLAYER_H;
	return (corners);
}

int did_player_win(t_data data)
{
	int n_coins;
	t_pos p[4];
	int i;

	n_coins = data.map.n_collect;
	get_player_corners(data.map.p, p);
	i = 0;
	while (i < 4)
	{
		if (has_collided(p[i], data.map.map, EXIT))
		{
			if (n_coins == 0)
				return (1);
		}
		i++;
	}	
	return (0);
}
