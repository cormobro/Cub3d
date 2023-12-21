#include "../Includes/cub3d.h"

static void	ft_free_exit(char *str, t_map *map)
{
	if (map)
	{
		if (map->north != NULL)
			free (map->north);
		if (map->south != NULL)
			free (map->south);
		if (map->east != NULL)
			free (map->east);
		if (map->west != NULL)
			free (map->west);
		if (map->ceiling != NULL)
			free (map->ceiling);
		if (map->floor != NULL)
			free (map->floor);
		free (map);
	}
	ft_exit(str);
}

static t_map	*init_map()
{
	t_map	*map;

	map = malloc(sizeof(t_map) * 1);
	if (!map)
		ft_exit("Error\nAllocation failed\n");
	map->north = NULL;
	map->south = NULL;
	map->east = NULL;
	map->west = NULL;
	map->ceiling = NULL;
	map->floor = NULL;
	map->mapX = 0;
	map->mapY = 0;
	map->hexfloor = 0;
	map->hexceiling = 0;
	map->posX = 0;
	map->posY = 0;
	map->dirX = 0;
	map->dirY = 0;
	map->rayDirX = 0;
	map->rayDirY = 0;
	map->planeX = 0;
	map->planeY = 0.66;
	map->side = 0;
	map->time = 0;
	map->oldTime = 0;
	map->perpWallDist = 0;
	map->check = false;
	return (map);
}

int	main(int argc, char **argv)
{
	t_map		*map;

	map = NULL;
	map = init_map();
	if (!arg_checker(argc, argv))
		ft_free_exit("Error\nFile extension is not '.cub'\n", map);
	if (!map_checker(argv, map))
		ft_free_exit("Error\nWrong map format\n", map);
	launch_graphic_env(map);
	return (0);
}
