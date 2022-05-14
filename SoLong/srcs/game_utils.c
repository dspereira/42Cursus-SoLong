/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:38:47 by dsilveri          #+#    #+#             */
/*   Updated: 2022/05/14 15:40:38 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_pos	get_map_pos(t_pos pos)
{
	t_map_pos	m_pos;

	m_pos.i = pos.y / IMG_SIZE;
	m_pos.j = pos.x / IMG_SIZE;
	return (m_pos);
}

t_pos	get_window_pos(int i, int j)
{
	t_pos	pos;

	pos.x = j * IMG_SIZE;
	pos.y = i * IMG_SIZE;
	return (pos);
}

int	get_sprite(int sprite, int dir)
{
	int	s;

	if (dir == KEY_UP && sprite == UP_2)
		s = UP_1;
	else if (dir == KEY_UP)
		s = UP_2;
	else if (dir == KEY_DOWN && sprite == DOWN_2)
		s = DOWN_1;
	else if (dir == KEY_DOWN)
		s = DOWN_2;
	else if (dir == KEY_LEFT && sprite == LEFT_2)
		s = LEFT_1;
	else if (dir == KEY_LEFT)
		s = LEFT_2;
	else if (dir == KEY_RIGHT && sprite == RIGHT_2)
		s = RIGHT_1;
	else if (dir == KEY_RIGHT)
		s = RIGHT_2;
	return (s);
}

t_pos	get_new_pos(t_pos pos, int dir)
{
	if (dir == KEY_UP)
		pos.y -= MOVE_RANGE;
	else if (dir == KEY_DOWN)
		pos.y += MOVE_RANGE;
	else if (dir == KEY_RIGHT)
		pos.x += MOVE_RANGE;
	else if (dir == KEY_LEFT)
		pos.x -= MOVE_RANGE;
	pos.sprite = get_sprite(pos.sprite, dir);
	return (pos);
}

t_pos	*get_corners(t_pos start_pos, t_pos *corners)
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
