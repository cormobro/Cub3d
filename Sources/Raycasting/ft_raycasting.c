#include "../../Includes/cub3d.h"

static bool	dda_algo(t_map *map, double rayDirX, double rayDirY)
{
	int	mapX;
	int	mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int	stepX;
	int	stepY;
	int	hit;
	int	side;

	mapX = int(map->posX);
	mapY = int(map->posY);
	hit = 0;
	//Calcul de la distance X/Y entre deux cases
	if (map->rayDirX == 0)
		deltaDistX = 1e30;
	else
		deltaDistX = abs(1 / rayDirX);
	if (map->rayDirY == 0)
		deltaDistY = 1e30;
	else
		deltaDistY = abs(1 / rayDirY);
	//Calcul de la distance X/Y entre le joueur et la premiere intersection avec une autre case
	if (rayDirX < 0)
	{
		stepX = -1;
		sideDistX = (map->posX - mapX) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = (mapX + 1.0 - map->posX) * deltaDistX;
	}
	if (rayDirY < 0)
	{
		stepY = -1;
		sideDistY = (map->posY - mapY) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (mapY + 1.0 - map->posY) * deltaDistY;
	}
	while (hit == 0)
	{
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
		}
		//INTERCHANGER X ET Y ?
		if (map->maparray[mapX][mapY] == 1)
			hit = 1;
	}
}

void	ft_raycasting(t_map *map, t_window *window)
{
	int	x;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;

	x = 0;
	while (x < WIDTH)
	{
		cameraX = 2 * (double)x / double(WIDTH) - 1;
		rayDirX = (map->dirX + map->planeX) * cameraX;
		rayDirY = (map->dirY + map->planeY) * cameraX;
		x++;
	}
}
