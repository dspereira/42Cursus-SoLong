/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:36:04 by dsilveri          #+#    #+#             */
/*   Updated: 2022/05/16 15:43:42 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static void	player_move(t_data *data, int dir);

int	player_start_move(int keycode, t_data *data)
{
	if (keycode == KEY_DOWN || keycode == KEY_UP
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		player_move(data, keycode);
	return (0);
}

int	player_stop_move(int keycode, t_data *data)
{
	void	*img;
	int		*sprite;

	sprite = &(data->p_pos.sprite);
	img = 0;
	if (keycode == KEY_UP)
		*sprite = UP_0;
	else if (keycode == KEY_DOWN)
		*sprite = DOWN_0;
	else if (keycode == KEY_LEFT)
		*sprite = LEFT_0;
	else if (keycode == KEY_RIGHT)
		*sprite = RIGHT_0;
	img = data->player[*sprite].img;
	if (img)
		print_img(data->win, data->p_pos, img);
	return (0);
}

static void	player_move(t_data *data, int dir)
{
	t_pos	new_pos;
	t_pos	pos;
	char	**map;

	map = data->map.map;
	pos = data->p_pos;
	new_pos = get_new_pos(pos, dir, PLAYER);
	clean_all_character(*data);
	if (is_valid_move(new_pos, map))
	{
		data->p_pos = new_pos;
		data->n_moves++;
		print_number_of_moves(*data);
	}
	catch_coin(data);
	catch_coin(data);
	print_all_character(*data);
	if (is_win(*data) || is_lose(*data))
		finish_game();
}
