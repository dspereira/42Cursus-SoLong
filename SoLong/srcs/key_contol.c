#include "so_long.h"

static void up(t_data *data);
static void down(t_data *data);
static void left(t_data *data);
static void right(t_data *data);

int	key_control(int keycode, t_data *data)
{
	printf("keycode: %i\n", keycode);

	if (keycode == KEY_UP)
		up(data);
	else if (keycode == KEY_DOWN)
		down(data);
	else if (keycode == KEY_LEFT)
		left(data);
	else if (keycode == KEY_RIGHT)
		right(data);
	return (0);
}

static void up(t_data *data)
{
	data->map.p.y -= 10;
	mlx_put_image_to_window(data->win.mlx, data->win.mlx_win,data->imgs.player, data->map.p.x, data->map.p.y);
	printf("player pos: x:%i y:%i\n", data->map.p.x, data->map.p.y);
}

static void down(t_data *data)
{
	data->map.p.y += 10;
	mlx_put_image_to_window(data->win.mlx, data->win.mlx_win,data->imgs.player, data->map.p.x, data->map.p.y);
	printf("player pos: x:%i y:%i\n", data->map.p.x, data->map.p.y);
}

static void left(t_data *data)
{
	data->map.p.x -= 10;
	mlx_put_image_to_window(data->win.mlx, data->win.mlx_win,data->imgs.player, data->map.p.x, data->map.p.y);
	printf("player pos: x:%i y:%i\n", data->map.p.x, data->map.p.y);
}

static void right(t_data *data)
{
	data->map.p.x += 10;
	mlx_put_image_to_window(data->win.mlx, data->win.mlx_win,data->imgs.player, data->map.p.x, data->map.p.y);
	printf("player pos: x:%i y:%i\n", data->map.p.x, data->map.p.y);
}