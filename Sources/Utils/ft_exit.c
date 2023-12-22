#include "../../Includes/cub3d.h"

void	ft_exit(char *str, t_map *map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		if (map->maparray != NULL && map->maparray[i] != NULL)
		{
			while (map->maparray[i] != NULL)
			{
				//printf("i:%d\n%s\n", i, map->maparray[i]);
				free(map->maparray[i]);
				i++;
			}
			free(map->maparray);
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
