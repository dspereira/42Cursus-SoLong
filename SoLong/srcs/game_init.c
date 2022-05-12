#include "so_long.h"

static void	map_init(t_data *data);
static void	player_init(t_data *data, int i, int j);
static void	enemy_init(t_data *data, int i, int j);
static void	coins_init(t_data *data, int i, int j);

t_data	game_init(t_data *data)
{
	imgs_init(data);
	map_init(data);
	print_number_of_moves(*data);
	return (*data);
}

static void	map_init(t_data *data)
{
	t_pos	pos;
	t_map	map;
	int		i;
	int		j;

	map = data->map;
	i = 0;
	data->n_moves = 0;
	data->n_enemys = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.length)
		{
			if (map.map[i][j] == PLAYER)
				player_init(data, i, j);
			else if (map.map[i][j] == ENEMY)
				enemy_init(data, i, j);
			else if (map.map[i][j] == COLLECTIBLE)
				coins_init(data, i, j);
			else
				print_img_from_map(*data, i, j);
			j++;
		}
		i++;
	}
}

static void	player_init(t_data *data, int i, int j)
{
	static int	a = 0;

	data->map.map[i][j] = GRASS;
	print_img_from_map(*data, i, j);
	if (!a)
	{
		data->p_pos = get_window_pos(i, j);
		data->p_pos.sprite = DOWN_0;
		print_img(data->win, data->p_pos, get_map_img(*data, PLAYER));
	}
	a++;
}

static void	enemy_init(t_data *data, int i, int j)
{
	static int	n = 0;

	if (!n)
	{
		data->n_enemys = get_number_of_enemys(data->map);
		if (data->n_enemys)
			data->e_pos = oom_guard(malloc(data->n_enemys * sizeof(t_pos)));
	}
	print_img_from_map(*data, i, j);
	data->e_pos[n] = get_window_pos(i, j);
	data->e_pos[n].sprite = DOWN_0;
	data->map.map[i][j] = GRASS;
	n++;
}

static void	coins_init(t_data *data, int i, int j)
{
	static int	n = 1;

	data->n_coins = n++;
	print_img_from_map(*data, i, j);
}
