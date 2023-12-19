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

void	launch_graphic_env(t_map *map)
{
	t_window window;

	window.map = map;
	find_player_coords(map);
	window.mlx = mlx_init();
	if (window.mlx == NULL)
	{
		(void)window;
		ft_exit("Error: Failed to launch the MLX\n");
	}
	window.mlx_win = mlx_new_window(window.mlx, WIDTH, HEIGHT, "CUB3D");
	window.img = mlx_new_image(window.mlx, WIDTH, HEIGHT);
	window.addr = mlx_get_data_addr(window.img, &window.bits_per_pixel, &window.line_length, &window.endian);
	ft_raycasting(map, &window);
	//window.img = mlx_xpm_file_to_image(window.mlx, map->north, &window.line_length, &window.endian);
	//mlx_put_image_to_window(window.mlx, window.mlx_win, window.img, 0, 0);
	mlx_hook(window.mlx_win, 17, 0, ft_closebis, &window);
	mlx_key_hook(window.mlx_win, ft_handle_inputs, &window);
	mlx_loop(window.mlx);
}
