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
	int		map_x;
	int		map_y;
	double	hexfloor;
	double	hexceiling;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	plane_x;
	double	plane_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	tex_pos;
	double	time;
	double	old_time;
	double	perp_wall_dist;
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
