#include "../Includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	map = NULL;
	if (!arg_checker(argc, argv))
		return (ft_putstr_fd("Erreur dans les arguments.\n", 2));
	if (!map_checker(argv, map))
		return (ft_putstr_fd("Erreur dans la map.\n", 2));
}
