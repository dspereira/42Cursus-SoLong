#include "so_long.h"

void *get_first_img_player(t_data data);


// precisa de ser repensado
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
	else if (map_comp == ENEMY)
		img = get_img(data, E_DOWN_0);
	else
		img = 0;

	return (img);	
}

static void *get_map_img1(t_data data, char c)
{
	void *img;

	if (c == GRASS)
		img = data.textures[GRASS_1].img;
	else if (c == TREE)
		img = data.textures[TREE_1].img;
	else if (c == COLLECTIBLE)
		img = data.textures[COIN_1].img;
	else if (c == EXIT)
		img = data.textures[EXIT_1].img;
	else if (c == PLAYER)
		img = data.player[DOWN_0].img;
	else if (c == ENEMY)
		img = data.enemy[DOWN_0].img;
	else
		img = 0;

	return (img);	
}

// precisa de ser repensada
void print_img_from_map(t_data data, t_map_pos m_pos)
{
	t_win	win;
	t_pos	pos;
	char	**map;
	void	*img;
	void	*grass_img;

	map = data.map.map;
	win = data.win;
	get_window_pos(m_pos.i, m_pos.j, &pos);
	img = get_map_img(data, map[m_pos.i][m_pos.j]);
	grass_img = get_map_img(data, GRASS);
	if (img && grass_img)
	{
		if (img != grass_img)
			mlx_put_image_to_window(win.mlx, win.mlx_win, grass_img, pos.x, pos.y);
		mlx_put_image_to_window(win.mlx, win.mlx_win, img, pos.x, pos.y);
	}
}


void print_img_from_map1(t_data data, int i, int j)
{
	t_pos	pos;
	t_win	win;
	char	c;

	c = data.map.map[i][j];
	win = data.win;
	pos = get_window_pos2(i, j);
	if (c != TREE && c != GRASS);
		print_img1(win, pos, get_map_img1(data, GRASS));
	print_img1(win, pos, get_map_img1(data, c));
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

void clean_character(t_data data, t_pos pos)
{
	t_pos a_pos[4];
	t_map_pos m_pos;
	int i;

	get_player_corners(pos, a_pos);
	i = 0;
	while(i < 4)
	{
		m_pos = get_map_pos(a_pos[i]);
		print_img_from_map(data, m_pos);
		i++;
	}
}


//novas funções
void print_img1(t_win win, t_pos pos, void *img)
{
	mlx_put_image_to_window(win.mlx, win.mlx_win, img, pos.x, pos.y);
}


void print_player(t_data data, int sprite)
{
	t_img *player;
	void *img;

	img = data.player[sprite].img;
	print_img1(data.win, data.p_pos, img);

}

void print_enemy(t_data data, int sprite)
{
	t_img *enemy;
	void *img;

	img = data.enemy[sprite].img;
	print_img1(data.win, data.e_pos, img);	
}