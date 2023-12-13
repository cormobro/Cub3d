#include "../../Includes/cub3d.h"

static bool	dda_algo(t_map *map, double rayDirX, double rayDirY)
{
	int	mapX;
	int	mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	int	stepX;
	int	stepY;
	int	hit;
	int	side;

	mapX = (int)(map->posX);
	mapY = (int)(map->posY);
	hit = 0;
	//Calcul de la distance X/Y entre deux cases
	if (rayDirX == 0)
		deltaDistX = 1e30;
	else
		deltaDistX = fabs(1 / rayDirX);
	if (rayDirY == 0)
		deltaDistY = 1e30;
	else
		deltaDistY = fabs(1 / rayDirY);
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
		if (map->maparray[mapX][mapY] == '1')
			hit = 1;
	}
	if (side == 0)
	{
		map->perpWallDist = sideDistX - deltaDistX;
		return (false);
	}
	else
		map->perpWallDist = sideDistY - deltaDistY;
	return (true);

}

static void	paintVerticalStripe(t_map *map, t_window *window, int orientation, int x)
{
	int	lineHeight;
	int	drawStart;
	int	drawEnd;
	(void)orientation;

	lineHeight = (int)((double)HEIGHT / map->perpWallDist);
	drawStart = (double)HEIGHT / 2 - lineHeight / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = (double)HEIGHT / 2 + lineHeight / 2;
	if (drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;
	while (drawEnd >= drawStart)
	{
		my_mlx_pixel_put(window->img, x, drawEnd, 0x0019071A);
		drawEnd--;
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
		cameraX = 2 * (double)x / (double)(WIDTH) - 1;
		rayDirX = (map->dirX + map->planeX) * cameraX;
		rayDirY = (map->dirY + map->planeY) * cameraX;
		if (dda_algo(map, rayDirX, rayDirY) == false)
		{
			if (rayDirX < 0)
			{
				//mur ouest
				paintVerticalStripe(map, window, 0, x);

			}
			else
			{
				//mur est
				paintVerticalStripe(map, window, 1, x);
			}
		}
		else
		{
			if (rayDirY < 0)
			{
				//mur sud
				paintVerticalStripe(map, window, 2, x);
			}
			else
			{
				//mur nord
				paintVerticalStripe(map, window, 3, x);
			}
		}
		x++;
	}
}
