#include "so_long.h"


void clean_enemy(t_data data)
{
	t_pos p[4];
	int i;
	int j;
	int a;

	get_player_corners(data.e_pos, p);
	a = 0;
	while(a < 4)
	{
		get_map_pos(p[a], &i, &j);
		print_img_from_map(data, i, j);
		a++;
	}
}

void move_enemy(t_data *data, t_pos p)
{
	clean_enemy(*data);
	data->e_pos = p;
	print_img(*data, p, ENEMY);

}

int make_move_1(t_data *data, int x_offset, int y_offset)
{
	t_pos p;

	p.x = data->e_pos.x + x_offset;
	p.y = data->e_pos.y + y_offset;
	if (is_valid_move(p, data->map.map))
	{
		move_enemy(data, p);
		return (1);
	}
	return (0);
}

int time_counter(int n_sec)
{
	static unsigned long time_actual = 0;
	static unsigned long time_buff = 0;

	time_actual = time(NULL);
	if (time_actual - time_buff >= n_sec)
	{
		time_buff = time(NULL);
		return (1);
	}
	return (0);
}


int enemy_call(t_data *data)
{
	int r;
	int x;
	int y;
	int m;
	static int i = 0;

	x = 0;
	y = 0;
	r = 0;
	m = 0;
	i++;
	if (i >= 20000)
	{
			srand(time(NULL) + i);
			r = rand() % 4;
			if (r == 0)
			{
				if (data->map.p.x < data->e_pos.x)
					x = -20;
				else 
					x = 20;
			}
			else if(r == 1)
			{
				if (data->map.p.y < data->e_pos.y)
					y = -20;
				else 
					y = 20;
			}
			else if (r >= 2)
			{
				srand(time(NULL)+ i);
				r = rand() % 4;
				if (r == 0)
					x = -20;
				else if (r == 1)
					x = 20;
				else if (r == 2)
					y = -20;
				else if (r == 3)
					y = 20;
			}
			m = make_move_1(data, x, y);
			//printf("valor x: %i y: %i\n", x, y);
			//printf("direction: %i\n", r);
			if (m)
				i = 0;
	
		if (enemy_collision(data->map.p, data->e_pos))
		printf("INTERSETOU !\n");
	}

}

int main(int argc, char **argv)
{
	t_map 	map;
	t_imgs	imgs;
	t_win	win;
	t_data	data;

	if (argc != 2)
	{
		printf("Wrong parmeters: You have to indicate the path of map\n");
		return (0);
	}
	data.map = get_map(argv[1]);
	data.win.mlx = mlx_init();
	if (data.win.mlx == 0)
	{
		printf("erro mlx\n");
		return (1);
	}	
	data.win.mlx_win = mlx_new_window(data.win.mlx, data.map.length * IMG_SIZE, data.map.height * IMG_SIZE, "SoLong");		
	game_init(&data);
	mlx_hook(data.win.mlx_win, ON_KEYDOWN, 1L<<0, key_control, &data);
	mlx_hook(data.win.mlx_win, ON_KEYUP, 1L<<1, key_up, &data);
	mlx_loop_hook(data.win.mlx, enemy_call, &data);
	mlx_loop(data.win.mlx);
	return (0);
}
