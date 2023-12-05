#include "../../Includes/cub3d.h"

static void	check_sprite_rgb(char *rgb)
{
	int	i;
	int	num;
	char	**colors;

	colors = ft_split(rgb, ',');
	if (!colors)
		exit(EXIT_FAILURE);
	i = 0;
	while (colors[i])
	{
		if (!ft_isnumber(colors[i]))
			exit(EXIT_FAILURE);
		num = ft_atoi(colors[i]);
		free(colors[i]);
		if (num > 255 || num < 0)
			exit(EXIT_FAILURE);
		i++;
	}
	free(colors);
	if (i != 3)
		exit(EXIT_FAILURE);
	printf("NICE\n");
}

static void	check_sprite_path(char *path)
{
	int	fd;
	int	i;

	i = ft_strlen(path);
	if (path[i - 1] != 'm' || path[i - 2] != 'p' || path[i - 3] != 'x' || path[i - 4] != '.')
		exit(EXIT_FAILURE);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
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
