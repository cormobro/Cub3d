#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <mlx.h>

typedef struct s_window
{
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_window;

typedef struct s_img
{
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img;
	char	*addr;
}	t_img;

void	launch_graphic_env(t_map *map);
void	my_mlx_pixel_put(t_window *data, int x, int y, int color);
int	ft_close(int keycode, t_window *window);
int	ft_closebis(int keycode, t_window *window);

#endif
