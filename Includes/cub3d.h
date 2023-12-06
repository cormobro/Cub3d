#ifndef CUB3D_H
# define CUB3D_H

# include "utils.h"
# include "get_next_line.h"
# include "checker.h"
//# include <mlx.h>

# define BUFFER_SIZE 50
typedef struct s_img
{
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img;
	char	*addr;
}	t_img;

int		main(int argc, char **argv);
//void	my_mlx_pixel_put(t_complex *data, int x, int y, int color);

#endif
