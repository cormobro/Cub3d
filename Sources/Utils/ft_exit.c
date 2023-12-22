#include "../../Includes/cub3d.h"

void	ft_exit(char *str, t_map *map)
{
	int	i;

	i = -1;
	if (map != NULL)
	{
		if (map->maparray != NULL)
		{
			while (map->maparray[++i] != NULL)
				free(map->maparray[i]);
		}
		if (map->north != NULL)
			free(map->north);
		if (map->south != NULL)
			free(map->south);
		if (map->east != NULL)
			free(map->east);
		if (map->west != NULL)
			free(map->west);
		if (map->ceiling != NULL)
			free(map->ceiling);
		if (map->floor != NULL)
			free(map->floor);
		free(map);
	}
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
