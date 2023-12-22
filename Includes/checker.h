#ifndef CHECKER_H
# define CHECKER_H

bool		ft_iszero(t_map *map, int x, int y);
bool		ft_recursive_checker(t_map *map, int x, int y);
bool		map_valid(t_map *map);
bool		arg_checker(int argc, char **argv);
bool		map_checker(char **argv, t_map *map);
bool		map_extractor(int fd, t_map *map);
void		sprite_checker(t_map *map);
bool		is_surrounded_by_walls(char **map_array);

#endif
