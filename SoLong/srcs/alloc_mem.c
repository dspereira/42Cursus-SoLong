#include "so_long.h"


static t_data	*alloc_mem(t_data *data)
{
	static t_data	*d = 0;

	if (!d && data)
		d = data;
	return (d);
}

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
}



/*
void	init_alloc_mem(void)
{
	alloc_mem(0, NO_TYPE);
}

void	save_alloc_mem(void *mem, int type)
{
	alloc_mem(mem, type);
}

void	free_alloc_mem(void)
{
	t_alloc_mem	*mem;

	mem = get_alloc_mem();
	if (mem && mem->map)
		;
		//free_map(mem->map);
	if (mem)
		free(mem);
}

static t_alloc_mem	*get_alloc_mem(void)
{
    return (alloc_mem(0, NO_TYPE));
}

static t_alloc_mem	*alloc_mem(void *elem, int type)
{
	static t_alloc_mem	*mem = 0;

	if (!mem)
	{
		mem = oom_guard2(malloc(sizeof(t_alloc_mem)));
		mem->map = 0;
	}
	if (type == TYPE_MAP)
		mem->map = (t_map *) elem;
	return (mem);
}
*/