/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_call_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:29:27 by dsilveri          #+#    #+#             */
/*   Updated: 2022/05/14 14:29:53 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_down(int keycode, t_data *data)
{
	player_start_move(keycode, data);
	if (keycode == KEY_ESC)
		finish_game();
	return (0);
}

int	key_up(int keycode, t_data *data)
{
	player_stop_move(keycode, data);
	return (0);
}

int	enemy_call(t_data *data)
{
	enemy_move(data);
	return (0);
}

int	end_game()
{
	finish_game();
	return (0);
}
