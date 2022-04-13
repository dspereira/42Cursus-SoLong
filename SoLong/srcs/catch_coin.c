#include <so_long.h>

static void clean_coin(t_data *data, t_pos p)
{
	int i;
	int j;
	get_map_pos(p, &i, &j);
	if (data->map.map[i][j] == COLLECTIBLE)
		data->map.map[i][j] = GRASS;
	print_img_from_map(*data, i, j);
	print_img(*data, data->map.p, PLAYER);
}

static int corner_intersection_num(int *corner)
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

static t_pos get_intersection_point(t_pos *pos, int *conors)
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

void catch_coin(t_data *data)
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
		if (is_collision(pos[i], data->map.map, COLLECTIBLE))
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
