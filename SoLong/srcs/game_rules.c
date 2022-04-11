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
	data->map.map[i][j] = GRASS;
	return (1);
}

// Função inacabada
int touch_colletible(t_pos pos)
{
	t_pos p;
	t_pos pos_s;
	t_pos pos_e;
	int i;
	int j;

	get_map_matrix_pos(pos, &i, &j);
	get_win_pos(i, j, &p);
	pos_s.x += pos.x + 22;
	pos_s.y += pos.y + 22;
	pos_e.x += pos.x + IMG_SIZE - 22;
	pos_e.y += pos.y + IMG_SIZE - 22;
	if ((pos.x > pos_s.x && pos.x < pos_e.x)
		&& (pos.y > pos_s.y && pos.y < pos_e.y))
		return (1);
	return (0);
}

// Função inacabada
void catch_collectible(t_data *data)
{
	t_pos pos[4];
	int i;

	get_player_corners(data->map.p, pos);
	i = 0;
	while (i < 4)
	{
		if (has_collided(pos[i], data->map.map, COLLECTIBLE))
		{
			if (touch_colletible(pos[i]))
			{

			}
		}
		i++;
	}
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
	{
		clean_coin(data, p[i]);
		data->map.n_collect--;
		printf("coins missing: %i\n", data->map.n_collect);
	}
}

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
