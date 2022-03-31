#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*img1;
	void	*img2;
	void	*img3;
	char	*relative_path = "./assets/grass1.xpm";
	char	*relative_path1 = "./assets/multiple_three.xpm";
	char	*relative_path2 = "./assets/multiple_three1.xpm";
	char	*relative_path3 = "./assets/multiple_three2.xpm";
	int		img_width;
	int		img_height;
	t_map 	map;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "SoLong");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	img1 = mlx_xpm_file_to_image(mlx, relative_path1, &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, relative_path2, &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, relative_path3, &img_width, &img_height);

	printf("imagem size: %i x %i\n", img_width, img_height);

	
	mlx_put_image_to_window(mlx, mlx_win, img, 60, 60);
	
	mlx_put_image_to_window(mlx, mlx_win, img3, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, img3, 0, 60);
	mlx_put_image_to_window(mlx, mlx_win, img3, 0, 120);
	mlx_put_image_to_window(mlx, mlx_win, img3, 0, 180);

	mlx_put_image_to_window(mlx, mlx_win, img1, 0, 440);
	mlx_put_image_to_window(mlx, mlx_win, img1, 60, 440);
	mlx_put_image_to_window(mlx, mlx_win, img1, 120, 440);
	mlx_put_image_to_window(mlx, mlx_win, img1, 180, 440);

	mlx_put_image_to_window(mlx, mlx_win, img2, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, img2, 60, 0);
	mlx_put_image_to_window(mlx, mlx_win, img2, 120, 0);
	mlx_put_image_to_window(mlx, mlx_win, img2, 180, 0);

	if (argc != 2)
	{
		printf("Wrong parmeters: You have to indicate the path of map\n");
		return (0);
	}
	map = get_map(argv[1]);
	print_map(map);

	mlx_loop(mlx);
	return (0);
}