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
	int x;
	int y;

	x = data->map.p.x;
	y = data->map.p.y - MOVE_RANGE;
	if (is_valid_move(data->map, x, y, UP))
	{
		data->map.p.y -= 10;
		mlx_put_image_to_window(data->win.mlx, data->win.mlx_win,data->imgs.player, data->map.p.x, data->map.p.y);
	}
	printf("player pos: x:%i y:%i\n", data->map.p.x, data->map.p.y);
}

static void down(t_data *data)
{
	int x;
	int y;

	x = data->map.p.x;
	y = data->map.p.y + MOVE_RANGE;
	if (is_valid_move(data->map, x, y, DOWN))
	{
		data->map.p.y += 10;
		mlx_put_image_to_window(data->win.mlx, data->win.mlx_win,data->imgs.player, data->map.p.x, data->map.p.y);
	}
	printf("player pos: x:%i y:%i\n", data->map.p.x, data->map.p.y);
}

static void left(t_data *data)
{
	int x;
	int y;

	x = data->map.p.x - MOVE_RANGE;
	y = data->map.p.y;
	if (is_valid_move(data->map, x, y, LEFT))
	{
		data->map.p.x -= 10;
		mlx_put_image_to_window(data->win.mlx, data->win.mlx_win,data->imgs.player, data->map.p.x, data->map.p.y);
	}
	printf("player pos: x:%i y:%i\n", data->map.p.x, data->map.p.y);
}

static void right(t_data *data)
{
	int x;
	int y;

	x = data->map.p.x + MOVE_RANGE;
	y = data->map.p.y;
	if (is_valid_move(data->map, x, y, RIGHT))
	{
		data->map.p.x += 10;
		mlx_put_image_to_window(data->win.mlx, data->win.mlx_win,data->imgs.player, data->map.p.x, data->map.p.y);
	}
	printf("player pos: x:%i y:%i\n", data->map.p.x, data->map.p.y);
}