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

int	ft_handle_inputs(int keycode, t_window *window)
{
	//double	oldDirX;
	//double	oldPlaneX;

	if (keycode == 123 && window->mlx)
	{
		//turn left
		/*oldDirX = map->dirX;
		map->dirX = map->dirX * cos(10) - map->dirY * sin(10);
		map->dirY = oldDirX * sin(10) + map->dirY * cos(10);
		oldPlaneX = map->planeX;
		map->planeX = map->planeX * cos(10) - map->planeY * sin(10);
		map->planeY = oldPlaneX * sin(10) + map->planeY * cos(10);*/
		printf("GAUCHE\n");
		return (1);
	}
	else if (keycode == 124 && window->mlx)
	{
		//turn right
		/*oldDirX = map->dirX;
		map->dirX = map->dirX * cos(-10) - map->dirY * sin(-10);
		map->dirY = oldDirX * sin(-10) + map->dirY * cos(-10);
		oldPlaneX = map->planeX;
		map->planeX = map->planeX * cos(-10) - map->planeY * sin(-10);
		map->planeY = oldPlaneX * sin(-10) + map->planeY * cos(-10);*/
		printf("DROITE\n");
		return (1);
	}
	else if (keycode == 53 && window->mlx)
	{
		(void)window;
		ft_exit("Successfully left the game, have a great day!\n");
	}
	return (0);
}

