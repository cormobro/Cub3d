#include "../../Includes/cub3d.h"

static unsigned int	creatergb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

static void	check_sprite_rgb(char *rgb, double *hex, int r, int g, t_map *map)
{
	int		i;
	int		num;
	char	**colors;

	colors = ft_split(rgb, ',');
	if (!colors)
		ft_exit("Error\nAllocation failed\n", map);
	i = -1;
	while (colors[++i])
	{
		if (!ft_isnumber(colors[i]))
			ft_exit("Error\nRGB syntax error: not a digit\n", map);
		num = ft_atoi(colors[i]);
		free(colors[i]);
		if (num > 255 || num < 0)
			ft_exit("Error\nRGB syntax error", map);
		if (i == 0)
			r = num;
		else if (i == 1)
			g = num;
	}
	free(colors);
	if (i != 3)
		ft_exit("Error\nRGB syntax error", map);
	*hex = (double)(creatergb(r, g, num));
}

static void	check_sprite_path(char *path, t_map *map)
{
	int	fd;
	int	i;

	i = ft_strlen(path);
	if (path[i - 1] != 'm' || path[i - 2] != 'p'
		|| path[i - 3] != 'x' || path[i - 4] != '.')
		ft_exit("Error\nSprite error: not a .xpm\n", map);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_exit("Error\nCannot open sprite file\n", map);
	close(fd);
}

void	sprite_checker(t_map *map)
{
	int	r;
	int	g;

	r = 0;
	g = 0;
	check_sprite_path(map->north, map);
	check_sprite_path(map->south, map);
	check_sprite_path(map->east, map);
	check_sprite_path(map->west, map);
	check_sprite_rgb(map->ceiling, &map->hexceiling, r, g, map);
	check_sprite_rgb(map->floor, &map->hexfloor, r, g, map);
}
