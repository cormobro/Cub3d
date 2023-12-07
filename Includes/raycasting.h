#ifndef RAYCASTING_H
# define RAYCASTING_H

typedef struct s_img
{
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img;
	char	*addr;
}	t_img;

#endif
