#include "so_long.h"

int is_valid_move(t_map map, int x, int y, int d)
{
	int i;
	int j;
	int k;
	int p_offset;

	p_offset = 0;
	if (d == DOWN || d == RIGHT)
		p_offset = PLAYER_SIZE;
	if (d == LEFT || d == RIGHT)
	{
		i = y / IMG_SIZE;
		j = (x + p_offset) / IMG_SIZE;
		k = (y + PLAYER_SIZE) / IMG_SIZE;
		if (map.map[i][j] == '1' || map.map[k][j] == '1')
			return (0);	
	}
	else 
	{
		i = (y + p_offset) / IMG_SIZE;
		j = x / IMG_SIZE;
		k = (x + PLAYER_SIZE) / IMG_SIZE;
		if (map.map[i][j] == '1' || map.map[i][k] == '1')
			return (0);		
	}
	return (1);
}
