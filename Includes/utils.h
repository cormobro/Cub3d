#ifndef UTILS_H
# define UTILS_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_map
{
	char	**maparray;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*ceiling;
	char	*floor;
	double	hexfloor;
	double	hexceiling;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	perpWallDist;
	bool	check;
}	t_map;

int	ft_strlen(const char *str);
int	ft_putstr_fd(char const *s, int fd);
char	**ft_split(char const *str, char c);
int	ft_isnumber(char *s);
int	ft_atoi(const char *str);
int	ft_isspace(int c);
void	ft_exit(char *str, t_map *map);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
