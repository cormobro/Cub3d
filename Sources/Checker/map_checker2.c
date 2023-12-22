#include "../../Includes/cub3d.h"

static void	getPlayerDir(t_map *map, char c)
{
	if (c == 69)
	{
		map->plane_y = 0;
		map->plane_x = 0.66;
		map->dir_y = 1;
	}
	else if (c == 78)
		map->dir_x = -1;
	else if (c == 83)
	{
		map->dir_x = 1;
		map->plane_x = 0;
		map->plane_y = -0.66;
	}
	else
	{
		map->plane_y = 0;
		map->plane_x = -0.66;
		map->dir_y = -1;
	}
}

static bool	map_precheck(int fd, t_map *map)
{
	char	*stack;
	char	*line;
	int	i;

	stack = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		stack = ft_strjoin(stack, line);
		free(line);
		line = get_next_line(fd);
	}
	i = 0;
	while (stack[i] && (stack[i] == 48 || ft_isspace(stack[i]) || stack[i] == '\n' || stack[i] == 49 || stack[i] == 69 || stack[i] == 78 || stack[i] == 83 || stack[i] == 87))
	{
		if (stack[i] == 69 || stack[i] == 78 || stack[i] == 83 || stack[i] == 87)
		{
			if (map->check == true)
				ft_exit("Error\nSyntax error in the map\n");
			getPlayerDir(map, stack[i]);
			map->check = true;
		}
		i++;
	}
	map->maparray = ft_split(stack, '\n');
	return (true);
}

bool	map_extractor(int fd, t_map *map)
{
	(void)fd;

	sprite_checker(map);
	map->check = false;
	if (!map_precheck(fd, map) || map->check == false || !map_valid(map))
		ft_exit("Error\nSyntax error in the map\n");
	return (true);
}
