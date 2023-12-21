#ifndef CHECKER_H
# define CHECKER_H

typedef struct s_map
{
	char	**maparray;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*ceiling;
	char	*floor;
	int		mapX;
	int		mapY;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	rayDirX;
	double	rayDirY;
	double	planeX;
	double	planeY;
	int		side;
	double	time;
	double	oldTime;
	double	perpWallDist;
	bool	check;
}	t_map;

bool		ft_iszero(t_map *map, int x, int y);
bool		ft_recursive_checker(t_map *map, int x, int y);
bool		map_valid(t_map *map);
bool		arg_checker(int argc, char **argv);
bool		map_checker(char **argv, t_map *map);
bool		map_extractor(int fd, t_map *map);
void		sprite_checker(t_map *map);
bool		is_surrounded_by_walls(char **map_array);

#endif
