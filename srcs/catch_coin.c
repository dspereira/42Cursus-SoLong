/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_coin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:41:02 by dsilveri          #+#    #+#             */
/*   Updated: 2022/05/14 15:47:11 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void		clean_coin(t_data *data, t_pos pos);
static int		corner_intersection_num(int *corner);
static t_pos	get_intersection_point(t_pos *pos, int *conors);

void	catch_coin(t_data *data)
{
	t_pos	pos[4];
	int		cor[4];
	int		num;
	int		i;

	get_corners(data->p_pos, pos);
	i = 0;
	while (i < 4)
	{
		cor[i] = 0;
		if (is_collision(pos[i], data->map.map, COLLECTIBLE))
			cor[i] = 1;
		i++;
	}
	num = corner_intersection_num(cor);
	if (num >= 2)
	{	
		if (num == 2 && ((cor[0] && cor[2]) || (cor[1] && cor[3])))
			return ;
		clean_coin(data, get_intersection_point(pos, cor));
		data->n_coins--;
	}
}

static void	clean_coin(t_data *data, t_pos pos)
{	
	t_map_pos	m_pos;
	char		**map;

	map = data->map.map;
	m_pos = get_map_pos(pos);
	if (map[m_pos.i][m_pos.j] == COLLECTIBLE)
		map[m_pos.i][m_pos.j] = GRASS;
	print_img_from_map(*data, m_pos.i, m_pos.j);
}

static int	corner_intersection_num(int *corner)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (i < 4)
	{
		if (corner[i])
			n++;
		i++;
	}
	return (n);
}

static t_pos	get_intersection_point(t_pos *pos, int *conors)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (conors[i])
			break ;
		i++;
	}
	return (pos[i]);
}
