/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:56:37 by dsilveri          #+#    #+#             */
/*   Updated: 2022/05/16 16:03:27 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_sprite_player(int dir);
static int	get_sprite_enemy(int sprite, int dir);

t_pos	get_new_pos(t_pos pos, int dir, char c)
{
	if (dir == KEY_UP)
		pos.y -= MOVE_RANGE;
	else if (dir == KEY_DOWN)
		pos.y += MOVE_RANGE;
	else if (dir == KEY_RIGHT)
		pos.x += MOVE_RANGE;
	else if (dir == KEY_LEFT)
		pos.x -= MOVE_RANGE;
	if (c == ENEMY)
		pos.sprite = get_sprite_enemy(pos.sprite, dir);
	else
		pos.sprite = get_sprite_player(dir);
	return (pos);
}

static int	get_sprite_player(int dir)
{
	static int	i = 0;
	int			s;

	s = 0;
	if (dir == KEY_UP && i % 2 == 0)
		s = UP_1;
	else if (dir == KEY_UP)
		s = UP_2;
	else if (dir == KEY_DOWN && i % 2 == 0)
		s = DOWN_1;
	else if (dir == KEY_DOWN)
		s = DOWN_2;
	else if (dir == KEY_LEFT && i % 2 == 0)
		s = LEFT_1;
	else if (dir == KEY_LEFT)
		s = LEFT_2;
	else if (dir == KEY_RIGHT && i % 2 == 0)
		s = RIGHT_1;
	else if (dir == KEY_RIGHT)
		s = RIGHT_2;
	i++;
	return (s);
}

static int	get_sprite_enemy(int sprite, int dir)
{
	int	s;

	s = 0;
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
