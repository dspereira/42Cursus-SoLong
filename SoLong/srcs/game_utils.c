#include "so_long.h"

t_map_pos get_map_pos(t_pos pos)
{
	t_map_pos m_pos;

	m_pos.i = pos.y / IMG_SIZE;
	m_pos.j = pos.x / IMG_SIZE;
	return (m_pos);
}

t_pos *get_window_pos(int i, int j, t_pos *pos)
{
	pos->x = j * IMG_SIZE;
	pos->y = i * IMG_SIZE;
	return (pos);
}

t_pos get_window_pos1(t_map_pos m_pos)
{
	t_pos pos;
	pos.x = m_pos.j * IMG_SIZE;
	pos.y = m_pos.i * IMG_SIZE;
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

