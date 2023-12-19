/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:02:52 by gt-serst          #+#    #+#             */
/*   Updated: 2023/12/19 17:31:21 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static bool	is_walkable(char c)
{
	//printf("Char C %c\n", c);
	if (c != '1')
		return (true);
	return (false);
}

int	ft_handle_inputs2(int keycode, t_window *window)
{
	//int i = 0;
	//while (window->map->maparray[i])
	//	printf("%s\n", window->map->maparray[i++]);
	if (keycode == 126 && window->mlx)
	{
		if (is_walkable(window->map->maparray[(int)window->map->posX + (int)window->map->dirX][(int)window->map->posY]) == 1)
			window->map->posX += window->map->dirX;
		if (is_walkable(window->map->maparray[(int)window->map->posX][(int)window->map->posY + (int)window->map->dirY]))
			window->map->posY += window->map->dirY;
		printf("ARRIERE\n");
	}
	if (keycode == 125 && window->mlx)
	{
		if (is_walkable(window->map->maparray[(int)window->map->posX - (int)window->map->dirX][(int)window->map->posY]) == 1)
			window->map->posX -= window->map->dirX;
		if (is_walkable(window->map->maparray[(int)window->map->posX][(int)window->map->posY - (int)window->map->dirY]))
			window->map->posY -= window->map->dirY;
		printf("DEVANT\n");
	}
	printf("PosX %f\n", window->map->posX);
	printf("PosY %f\n", window->map->posY);
	ft_raycasting(window->map, window);
	return (0);
}
