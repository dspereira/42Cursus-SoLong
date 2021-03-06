/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all_character.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:00:48 by dsilveri          #+#    #+#             */
/*   Updated: 2022/05/14 14:37:20 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clean_character(t_data data, t_pos pos);

void	clean_all_character(t_data data)
{
	int	i;

	i = 0;
	while (i < data.n_enemys)
	{
		clean_character(data, data.e_pos[i]);
		i++;
	}
	clean_character(data, data.p_pos);
}

static void	clean_character(t_data data, t_pos pos)
{
	t_pos		a_pos[4];
	t_map_pos	m_pos;
	int			i;

	get_corners(pos, a_pos);
	i = 0;
	while (i < 4)
	{
		m_pos = get_map_pos(a_pos[i]);
		print_img_from_map(data, m_pos.i, m_pos.j);
		i++;
	}
}
