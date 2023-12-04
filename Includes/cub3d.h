#ifndef CUB3D_H
# define CUB3D_H

# include "utils.h"
# include "get_next_line.h"
//# include <mlx.h>

//# define WIDTH 1000
//# define LENGTH 1000
# define BUFFER_SIZE 50
typedef struct s_img
{
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img;
	char	*addr;
}	t_img;

typedef struct s_map
{
	char	**maparray;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*ceiling;
	char	*floor;
	bool	check;
}	t_map;

int		main(int argc, char **argv);
bool		arg_checker(int argc, char **argv);
bool		map_checker(char **argv, t_map *map);
bool		map_extractor(int fd, t_map *map);
int		ft_putstr_fd(char const *s, int fd);
//void	my_mlx_pixel_put(t_complex *data, int x, int y, int color);

#endif
