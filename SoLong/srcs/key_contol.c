#include "so_long.h"

static void make_move(t_data *data, int x_offset, int y_offset);


int	key_control(int keycode, t_data *data)
{
	if (keycode == KEY_UP)
		make_move(data, 0, -MOVE_RANGE);
	else if (keycode == KEY_DOWN)
		make_move(data, 0, MOVE_RANGE);
	else if (keycode == KEY_LEFT)
		make_move(data, -MOVE_RANGE, 0);
	else if (keycode == KEY_RIGHT)
		make_move(data, MOVE_RANGE, 0);
	return (0);
}

static void make_move(t_data *data, int x_offset, int y_offset)
{
	t_pos p;

	p.x = data->map.p.x + x_offset;
	p.y = data->map.p.y + y_offset;
	if (is_valid_move(p, data->map.map))
		move_player(data, p);
	catch_coin(data);
	catch_coin(data);
	if(is_player_win(*data))
	{
		mlx_destroy_window(data->win.mlx, data->win.mlx_win);
		exit(0);
	}		
}
