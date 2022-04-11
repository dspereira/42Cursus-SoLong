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
	t_pos p;

	p.x = data->map.p.x;
	p.y = data->map.p.y - MOVE_RANGE;
	if (is_valid_move(p, data->map.map))
		move_player(data, p);
	//collect_collectibles(data);
	catch_collectible(data);
	printf("player pos: x:%i y:%i\n", data->map.p.x, data->map.p.y);
	if(did_player_win(*data))
	{
		printf("++++Ganhou++++\n");
		mlx_destroy_window(data->win.mlx, data->win.mlx_win);
		exit(0);
	}
		
}

static void down(t_data *data)
{
	t_pos p;

	p.x = data->map.p.x;
	p.y = data->map.p.y + MOVE_RANGE;
	if (is_valid_move(p, data->map.map))
		move_player(data, p);
	//collect_collectibles(data);
	catch_collectible(data);
	printf("player pos: x:%i y:%i\n", data->map.p.x, data->map.p.y);
	if(did_player_win(*data))
	{
		printf("++++Ganhou++++\n");
		mlx_destroy_window(data->win.mlx, data->win.mlx_win);
		exit(0);
	}
}

static void left(t_data *data)
{
	t_pos p;

	p.x = data->map.p.x - MOVE_RANGE;
	p.y = data->map.p.y;
	if (is_valid_move(p, data->map.map))
		move_player(data, p);
	//collect_collectibles(data);
	catch_collectible(data);
	printf("player pos: x:%i y:%i\n", data->map.p.x, data->map.p.y);
	if(did_player_win(*data))
	{
		printf("++++Ganhou++++\n");
		mlx_destroy_window(data->win.mlx, data->win.mlx_win);
		exit(0);
	}
}

static void right(t_data *data)
{
	t_pos p;

	p.x = data->map.p.x + MOVE_RANGE;
	p.y = data->map.p.y;
	if (is_valid_move(p, data->map.map))
		move_player(data, p);
	//collect_collectibles(data);
	catch_collectible(data);
	printf("player pos: x:%i y:%i\n", data->map.p.x, data->map.p.y);
	if(did_player_win(*data))
	{
		printf("++++Ganhou++++\n");
		mlx_destroy_window(data->win.mlx, data->win.mlx_win);
		exit(0);
	}
}