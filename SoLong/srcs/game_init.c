#include "so_long.h"

static void assets_init(t_data *data);
static void map_init(t_data *data);

void add_img(t_data *data, int i, char *path);
void imgs_init(t_data *data);


t_data game_init(t_data *data)
{
	imgs_init(data);
    map_init(data);
	return (*data);
}

static void map_init(t_data *data)
{
	t_pos pos;
	t_map map;
	t_map_pos m_pos;
	int collect;
	
	map = data->map;
	collect = 0;
	m_pos.i = 0;
	while (m_pos.i < map.height)
	{
		m_pos.j = 0;
		while (m_pos.j < map.length)
		{
			print_img_from_map(*data, m_pos);
			if (map.map[m_pos.i][m_pos.j] == PLAYER)
			{
				update_player_pos(data, *get_window_pos(m_pos.i, m_pos.j, &pos));
				map.map[m_pos.i][m_pos.j] = GRASS;
			}
			else if (map.map[m_pos.i][m_pos.j] == ENEMY)
			{
				get_window_pos(m_pos.i, m_pos.j, &pos);

				//Neste ponto o ponteiro de enimigos já deve estar criado
				data->e_pos = pos;
				map.map[m_pos.i][m_pos.j] = GRASS;
			}
			else if (map.map[m_pos.i][m_pos.j] == COLLECTIBLE)
				collect++;
			m_pos.j++;
		}
		m_pos.i++;
	}
	data->n_coins = collect;
}

void add_img(t_data *data, int i, char *path)
{
	t_win win;
	t_img *img;
	int w;
	int h;

	win = data->win;
	img = data->imgs;
	ft_strlcpy(img[i].path, path, ft_strlen(path) + 1);	
	img[i].img = mlx_xpm_file_to_image(win.mlx, img[i].path, &w, &h);
}

void imgs_init(t_data *data)
{
	int i;

	i = 0;
	add_img(data, i++, "./assets/grass.xpm");
	add_img(data, i++, "./assets/tree.xpm");
	add_img(data, i++, "./assets/coin.xpm");
	add_img(data, i++, "./assets/exit.xpm");
	add_img(data, i++, "./assets/player/p_up_0.xpm");
	add_img(data, i++, "./assets/player/p_up_1.xpm");
	add_img(data, i++, "./assets/player/p_up_2.xpm");
	add_img(data, i++, "./assets/player/p_down_0.xpm");
	add_img(data, i++, "./assets/player/p_down_1.xpm");
	add_img(data, i++, "./assets/player/p_down_2.xpm");
	add_img(data, i++, "./assets/player/p_left_0.xpm");
	add_img(data, i++, "./assets/player/p_left_1.xpm");
	add_img(data, i++, "./assets/player/p_left_2.xpm");
	add_img(data, i++, "./assets/player/p_right_0.xpm");
	add_img(data, i++, "./assets/player/p_right_1.xpm");
	add_img(data, i++, "./assets/player/p_right_2.xpm");
	add_img(data, i++, "./assets/enemy/e_up_0.xpm");
	add_img(data, i++, "./assets/enemy/e_up_1.xpm");
	add_img(data, i++, "./assets/enemy/e_up_2.xpm");
	add_img(data, i++, "./assets/enemy/e_down_0.xpm");
	add_img(data, i++, "./assets/enemy/e_down_1.xpm");
	add_img(data, i++, "./assets/enemy/e_down_2.xpm");
	add_img(data, i++, "./assets/enemy/e_left_0.xpm");
	add_img(data, i++, "./assets/enemy/e_left_1.xpm");
	add_img(data, i++, "./assets/enemy/e_left_2.xpm");
	add_img(data, i++, "./assets/enemy/e_right_0.xpm");
	add_img(data, i++, "./assets/enemy/e_right_1.xpm");
	add_img(data, i++, "./assets/enemy/e_right_2.xpm");


	//add_img(data, i++, "./assets/enemy.xpm");
}

void *get_img(t_data data, int index)
{
	return (data.imgs[index].img);
}