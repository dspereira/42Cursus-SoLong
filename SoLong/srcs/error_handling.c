#include "so_long.h"

void	*oom_guard(void *p)
{
	if (!p)
	{
		printf("%s: Out of memory!\n", "Solong");
		exit(EXIT_FAILURE);
	}
	return (p);
}

void map_error(int err)
{
	if (err == 0)
	{
		printf("Error\n");
		exit(0);
	}	
}