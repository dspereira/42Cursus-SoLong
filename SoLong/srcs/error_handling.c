/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 09:30:05 by dsilveri          #+#    #+#             */
/*   Updated: 2022/05/14 09:30:22 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *str)
{
	int	size;

	if (!str)
		return ;
	size = ft_strlen(str);
	write(STDERR_FD, str, size);
}

void	*oom_guard(void *p)
{
	if (!p)
	{
		free_alloc_mem();
		print_error("Out of memory!\n");
		exit(EXIT_FAILURE);
	}
	return (p);
}

int	map_error(int err, char *msg)
{
	if (err == -1)
	{
		free_alloc_mem();
		print_error("Error\n");
		print_error(msg);
		exit(EXIT_FAILURE);
	}
	return (err);
}

int	sys_error(int err)
{
	if (err == -1)
	{
		free_alloc_mem();
		print_error("Error\n");
		print_error(strerror(errno));
		print_error("\n");
		exit(EXIT_FAILURE);
	}
	return (err);
}

void	*mlx_error(void *p)
{		
	if (!p)
	{
		free_alloc_mem();
		print_error("Error\n");
		print_error("mlx fail\n");
		exit(EXIT_FAILURE);
	}
	return (p);
}
