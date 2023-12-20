#include "../../Includes/cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	//printf("X %d\n", x);
	//printf("Y %d\n", y);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	get_pixel_color(t_img *texture, t_index *texture_position)
{
	int	texture_index;

	texture_index = texture->line_length * texture_position->y
		+ texture_position->x * texture->bits_per_pixel / 8;
	printf("%s\n", texture->addr);
	printf("%d\n", texture_index);
	return (*(int *)(texture->addr + texture_index));
}
