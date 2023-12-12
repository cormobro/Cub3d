#include "../../Includes/cub3d.h"

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
				ft_exit("Error: syntax error in the map\n");
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
<<<<<<< HEAD
	if (!map_precheck(fd, map) || map->check == false || !is_surrounded_by_walls(map->maparray))
=======
	if (!map_precheck(fd, map) || map->check == false || !map_valid(map))
>>>>>>> main
		ft_exit("Error: syntax error in the map\n");
	printf("NICE\n");
	return (true);
}
