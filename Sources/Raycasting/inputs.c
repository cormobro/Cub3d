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

