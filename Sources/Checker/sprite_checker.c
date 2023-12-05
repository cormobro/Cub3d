#include "../../Includes/cub3d.h"

static void	check_sprite_rgb(char *rgb)
{
	int	i;
	int	num;
	char	**colors;

	colors = ft_split(rgb, ',');
	if (!colors)
		ft_exit("Error: allocation failed");
	i = 0;
	while (colors[i])
	{
		if (!ft_isnumber(colors[i]))
			ft_exit("Error: RGB syntax error: not a digit");
		num = ft_atoi(colors[i]);
		free(colors[i]);
		if (num > 255 || num < 0)
			ft_exit("Error: RGB syntax error: number must be between 0 and 255");
		i++;
	}
	free(colors);
	if (i != 3)
		ft_exit("Error: RGB syntax error: need at least 3 numbers for RGB to be correct");
}

static void	check_sprite_path(char *path)
{
	int	fd;
	int	i;

	i = ft_strlen(path);
	if (path[i - 1] != 'm' || path[i - 2] != 'p' || path[i - 3] != 'x' || path[i - 4] != '.')
		ft_exit("Error: sprite error: not a .xpm");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_exit("Error: cannot open sprite file");
	close(fd);
}

void	sprite_checker(t_map *map)
{
	check_sprite_path(map->north);
	check_sprite_path(map->south);
	check_sprite_path(map->east);
	check_sprite_path(map->west);
	check_sprite_rgb(map->ceiling);
	check_sprite_rgb(map->floor);
}
