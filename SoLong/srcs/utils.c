/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:18:33 by dsilveri          #+#    #+#             */
/*   Updated: 2022/05/14 13:44:44 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_size(long int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}	
	return (i);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*str;
	long int	nbr;

	nbr = (long int) n;
	size = get_size(nbr);
	str = oom_guard(malloc((1 + size) * sizeof(char)));
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	else if (nbr == 0)
		str[0] = '0';
	str[size] = '\0';
	while (nbr > 0)
	{
		str[--size] = (nbr - ((nbr / 10) * 10)) + '0';
		nbr /= 10;
	}
	return (str);
}

void	clean_mlx(t_data data)
{
	int	i;

	i = 0;
	while (i < N_SPRITES)
	{
		if (data.win.mlx && data.enemy[i].img)
			mlx_destroy_image(data.win.mlx, data.enemy[i].img);
		if (data.win.mlx && data.player[i].img)
			mlx_destroy_image(data.win.mlx, data.player[i].img);
		i++;
	}
	i = 0;
	while (i < N_TEXTURES)
	{
		if (data.win.mlx && data.textures[i].img)
			mlx_destroy_image(data.win.mlx, data.textures[i].img);
		i++;
	}
	if (data.win.mlx && data.win.mlx_win)
		mlx_destroy_window(data.win.mlx, data.win.mlx_win);
}
