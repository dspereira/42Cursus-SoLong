/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_enemy_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:38:34 by dsilveri          #+#    #+#             */
/*   Updated: 2022/05/16 15:25:52 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static int	get_random_num(int max_value);
static int	get_rand_direction(void);

int	get_enemy_dir(t_pos e_pos, t_pos p_pos)
{
	int	r;
	int	dir;

	r = get_random_num(4);
	if (r == 0)
	{
		if (p_pos.x < e_pos.x)
			dir = KEY_LEFT;
		else
			dir = KEY_RIGHT;
	}
	else if (r == 1)
	{
		if (p_pos.y < e_pos.y)
			dir = KEY_UP;
		else
			dir = KEY_DOWN;
	}
	else if (r >= 2)
		dir = get_rand_direction();
	return (dir);
}

static int	get_random_num(int max_value)
{
	int	r;

	r = rand() % (max_value + 1);
	return (r);
}

static int	get_rand_direction(void)
{
	int	r;

	r = get_random_num(3);
	if (r == 0)
		return (KEY_LEFT);
	else if (r == 1)
		return (KEY_RIGHT);
	else if (r == 2)
		return (KEY_UP);
	else
		return (KEY_DOWN);
}
