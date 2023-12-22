#include "../../Includes/cub3d.h"

static bool	find_next_wall(char **map_array, size_t i, size_t j, char type)
{
	while (map_array[i][j])
	{
		if (map_array[i][j] == '1')
			return (true);
		else if (map_array[i][j] == '0')
			return (false);
		else
		{
			if (type == 'T')
				i++;
			if (type == 'B')
				i--;
			if (type == 'L')
				j++;
			if (type == 'R')
				j--;
		}
	}
	return (false);
}

bool	top_and_bottom(char **map_array, size_t i, size_t j, char type)
{
	while (map_array[i] && map_array[i][j])
	{
		if (map_array[i][j] == '1')
			j++;
		else if (map_array[i][j] == ' ')
		{
			if (find_next_wall(map_array, i, j, type))
				j++;
			else
				return (false);
		}
		else
			return (false);
	}
	return (true);
}

bool	left(char **map_array, size_t i, size_t j, char type)
{
	while (map_array[i] && map_array[i][j])
	{
		if (map_array[i][j] == '1')
			i++;
		else if (map_array[i][j] == ' ')
		{
			if (find_next_wall(map_array, i, j, type))
				i++;
			else
				return (false);
		}
		else
			return (false);
	}
	return (true);
}

bool	right(char **map_array, size_t i, char type)
{
	while (map_array[i] && map_array[i][ft_strlen(map_array[i]) - 1])
	{
		if (map_array[i][ft_strlen(map_array[i]) - 1] == '1')
			i++;
		else if (map_array[i][ft_strlen(map_array[i]) - 1] == ' ')
		{
			if (find_next_wall(map_array, i, ft_strlen(map_array[i]) - 1, type))
				i++;
			else
				return (false);
		}
		else
			return (false);
	}
	return (true);
}

bool	is_surrounded_by_walls(char **map_array)
{
	size_t	map_height;

	map_height = 0;
	while (map_array[map_height])
		map_height++;
	if (top_and_bottom(map_array, 0, 0, 'T')
		&& top_and_bottom(map_array, map_height - 1, 0, 'B')
		&& left(map_array, 0, 0, 'L') && right(map_array, 0, 'R'))
		return (true);
	else
		return (false);
}
