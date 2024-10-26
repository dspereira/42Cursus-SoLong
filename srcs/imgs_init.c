/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:15:05 by dsilveri          #+#    #+#             */
/*   Updated: 2022/05/14 14:15:37 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	add_img(void *mlx, t_img *img, char *path);
static void	init_player_imgs(t_img *imgs, void *mlx);
static void	init_enemy_imgs(t_img *imgs, void *mlx);
static void	init_textures_imgs(t_img *imgs, void *mlx);

void	imgs_init(t_data *data)
{
	init_player_imgs(data->player, data->win.mlx);
	init_enemy_imgs(data->enemy, data->win.mlx);
	init_textures_imgs(data->textures, data->win.mlx);
}

static void	add_img(void *mlx, t_img *img, char *path)
{
	int	w;
	int	h;

	ft_strlcpy(img->path, path, ft_strlen(path) + 1);
	img->img = mlx_xpm_file_to_image(mlx, img->path, &w, &h);
}

static void	init_player_imgs(t_img *imgs, void *mlx)
{
	int	i;

	i = 0;
	add_img(mlx, &(imgs[i++]), "./assets/player/p_up_0.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/player/p_up_1.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/player/p_up_2.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/player/p_down_0.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/player/p_down_1.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/player/p_down_2.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/player/p_left_0.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/player/p_left_1.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/player/p_left_2.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/player/p_right_0.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/player/p_right_1.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/player/p_right_2.xpm");
}

static void	init_enemy_imgs(t_img *imgs, void *mlx)
{
	int	i;

	i = 0;
	add_img(mlx, &(imgs[i++]), "./assets/enemy/e_up_0.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/enemy/e_up_1.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/enemy/e_up_2.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/enemy/e_down_0.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/enemy/e_down_1.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/enemy/e_down_2.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/enemy/e_left_0.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/enemy/e_left_1.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/enemy/e_left_2.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/enemy/e_right_0.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/enemy/e_right_1.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/enemy/e_right_2.xpm");
}

static void	init_textures_imgs(t_img *imgs, void *mlx)
{
	int	i;

	i = 0;
	add_img(mlx, &(imgs[i++]), "./assets/grass.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/tree.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/coin.xpm");
	add_img(mlx, &(imgs[i++]), "./assets/exit.xpm");
}
