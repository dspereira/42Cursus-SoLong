#include "so_long.h"

void *get_first_img_player(t_data data);

static void *get_map_img(t_data data, char map_comp)
{
	void *img;

	if (map_comp == GRASS)
		img = get_img(data, GRASS_1);
	else if (map_comp == TREE)
		img = get_img(data, TREE_1);
	else if (map_comp == PLAYER)
		img = get_img(data, P_DOWN_0);
	else if (map_comp == COLLECTIBLE)
		img = get_img(data, COIN_1);
	else if (map_comp == EXIT)
		img = get_img(data, EXIT_1);
	else 
		img = 0;

	return (img);	
}

//criar função que recebe outra por parametro que retorna a imagem

void print_img_from_map(t_data data, int i, int j)
{
	void *p_img;
	void *grass_img;
	t_pos pos;
	t_win win;

	get_window_pos(i, j, &pos);
	win = data.win;
	p_img = get_map_img(data, data.map.map[i][j]);
	grass_img = get_map_img(data, GRASS);
	if (p_img && grass_img)
	{
		mlx_put_image_to_window(win.mlx, win.mlx_win, grass_img, pos.x, pos.y);
		mlx_put_image_to_window(win.mlx, win.mlx_win, p_img, pos.x, pos.y);
	}
}

void print_img(t_data data, t_pos pos, char c_img)
{
	void *p_img;
	t_win win;

	win = data.win;
	p_img = get_map_img(data, c_img);
	if (p_img)
		mlx_put_image_to_window(win.mlx, win.mlx_win, p_img, pos.x, pos.y);
}

void print_img_by_index(t_data data, t_pos pos, int img_index)
{
	void *p_img;
	t_win win;

	win = data.win;
	p_img = get_img(data, img_index);
	if (p_img)
		mlx_put_image_to_window(win.mlx, win.mlx_win, p_img, pos.x, pos.y);
}






// primeira imagem do player
/*
void *get_first_img_player(t_data data)
{
	void *img;
	t_map map;
	int i;
	int j;

	map = data.map;
	get_map_pos(map.p, &i, &j);
	if (map.map[i + 1][j] == TREE)
		return (get_img(data, P_UP_0));
	else if (map.map[i - 1][j] == TREE)
		return (get_img(data, P_DOWN_0));
	else if (map.map[i][j + 1] == TREE)
		return (get_img(data, P_RIGTH_0));
	else if (map.map[i][j - 1] == TREE)
		return (get_img(data, P_LEFT_0));
	else 
		return (get_img(data, P_DOWN_0));
}
*/