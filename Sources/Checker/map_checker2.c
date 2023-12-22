/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:33:20 by febonaer          #+#    #+#             */
/*   Updated: 2023/12/22 14:33:22 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static void	getplayerdir(t_map *map, char c)
{
	if (c == 69)
	{
		map->planeY = 0;
		map->planeX = 0.66;
		map->dirY = 1;
	}
	else if (c == 78)
		map->dirX = -1;
	else if (c == 83)
	{
		map->dirX = 1;
		map->planeX = 0;
		map->planeY = -0.66;
	}
	else
	{
		map->planeY = 0;
		map->planeX = -0.66;
		map->dirY = -1;
	}
}

static bool	map_precheck2(char *stack, t_map *map)
{
	int	i;

	i = 0;
	while (stack[i] && (stack[i] == 48 || ft_isspace(stack[i])
			|| stack[i] == '\n' || stack[i] == 49 || stack[i] == 69
			|| stack[i] == 78 || stack[i] == 83 || stack[i] == 87))
	{
		if (stack[i] == 69 || stack[i] == 78
			|| stack[i] == 83 || stack[i] == 87)
		{
			if (map->check == true)
				return (false);
			getplayerdir(map, stack[i]);
			map->check = true;
		}
		i++;
	}
	return (true);
}

static bool	map_precheck(int fd, t_map *map)
{
	char	*stack;
	char	*line;

	stack = NULL;
	line = get_next_line(fd);
	if (!line)
		ft_exit("Error\nAllocation failed\n", map);
	while (line != NULL)
	{
		stack = ft_strjoin(stack, line);
		if (!stack)
			ft_exit("Error\nAllocation failed\n", map);
		free(line);
		line = get_next_line(fd);
	}
	if (!map_precheck2(stack, map))
	{
		free(stack);
		return (false);
	}
	map->maparray = ft_split(stack, '\n');
	if (!map->maparray)
		ft_exit("Error\nAllocation failed\n", map);
	return (true);
}

bool	map_extractor(int fd, t_map *map)
{
	sprite_checker(map);
	map->check = false;
	if (!map_precheck(fd, map) || map->check == false || !map_valid(map))
		ft_exit("Error\nSyntax error in the map\n", map);
	return (true);
}
