#include "../Includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_map		*map;

	map = NULL;
	window = NULL;
	if (!arg_checker(argc, argv))
		return (ft_putstr_fd("Error\nFile extension is not '.cub'\n", 2));
	if (!map_checker(argv, map))
		return (ft_putstr_fd("Error\nWrong map format\n", 2));
	launch_graphic_env(map);
	return (0);
}
