#include "../../Includes/cub3d.h"

static void	find_player_coords(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->maparray[x])
	{
		y = 0;
		while (map->maparray[x][y])
		{
			if (map->maparray[x][y] == '4')
			{
				map->posX = (double)x;
				map->posY = (double)y;
				break ;
			}
			y++;
		}
		x++;
	}
}

static void	init_image(t_window *window)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
			window->image[i].reference = mlx_xpm_file_to_image(window->mlx, window->map->north, &window->image[i].line_length, &window->image[i].endian);
		if (i == 1)
			window->image[i].reference = mlx_xpm_file_to_image(window->mlx, window->map->south, &window->image[i].line_length, &window->image[i].endian);
		if (i == 2)
			window->image[i].reference = mlx_xpm_file_to_image(window->mlx, window->map->west, &window->image[i].line_length, &window->image[i].endian);
		if (i == 3)
			window->image[i].reference = mlx_xpm_file_to_image(window->mlx, window->map->east, &window->image[i].line_length, &window->image[i].endian);

		if (window->image[i].reference == NULL)
			ft_exit("Error: could not load an image\n");
		window->image[i].addr = mlx_get_data_addr(window->image[i].reference, &window->image[i].bits_per_pixel, &window->image[i].line_length, &window->image[i].endian);
		i++;
	}
}

void	launch_graphic_env(t_map *map)
{
	t_window window;

	window.map = map;
	find_player_coords(map);
	window.mlx = mlx_init();
	if (window.mlx == NULL)
	{
		(void)window;
		ft_exit("Error\nFailed to launch the MLX\n");
	}
	window.mlx_win = mlx_new_window(window.mlx, WIDTH, HEIGHT, "CUB3D");
	init_image(&window);
	window.img = mlx_new_image(window.mlx, WIDTH, HEIGHT);
	window.addr = mlx_get_data_addr(window.img, &window.bits_per_pixel, &window.line_length, &window.endian);
	ft_raycasting(map, &window);
	mlx_hook(window.mlx_win, 2, (1L << 0), ft_handle_inputs, &window);
	mlx_loop(window.mlx);
}
