#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <mlx.h>
# include <math.h>

# define WIDTH 1080
# define HEIGHT 720
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef struct s_window
{
	t_map	*map;
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

void	ft_raycasting(t_map *map, t_window *window);
void	launch_graphic_env(t_map *map);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	my_mlx_texturing_put();
int	ft_handle_inputs(int keycode, t_window *window);
int	ft_closebis(int keycode, t_window *window);
int	ft_rotate(int keycode, t_window *window);
int	ft_handle_inputs2(int keycode, t_window *window);

#endif
