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
	map->map_x = 0;
	map->map_y = 0;
	map->hexfloor = 0;
	map->hexceiling = 0;
	map->pos_x = 0;
	map->pos_y = 0;
	map->dir_x = 0;
	map->dir_y = 0;
	map->ray_dir_x = 0;
	map->ray_dir_y = 0;
	map->plane_x = 0;
	map->plane_y = 0.66;
	map->delta_dist_x = 0;
	map->delta_dist_y = 0;
	map->side_dist_x = 0;
	map->side_dist_y = 0;
	map->step_x = 0;
	map->step_y = 0;
	map->side = 0;
	map->tex_pos = 0;
	map->time = 0;
	map->old_time = 0;
	map->perp_wall_dist = 0;
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
