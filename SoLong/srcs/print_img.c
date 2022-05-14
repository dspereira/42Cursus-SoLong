/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:49:40 by dsilveri          #+#    #+#             */
/*   Updated: 2022/05/14 13:56:46 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_map_img(t_data data, char c)
{
	void	*img;

	if (c == GRASS)
		img = data.textures[GRASS_1].img;
	else if (c == TREE)
		img = data.textures[TREE_1].img;
	else if (c == COLLECTIBLE)
		img = data.textures[COIN_1].img;
	else if (c == EXIT)
		img = data.textures[EXIT_1].img;
	else if (c == PLAYER)
		img = data.player[DOWN_0].img;
	else if (c == ENEMY)
		img = data.enemy[DOWN_0].img;
	else
		img = 0;
	return (img);
}

void	print_img_from_map(t_data data, int i, int j)
{
	t_pos	pos;
	t_win	win;
	char	c;

	c = data.map.map[i][j];
	win = data.win;
	pos = get_window_pos(i, j);
	if (c != TREE && c != GRASS)
		print_img(win, pos, get_map_img(data, GRASS));
	print_img(win, pos, get_map_img(data, c));
}

void	print_img(t_win win, t_pos pos, void *img)
{
	mlx_put_image_to_window(win.mlx, win.mlx_win, img, pos.x, pos.y);
}

void	print_all_character(t_data data)
{
	int	sprite;
	int	i;

	i = 0;
	while (i < data.n_enemys)
	{
		sprite = data.e_pos[i].sprite;
		print_img(data.win, data.e_pos[i], data.enemy[sprite].img);
		i++;
	}
	print_img(data.win, data.p_pos, data.player[data.p_pos.sprite].img);
}

void	print_number_of_moves(t_data data)
{
	t_win	win;
	int		color;
	int		n;
	int		i;
	char	*num;

	win = data.win;
	n = data.n_moves;
	color = 0xFFFFFF;
	i = 0;
	while (i < 3)
		print_img_from_map(data, 0, i++);
	mlx_string_put(win.mlx, win.mlx_win, 30, 30, color, "MOVEMENTS:");
	num = ft_itoa(n);
	mlx_string_put(win.mlx, win.mlx_win, 130, 30, color, num);
	free(num);
}
