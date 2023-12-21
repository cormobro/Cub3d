/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:13:09 by gt-serst          #+#    #+#             */
/*   Updated: 2023/12/21 19:28:32 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static bool	dda_algo(t_map *map)
{
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	int	stepX;
	int	stepY;
	int	hit;

	map->mapX = (int)(map->posX);
	map->mapY = (int)(map->posY);
	//printf("mapX %d\n", mapX);
	//printf("mapY %d\n", mapY);
	hit = 0;
	//Calcul de la distance X/Y entre deux cases
	if (map->rayDirX == 0)
		deltaDistX = 1e30;
	else
		deltaDistX = fabs(1 / map->rayDirX);
	if (map->rayDirY == 0)
		deltaDistY = 1e30;
	else
		deltaDistY = fabs(1 / map->rayDirY);
	//Calcul de la distance X/Y entre le joueur et la premiere intersection avec une autre case
	if (map->rayDirX < 0)
	{
		stepX = -1;
		sideDistX = (map->posX - map->mapX) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = (map->mapX + 1.0 - map->posX) * deltaDistX;
	}
	if (map->rayDirY < 0)
	{
		stepY = -1;
		sideDistY = (map->posY - map->mapY) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (map->mapY + 1.0 - map->posY) * deltaDistY;
	}
	while (hit == 0)
	{
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			map->mapX += stepX;
			map->side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			map->mapY += stepY;
			map->side = 1;
		}
		//INTERCHANGER X ET Y ?
		if (map->maparray[map->mapX][map->mapY] == '1')
			hit = 1;
	}
	if (map->side == 0)
	{
		map->perpWallDist = sideDistX - deltaDistX;
		return (false);
	}
	else
		map->perpWallDist = sideDistY - deltaDistY;
	//printf("perpWallDist %f\n", map->perpWallDist);
	return (true);

}

static void	paintVerticalStripe(t_map *map, t_img *image, int x, t_img *texture)
{
	int	lineHeight;
	int	drawStart;
	int	drawEnd;
	int	y;
	double	wallX;
	int		texX;
	int		texY;
	double	step;
	double	texPos;
	int		color;

	if (map->perpWallDist == 0)
		map->perpWallDist = 1e30;
	lineHeight = (int)(HEIGHT / map->perpWallDist);
	drawStart = HEIGHT / 2 - lineHeight / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = HEIGHT / 2 + lineHeight / 2;
	if (drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;
	//calculate value of where exactly the wall was hit
	if (map->side == 0)
		wallX = map->posY + map->perpWallDist * map->rayDirY;
	else
		wallX = map->posX + map->perpWallDist * map->rayDirX;
	wallX -= floor((wallX));
	//printf("wallX %f\nraydir %f\n", wallX, map->rayDirX);
	//x coordinate on the texture
	texX = (int)(wallX * TEX_WIDTH);
	if (map->side == 0 && map->rayDirX > 0)
		texX = TEX_WIDTH - texX - 1;
	if (map->side == 1 && map->rayDirY < 0)
		texX = TEX_WIDTH - texX - 1;
	//how much to increase the texture coordinate per screen pixel
	step = 1.0 * TEX_HEIGHT / lineHeight;
	//calculate position on the y axis in the texture we are
	texPos = (drawStart - HEIGHT / 2 + lineHeight / 2) * step;
	y = drawStart;
	//printf("drawStart%d\n", drawStart);
	//printf("drawEnd%d\n", drawEnd);
	while (y <= drawEnd)
	{
		//printf("Y%d\n", y);
		//cast the texture coordinate to integer and mask in case of overflow
		texY = (int)texPos;
		texPos += step;
		color = get_pixel_color(texture, texX, texY);
		//printf("Color %06x\n", color);
		my_mlx_pixel_put(image, x, y, color);
		y++;
	}
	y = 0;
	while (y < drawStart)
	{
		my_mlx_pixel_put(image, x, y, (int)map->hexceiling);
		y++;
	}
	y = HEIGHT - 1;
	while (y > drawEnd)
	{
		my_mlx_pixel_put(image, x, y, (int)map->hexfloor);
		y--;
	}
	/*while (drawEnd >= drawStart)
	{

		if (orientation == 0)
			my_mlx_pixel_put(image, x, drawEnd, 0xab4c20);
		else if (orientation == 1)
			my_mlx_pixel_put(image, x, drawEnd, 0x56ab20);
		else if (orientation == 2)
			my_mlx_pixel_put(image, x, drawEnd, 0xa219d4);
		else
			my_mlx_pixel_put(image, x, drawEnd, 0xfc0008);
		drawEnd--;
	}*/
}

void	ft_raycasting(t_map *map, t_window *window)
{
	int	x;
	double	cameraX;
	t_img	img;

	img.reference = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_length, &img.endian);
	x = 0;
	while (x < WIDTH)
	{
		cameraX = 2 * (double)x / (double)(WIDTH) - 1;
		map->rayDirX = map->dirX + map->planeX * cameraX;
		map->rayDirY = map->dirY + map->planeY * cameraX;
		if (dda_algo(map) == false)
		{
			if (map->rayDirX < 0)
			{
				//mur ouest
				paintVerticalStripe(map, &img, x, &window->image[0]);

			}
			else
			{
				//mur est
				paintVerticalStripe(map, &img, x, &window->image[1]);
			}
		}
		else
		{
			if (map->rayDirY < 0)
			{
				//mur sud
				paintVerticalStripe(map, &img, x, &window->image[2]);
			}
			else
			{
				//mur nord
				paintVerticalStripe(map, &img, x, &window->image[3]);
			}
		}
		x++;
	}
	window->img = img.reference;
	mlx_put_image_to_window(window->mlx, window->mlx_win, window->img, 0, 0);
}
