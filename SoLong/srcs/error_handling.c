/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 09:30:05 by dsilveri          #+#    #+#             */
/*   Updated: 2022/05/15 12:09:55 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*oom_guard(void *p)
{
	if (!p)
	{
		free_alloc_mem();
		print_msg(STDERR_FD, "Out of memory!\n");
		exit(EXIT_FAILURE);
	}
	return (p);
}

int	map_error(int err, char *msg)
{
	if (err == -1)
	{
		free_alloc_mem();
		print_msg(STDERR_FD, "Error\n");
		print_msg(STDERR_FD, msg);
		exit(EXIT_FAILURE);
	}
	return (err);
}

int	sys_error(int err)
{
	if (err == -1)
	{
		free_alloc_mem();
		print_msg(STDERR_FD, "Error\n");
		print_msg(STDERR_FD, strerror(errno));
		print_msg(STDERR_FD, "\n");
		exit(EXIT_FAILURE);
	}
	return (err);
}

void	*mlx_error(void *p)
{		
	if (!p)
	{
		free_alloc_mem();
		print_msg(STDERR_FD, "Error\n");
		print_msg(STDERR_FD, "mlx fail\n");
		exit(EXIT_FAILURE);
	}
	return (p);
}
