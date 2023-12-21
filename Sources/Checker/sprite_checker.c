#include "../../Includes/cub3d.h"

static unsigned int	createRGB(int r, int g, int b)
{
	return (r << 16) | (g << 8) | b;
}

static void	check_sprite_rgb(char *rgb, double *hex)
{
	int	i;
	int	r;
	int	g;
	int	b;
	int	num;
	char	**colors;

	colors = ft_split(rgb, ',');
	if (!colors)
		ft_exit("Error\nAllocation failed\n");
	i = 0;
	while (colors[i])
	{
		if (!ft_isnumber(colors[i]))
			ft_exit("Error\nRGB syntax error: not a digit\n");
		num = ft_atoi(colors[i]);
		free(colors[i]);
		if (num > 255 || num < 0)
			ft_exit("Error\nRGB syntax error: number must be between 0 and 255\n");
		if (i == 0)
			r = num;
		else if (i == 1)
			g = num;
		else
			b = num;
		i++;
	}
	free(colors);
	if (i != 3)
		ft_exit("Error\nRGB syntax error: need at least 3 numbers for RGB to be correct\n");
	*hex = (double)(createRGB(r, g, b));
}

static void	check_sprite_path(char *path)
{
	int	fd;
	int	i;

	i = ft_strlen(path);
	if (path[i - 1] != 'm' || path[i - 2] != 'p' || path[i - 3] != 'x' || path[i - 4] != '.')
		ft_exit("Error\nSprite error: not a .xpm\n");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_exit("Error\nCannot open sprite file\n");
	close(fd);
}

void	sprite_checker(t_map *map)
{
	check_sprite_path(map->north);
	check_sprite_path(map->south);
	check_sprite_path(map->east);
	check_sprite_path(map->west);
	check_sprite_rgb(map->ceiling, &map->hexceiling);
	check_sprite_rgb(map->floor, &map->hexfloor);
}
