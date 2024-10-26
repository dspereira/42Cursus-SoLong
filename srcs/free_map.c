/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:24:37 by dsilveri          #+#    #+#             */
/*   Updated: 2022/05/14 14:25:06 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map map)
{
	int		i;
	char	**m;

	m = map.map;
	if (!m)
		return ;
	i = 0;
	while (i < map.height)
	{
		if (m[i])
			free(m[i]);
		i++;
	}
	free(m);
}
