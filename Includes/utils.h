#ifndef UTILS_H
# define UTILS_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>

int	ft_strlen(const char *str);
int	ft_putstr_fd(char const *s, int fd);
char	**ft_split(char const *str, char c);
int	ft_isnumber(char *s);
int	ft_atoi(const char *str);
int	ft_isspace(int c);
void	ft_exit(char *str);

#endif
