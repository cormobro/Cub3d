#include "../../Includes/cub3d.h"

static void	get_path(char *str, char **path)
{
	int	i;
	int	j;

	i = 3;
	if (str[1] == ' ')
		i--;
	while (str[i] && str[i] == ' ' && str[i] == '\t')
		i++;
	j = i;
	while (str[j] != '\0' && str[j] != ' ' && str[j] != '\t')
		j++;
	*path = malloc(sizeof(char) * (j - i + 1));
	if (!path)
		exit(EXIT_FAILURE);
	j = 0;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			(*path)[j] = str[i];
			i++;
			j++;
		}
}

static void	is_valid_line(char *str, t_map *map)
{
	int	i;

	i = -1;
	if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ' && map->north == NULL)
		get_path(str, &map->north);
	else if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ' && map->south == NULL)
		get_path(str, &map->south);
	else if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ' && map->east == NULL)
		get_path(str, &map->east);
	else if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ' && map->west == NULL)
		get_path(str, &map->west);
	else if (str[0] == 'C' && str[1] == ' ' && map->ceiling == NULL)
		get_path(str, &map->ceiling);
	else if (str[0] == 'F' && str[1] == ' ' && map->floor == NULL)
		get_path(str, &map->floor);
	else
	{
		while (str[++i])
		{
			if (str[i] != ' ' && str[i] != 9 && str[i] != 10 && str[i] != 11 && str[i] != 12 && str[i] != 13)
				exit(EXIT_FAILURE);
		}
	}
	if (map->north != NULL && map->south != NULL && map->east != NULL && map->west != NULL
			&& map->ceiling != NULL && map->floor != NULL)
		map->check = true;
}

static bool	cub_extractor(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL && map->check == false)
	{
		is_valid_line(line, map);
		free (line);
		line = get_next_line(fd);
	}
	if (map->check == false)
	{
		printf("map check is false\n");
		return (false);
	}
	//Now that paths are retrieved, check for the map.
	if (!map_extractor(fd, map))
		return (false);
	return (true);
}

static bool	ft_check_map_validity(int fd, t_map *map)
{
	map = malloc(sizeof(t_map) * 1);
	if (!map)
		exit(EXIT_FAILURE);
	map->north = NULL;
	map->south = NULL;
	map->east = NULL;
	map->west = NULL;
	map->ceiling = NULL;
	map->floor = NULL;
	map->check = false;
	if (!cub_extractor(fd, map))
		return (false);
	return (true);
}

bool	map_checker(char **argv, t_map *map)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (false);
	if (!ft_check_map_validity(fd, map))
	{
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}
