#include "so_long.h"

static void assets_init(t_data *data);
static void map_init(t_data *data);

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
			print_img_from_map(*data, m_pos.i, m_pos.j);
			if (map.map[m_pos.i][m_pos.j] == PLAYER)
			{
				data->p_pos = get_window_pos(m_pos.i, m_pos.j);
				map.map[m_pos.i][m_pos.j] = GRASS;
			}
			else if (map.map[m_pos.i][m_pos.j] == ENEMY)
			{
				pos = get_window_pos(m_pos.i, m_pos.j);

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


