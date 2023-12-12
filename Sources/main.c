#include "../Includes/cub3d.h"

static t_map	*init_map()
{
	t_map	*map;

	map = malloc(sizeof(t_map) * 1);
	if (!map)
		ft_exit("Error: allocation failed\n");
	map->north = NULL;
	map->south = NULL;
	map->east = NULL;
	map->west = NULL;
	map->ceiling = NULL;
	map->floor = NULL;
	map->check = false;
	return (map);
}

int	main(int argc, char **argv)
{
	t_map		*map;

	map = NULL;
	map = init_map();
	if (!arg_checker(argc, argv))
		return (ft_putstr_fd("Error\nFile extension is not '.cub'\n", 2));
	if (!map_checker(argv, map))
		return (ft_putstr_fd("Error\nWrong map format\n", 2));
	launch_graphic_env(map);
	return (0);
}
