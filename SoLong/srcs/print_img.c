#include "so_long.h"

static void *get_img(t_imgs imgs, char map_comp)
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

void print_img_from_map(t_data data, int i, int j)
{
	void *p_img;
	void *grass_img;
	t_pos pos;
	t_win win;

	get_window_pos(i, j, &pos);
	win = data.win;
	p_img = get_img(data.imgs, data.map.map[i][j]);
	grass_img = get_img(data.imgs, GRASS);
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
	p_img = get_img(data.imgs, c_img);
	if (p_img)
		mlx_put_image_to_window(win.mlx, win.mlx_win, p_img, pos.x, pos.y);
}
