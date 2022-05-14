/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:29:34 by dsilveri          #+#    #+#             */
/*   Updated: 2022/05/14 15:35:50 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move(t_data *data);
static int	time_counter(int n_sec);

int	enemy_move(t_data *data)
{
	if (!data->n_enemys)
		return (0);
	if (time_counter(1))
		move(data);
	if (is_win(*data) || is_lose(*data))
		finish_game();
	return (0);
}

int	get_number_of_enemys(t_map map)
{
	int	i;
	int	j;
	int	n;

	n = 0;
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.length)
		{
			if (map.map[i][j] == ENEMY)
				n++;
			j++;
		}
		i++;
	}
	return (n);
}

static void	move(t_data *data)
{
	t_pos	*e_pos;
	t_pos	new_pos;
	int		i;
	int		dir;

	i = 0;
	clean_all_character(*data);
	while (i < data->n_enemys)
	{
		e_pos = &(data->e_pos[i]);
		dir = get_enemy_dir(*e_pos, data->p_pos);
		new_pos = get_new_pos(*e_pos, dir);
		if (is_valid_move(new_pos, data->map.map)
			&& !is_collision_btw_enemys(*data, new_pos, i))
			*e_pos = new_pos;
		i++;
	}
	print_all_character(*data);
}

static int	time_counter(int n_sec)
{
	static unsigned long	time_actual = 0;
	static unsigned long	time_buff = 0;

	time_actual = time(NULL);
	if (time_actual - time_buff >= n_sec)
	{
		time_buff = time(NULL);
		return (1);
	}
	return (0);
}
