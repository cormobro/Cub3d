#include "../../Includes/cub3d.h"

static bool	hole_is_blocked(char **map_array, size_t i, size_t j)
{
	// top check if three walls are placed below the hole
	if (map_array[i + 1][j] == 1 && map_array[i + 1][j + 1] == 1
		&& map_array[i + 1][j - 1] == 1)
		return (true);
	// bottom check if three walls are placed above the hole
	else if (map_array[i - 1][j] == 1 && map_array[i - 1][j + 1] == 1
		&& map_array[i - 1][j - 1] == 1)
		return (true);
	// left check if three walls are placed right of the hole
	else if (map_array[i][j + 1] == 1 && map_array[i + 1][j + 1] == 1
		&& map_array[i - 1][j + 1] == 1)
		return (true);
	// right check if three walls are placed left of the hole
	else if (map_array[i][j - 1] == 1 && map_array[i + 1][j - 1] == 1
		&& map_array[i - 1][j - 1])
		return (true);
	else
		return (false);
}

bool	is_surrounded_by_walls(char **map_array)
{
	size_t	i;
	size_t	j;
	size_t	map_width;
	size_t	map_height;

	map_width = ft_strlen(map_array[0]);
	map_height = 0;
	while (map_array[map_height])
		map_height++;
	j = 0;
	// top walls check
	while (map_array[0][j] && j < map_width)
	{
		if (map_array[0][j] == 1)
			j++;
		else if (map_array[0][j] == ' ')
		{
			if (hole_is_blocked(map_array, 0, j))
				j++;
			else
				return (false);
		}
		else
			return (false);
	}
	j = 0;
	// bottom walls check
	while (map_array[map_height][j] && j < map_width)
	{
		if (map_array[map_height][j] == 1)
			j++;
		else if (map_array[0][j] == ' ')
		{
			if (hole_is_blocked(map_array, map_height, j))
				j++;
			else
				return (false);
		}
		else
			return (false);
	}
	i = 0;
	// left walls check
	while(map_array[i][0] && i < map_height)
	{
		if (map_array[i][0] == 1)
			i++;
		else if (map_array[i][0] == ' ')
		{
			if (hole_is_blocked(map_array, i, 0))
				i++;
			else
				return (false);
		}
		else
			return (false);
	}
	i = 0;
	// right walls check
	while (map_array[i][map_width] && i < map_height)
	{
		if (map_array[i][map_width] == 1)
			i++;
		else if (map_array[i][map_width] == ' ')
		{
			if (hole_is_blocked(map_array, i, map_width))
				i++;
			else
				return (false);
		}
		else
			return (false);
	}
	return (true);
}
