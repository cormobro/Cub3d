#include "../../Includes/cub3d.h"

int	ft_close(int keycode, t_window *window)
{
	if (keycode == 53 && window->mlx)
	{
		(void)window;
		ft_exit("Successfully left the game, have a great day!\n");
	}
	return (0);
}

int	ft_closebis(int keycode, t_window *window)
{
	if (keycode && window->mlx)
	{
		(void)window;
		ft_exit("Successfully left the game, have a great day!\n");
	}
	return (0);
}

static bool	is_walkable(char c)
{
	printf("Char C %c\n", c);
	if (c == '3')
		return (true);
	return (false);
}

int	ft_handle_inputs(int keycode, t_window *window)
{
	double	oldDirX;
	double	oldPlaneX;

	if (keycode == 126 && window->mlx)
	{
		if (is_walkable(window->map->maparray[(int)(window->map->posX + window->map->dirX + 0.6)][(int)(window->map->posY + 0.6)]) == 1)
			window->map->posX += window->map->dirX;
		if (is_walkable(window->map->maparray[(int)(window->map->posX + 0.6)][(int)(window->map->posY + window->map->dirY + 0.6)]))
			window->map->posY += window->map->dirY;
		printf("ARRIERE\n");
	}
	else if (keycode == 125 && window->mlx)
	{
		if (is_walkable(window->map->maparray[(int)(window->map->posX - window->map->dirX - 0.6)][(int)(window->map->posY - 0.6)]) == 1)
			window->map->posX -= window->map->dirX;
		if (is_walkable(window->map->maparray[(int)(window->map->posX - 0.6)][(int)(window->map->posY - window->map->dirY - 0.6)]))
			window->map->posY -= window->map->dirY;
		printf("DEVANT\n");
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
		//ft_raycasting(window->map, window);
		printf("%f %f\n", window->map->planeX, window->map->planeY);
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
		//ft_raycasting(window->map, window);
		printf("DROITE\n");
		//return (1);
	}
	else if (keycode == 53 && window->mlx)
	{
		(void)window;
		ft_exit("Successfully left the game, have a great day!\n");
	}
	ft_raycasting(window->map, window);
	return (0);
}

