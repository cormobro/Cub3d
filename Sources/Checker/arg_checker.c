#include "../../Includes/cub3d.h"

bool	arg_checker(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		return (false);
	i = ft_strlen(argv[1]);
	if (argv[1][i - 1] != 'b' || argv[1][i - 2] != 'u'
		|| argv[1][i - 3] != 'c' || argv[1][i - 4] != '.')
		return (false);
	return (true);
}
