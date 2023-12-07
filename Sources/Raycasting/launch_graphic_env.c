#include "../../Includes/cub3d.h"

void	launch_graphic_env(t_map *map)
{
	(void)map;
	t_window window;

	window.mlx = mlx_init();
	if (window.mlx == NULL)
	{
		(void)window;
		ft_exit("Error: Failed to launch the MLX\n");
	}
	window.mlx_win = mlx_new_window(window.mlx, 1000, 1000, "CUB3D");
	window.img = mlx_new_image(window.mlx, 1000, 1000);
	window.addr = mlx_get_data_addr(window.img, &window.bits_per_pixel, &window.line_length, &window.endian);
	mlx_hook(window.mlx_win, 17, 0, ft_closebis, &window);
	mlx_key_hook(window.mlx_win, ft_close, &window);
	mlx_loop(window.mlx);
}
