#include "../../Includes/cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	get_pixel_color(t_img *texture, int x, int y)
{
	int	texture_index;

	texture_index = texture->line_length * y + x * (texture->bits_per_pixel / 8);
	return (*(int *)(texture->addr + texture_index));
}
