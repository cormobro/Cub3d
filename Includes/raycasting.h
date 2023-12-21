#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <mlx.h>
# include <math.h>
# include <stdint.h>

# define WIDTH 1920
# define HEIGHT 1080
# define TEX_WIDTH 80
# define TEX_HEIGHT 80

typedef struct s_index
{
	int	x;
	int	y;
}	t_index;

typedef struct s_img
{
	void		*reference;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
}	t_img;

typedef struct s_window
{
	t_map	*map;
	t_img	image[4];
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_window;

void	ft_raycasting(t_map *map, t_window *window);
void	launch_graphic_env(t_map *map);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		get_pixel_color(t_img *texture, int x, int y);
int		ft_handle_inputs(int keycode, t_window *window);
int		ft_closebis(int keycode, t_window *window);
int		ft_rotate(int keycode, t_window *window);

#endif
