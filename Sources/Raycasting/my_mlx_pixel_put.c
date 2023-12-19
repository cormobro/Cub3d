#include "../../Includes/cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	//printf("X %d\n", x);
	//printf("Y %d\n", y);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

/*void	my_mlx_texturing_put()
{
}*/
