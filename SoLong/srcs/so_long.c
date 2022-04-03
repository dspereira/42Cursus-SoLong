#include "so_long.h"

// função de teste durante o desenvolvimento
void print_map(t_map map)
{
	int i; 
	
	i = 0;
	printf("mapa h: %i\n", map.height);
	printf("mapa l: %i\n", map.length);
	while(i < map.height)
	{
		if (map.map[i])
			printf("%s\n", map.map[i]);
		else 
			printf("\n");
		i++;
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
	data.win.mlx_win = mlx_new_window(data.win.mlx, data.map.length * IMG_SIZE, data.map.height * IMG_SIZE, "SoLong");		
	game_init(&data);
	mlx_hook(data.win.mlx_win, ON_KEYDOWN, 1L<<0, key_control, &data);
	mlx_loop(data.win.mlx);
	return (0);
}
