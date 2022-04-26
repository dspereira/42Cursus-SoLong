#include "so_long.h"

// criar função de update numero de jogadas

void player_move(t_data *data, int dir)
{
	t_pos new_pos;
	t_pos pos;
	char **map;
	
	map = data->map.map;
	pos = data->p_pos;
	new_pos = get_new_pos(pos, dir);
	if (is_valid_move(new_pos, map))
	{
		move_character_novo(data, data->player, &(data->p_pos), dir);
		data->n_moves++;
		print_player_moves(*data);
	}
	if (is_player_collision(pos, map, COLLECTIBLE))
	{
		catch_coin(data);
		catch_coin(data);
	}
	if(is_win(*data))
		finish_game(*data);
}