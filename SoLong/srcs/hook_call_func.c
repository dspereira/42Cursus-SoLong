#include "so_long.h"


int	key_down(int keycode, t_data *data)
{
	player_start_move(keycode, data);
	if (keycode == KEY_ESC)
		finish_game(*data);
	return (0);
}

int key_up(int keycode, t_data *data)
{
	player_stop_move(keycode, data);
	return (0);
}

int enemy_call(t_data *data)
{
	move_enemy(data);
    return (0);
}