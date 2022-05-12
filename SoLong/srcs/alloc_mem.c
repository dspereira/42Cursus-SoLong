#include "so_long.h"

static t_data	*alloc_mem(t_data *data);

static t_data *get_alloc_mem(void)
{
	return (alloc_mem(0));
}

void	save_alloc_mem(t_data *data)
{
	alloc_mem(data);
}

void	free_alloc_mem(void)
{
	t_data	*data;

	data = get_alloc_mem();
	free_map(data->map);
	if (data->e_pos)
		free(data->e_pos);
	clean_mlx(*data);
}

static t_data	*alloc_mem(t_data *data)
{
	static t_data	*d = 0;

	if (!d && data)
		d = data;
	return (d);
}