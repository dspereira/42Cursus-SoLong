/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:05:47 by dsilveri          #+#    #+#             */
/*   Updated: 2022/05/14 14:37:20 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish_game(void)
{
	free_alloc_mem();
	exit(0);
}

int	is_valid_move(t_pos pos, char **map)
{
	if (is_player_collision(pos, map, TREE))
		return (0);
	return (1);
}

int	is_win(t_data data)
{
	int		n_coins;
	t_pos	p[4];
	int		i;

	n_coins = data.n_coins;
	get_corners(data.p_pos, p);
	i = 0;
	while (i < 4)
	{
		if (is_collision(p[i], data.map.map, EXIT))
		{
			if (n_coins == 0)
				return (1);
		}
		i++;
	}	
	return (0);
}

int	is_lose(t_data data)
{
	int	i;

	i = 0;
	while (i < data.n_enemys)
	{
		if (enemy_collision(data.p_pos, data.e_pos[i]))
		{
			printf("you lose!\n");
			return (1);
		}
		i++;
	}
	return (0);
}
