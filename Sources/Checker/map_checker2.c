#include "../../Includes/cub3d.h"

/*bool	map_extractor(int fd, t_map *map)
{
	//char	*line;

	(void)map;
	(void)fd;
	//line = get_next_line(fd);
	while (line != NULL)
	{
		
	}
	return (true);
}*/

bool	map_extractor(int fd, t_map *map)
{
	(void)fd;

	sprite_checker(map);
	return (true);
}
