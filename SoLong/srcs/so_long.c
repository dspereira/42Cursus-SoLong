/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:29:27 by dsilveri          #+#    #+#             */
/*   Updated: 2022/05/15 12:16:40 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	data_init(t_data *data);
static void	mlx_win_init(t_data *data);

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		print_msg(STDERR_FD, "Error\n");
		print_msg(STDERR_FD, "no map was specified\n");
		return (0);
	}
	data_init(&data);
	get_map(&data, argv[1]);
	mlx_win_init(&data);
	game_init(&data);
	mlx_hook(data.win.mlx_win, ON_KEYDOWN, 1L << 0, key_down, &data);
	mlx_hook(data.win.mlx_win, ON_KEYUP, 1L << 1, key_up, &data);
	mlx_loop_hook(data.win.mlx, enemy_call, &data);
	mlx_hook(data.win.mlx_win, ON_DESTROY, 0, end_game, &data);
	mlx_loop(data.win.mlx);
	return (0);
}

static void	data_init(t_data *data)
{
	int	i;

	data->map.map = 0;
	data->e_pos = 0;
	data->win.mlx = 0;
	data->win.mlx_win = 0;
	data->n_moves = 0;
	data->n_enemys = 0;
	i = 0;
	while (i < N_TEXTURES)
	{
		data->textures[i].img = 0;
		i++;
	}
	i = 0;
	while (i < N_SPRITES)
	{
		data->player[i].img = 0;
		data->enemy[i].img = 0;
		i++;
	}
	save_alloc_mem(data);
}

static void	mlx_win_init(t_data *data)
{
	void	*mlx;
	void	*mlx_win;
	int		win_l;
	int		win_h;

	win_l = data->map.length * IMG_SIZE;
	win_h = data->map.height * IMG_SIZE;
	mlx = mlx_error(mlx_init());
	mlx_win = mlx_error(mlx_new_window(mlx, win_l, win_h, "SoLong"));
	data->win.mlx = mlx;
	data->win.mlx_win = mlx_win;
}
