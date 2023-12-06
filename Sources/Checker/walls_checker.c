#include "../../Includes/cub3d.h"

/*static bool	hole_is_blocked(char **map_array, size_t i, size_t j, char type)
{
	// top check if three walls are placed below the hole
	if (type == 'T' && map_array[i + 1][j] == '1' && map_array[i + 1][j + 1] == '1'
		&& map_array[i + 1][j - 1] == '1')
		return (true);
	// bottom check if three walls are placed above the hole
	if (type == 'B' && map_array[i - 1][j] == '1' && map_array[i - 1][j + 1] == '1'
		&& map_array[i - 1][j - 1] == '1')
		return (true);
	// left check if three walls are placed right of the hole
	if (type == 'L' && map_array[i][j + 1] == '1' && map_array[i + 1][j + 1] == '1'
		&& map_array[i - 1][j + 1] == '1')
		return (true);
	// right check if three walls are placed left of the hole
	if (type == 'R' && map_array[i][j - 1] == '1' && map_array[i + 1][j - 1] == '1'
		&& map_array[i - 1][j - 1] == '1')
		return (true);
	return (false);
}*/

static bool	find_next_wall(char **map_array, size_t i, size_t j, char type)
{
	//printf("%s\n", map_array[i]);
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
	if (top_and_bottom(map_array, 0, 0, 'T') && top_and_bottom(map_array, map_height - 1, 0, 'B')
		&& left(map_array, 0, 0, 'L') && right(map_array, 0, 'R'))
		return (true);
	else
		return (false);
}

/*bool	is_surrounded_by_walls(char **map_array)
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
	while (map_array[0][j])
	{
		if (map_array[0][j] == '1')
			j++;
		else if (map_array[0][j] == ' ')
		{
			if (find_next_wall(map_array, 0, j, 'T'))
				j++;
			else
				return (false);
		}
		else
			return (false);
	}
	printf("%zu\n", j);
	j = 0;
	// bottom walls check
	while (map_array[map_height - 1][j])
	{
		if (map_array[map_height - 1][j] == '1')
			j++;
		else if (map_array[map_height - 1][j] == ' ')
		{
			if (find_next_wall(map_array, map_height - 1, j, 'B'))
				j++;
			else
				return (false);
		}
		else
			return (false);
	}
	printf("%zu\n", j);
	i = 0;
	// left walls check
	while(map_array[i] && map_array[i][0])
	{
		if (map_array[i][0] == '1')
			i++;
		else if (map_array[i][0] == ' ')
		{
			if (find_next_wall(map_array, i, 0, 'L'))
				i++;
			else
				return (false);
		}
		else
			return (false);
	}
	printf("%zu\n", i);
	i = 0;
	// right walls check
	while (map_array[i] && map_array[i][ft_strlen(map_array[i]) - 1])
	{
		if (map_array[i][ft_strlen(map_array[i]) - 1] == '1')
			i++;
		else if (map_array[i][ft_strlen(map_array[i]) - 1] == ' ')
		{
			if (find_next_wall(map_array, i, ft_strlen(map_array[i]) - 1, 'R'))
				i++;
			else
				return (false);
		}
		else
			return (false);
	}
	printf("%zu\n", i);
	return (true);
}*/
