#include "../../Includes/cub3d.h"

int	ft_closebis(int keycode, t_window *window)
{
	t_map *map;

	map = window->map;
	if (keycode && window->mlx)
	{
		(void)window;
		ft_exit("Successfully left the game, have a great day!\n", map);
	}
	return (0);
}

static bool	is_walkable(char c)
{
	if (c && (c == '3' || c == '4'))
		return (true);
	return (false);
}

int	ft_handle_inputs(int keycode, t_window *window)
{
	double	oldDirX;
	double	oldPlaneX;
	t_map	*map;

	map = window->map;
	if (keycode == 126 && window->mlx)
	{
		if (is_walkable(window->map->maparray[(int)(window->map->posX + window->map->dirX)][(int)(window->map->posY)]) == 1)
			window->map->posX += window->map->dirX / 2;
		if (is_walkable(window->map->maparray[(int)(window->map->posX)][(int)(window->map->posY + window->map->dirY)]))
			window->map->posY += window->map->dirY / 2;
	}
	else if (keycode == 125 && window->mlx)
	{
		if (is_walkable(window->map->maparray[(int)(window->map->posX - window->map->dirX)][(int)(window->map->posY)]) == 1)
			window->map->posX -= window->map->dirX / 2;
		if (is_walkable(window->map->maparray[(int)(window->map->posX)][(int)(window->map->posY - window->map->dirY)]))
			window->map->posY -= window->map->dirY / 2;
	}
	else if (keycode == 123 && window->mlx)
	{
		//turn left
		oldDirX = window->map->dirX;
		window->map->dirX = window->map->dirX * cos(0.1) - window->map->dirY * sin(0.1);
		window->map->dirY = oldDirX * sin(0.1) + window->map->dirY * cos(0.1);
		oldPlaneX = window->map->planeX;
		window->map->planeX = window->map->planeX * cos(0.1) - window->map->planeY * sin(0.1);
		window->map->planeY = oldPlaneX * sin(0.1) + window->map->planeY * cos(0.1);
		//return (1);
	}
	else if (keycode == 124 && window->mlx)
	{
		//turn right
		oldDirX = window->map->dirX;
		window->map->dirX = window->map->dirX * cos(-0.1) - window->map->dirY * sin(-0.1);
		window->map->dirY = oldDirX * sin(-0.1) + window->map->dirY * cos(-0.1);
		oldPlaneX = window->map->planeX;
		window->map->planeX = window->map->planeX * cos(-0.1) - window->map->planeY * sin(-0.1);
		window->map->planeY = oldPlaneX * sin(-0.1) + window->map->planeY * cos(-0.1);
		//return (1);
	}
	else if (keycode == 53 && window->mlx)
	{
		(void)window;
		ft_exit("Successfully left the game, have a great day!\n", map);
	}
	ft_raycasting(window->map, window);
	return (0);
}

