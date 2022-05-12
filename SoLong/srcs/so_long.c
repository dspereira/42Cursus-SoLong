#include "so_long.h"

int finish_game1(t_data *data)
{
	//free_map(data->map);
	//free(data.win.mlx);
	exit(0);
	return (0);	
}

int main(int argc, char **argv)
{
	t_map 	map;
	t_img	imgs;
	t_win	win;
	t_data	data;

	if (argc != 2)
	{
		printf("Wrong parmeters: You have to indicate the path of map\n");
		return (0);
	}
	data.map.map = 0;
	data.e_pos = 0;
	save_alloc_mem(&data);
	get_map(&data, argv[1]);
	data.win.mlx = mlx_init();
	if (data.win.mlx == 0)
	{
		printf("erro mlx\n");
		return (1);
	}
	data.win.mlx_win = mlx_new_window(data.win.mlx, data.map.length * IMG_SIZE, data.map.height * IMG_SIZE, "SoLong");		
	game_init(&data);
	mlx_hook(data.win.mlx_win, ON_KEYDOWN, 1L<<0, key_down, &data);
	mlx_hook(data.win.mlx_win, ON_KEYUP, 1L<<1, key_up, &data);
	mlx_loop_hook(data.win.mlx, enemy_call, &data);
	mlx_hook(data.win.mlx_win, ON_DESTROY, 0, finish_game1, &data);
	mlx_loop(data.win.mlx);
	return (0);
}
