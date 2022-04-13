#include "so_long.h"

void get_map_pos(t_pos pos, int *i, int *j)
{
	*i = pos.y / IMG_SIZE;
	*j = pos.x / IMG_SIZE;
}

t_pos *get_window_pos(int i, int j, t_pos *pos)
{
	pos->x = j * IMG_SIZE;
	pos->y = i * IMG_SIZE;
	return (pos);
}

t_pos *get_player_corners(t_pos start_pos, t_pos *corners)
{
	corners[0].x = start_pos.x;
	corners[0].y = start_pos.y;
	corners[1].x = start_pos.x + PLAYER_W;
	corners[1].y = start_pos.y;
	corners[2].x = start_pos.x;
	corners[2].y = start_pos.y + PLAYER_H;
	corners[3].x = start_pos.x + PLAYER_W;
	corners[3].y = start_pos.y + PLAYER_H;
	return (corners);
}

