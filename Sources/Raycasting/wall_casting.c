/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:33:25 by geraudtsers       #+#    #+#             */
/*   Updated: 2023/12/12 17:16:06 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

void init_wall_casting()
{
	//receive in arguments x and y start position (double variables), initial direction vector (N,S,E,W) and the camera plane
	double posX, posY;  //x and y start position vector
	double dirX, dirY; //initial direction vector pointing inside the screen
	double planeX = 0, planeY = 0.66; //surface vector of the computer screen

	//calculate ray position and direction

	//for each vertical line (X) on screen
	double cameraX = 2 * x / (double)w - 1; //x is the start position and w is the map width
	double rayDirX = posX + dirX + planeX * cameraX;
	double rayDirY = posY + dirY + planeY *cameraX;

	//To rotate a vector, multiply it with the rotation matrix

	compute_next_side_dist(rayDirX, rayDirY);

	//box of the map the current position belongs to
	int mapX = (int)posX;
	int mapY = (int)posY;

	//direction to step in X or Y direction (either +1 or -1)
	int stepX;
	int stepY;
	compute_side_dist(mapX, mapY, stepX, stepY);

	dda_algo();

	//calculate height of line to draw on screen
	compute_ray_perp_dist();
	compute_stripe_to_draw();

	//choose a sprite to draw depend on which side of the wall was hit
}

double	compute_side_dist()
{
	double sideDistX;
	double sideDistY;
	//compute the distance of the ray between the current position to the
	//next horizontal (Y) or vertical (X) line
}

double	compute_next_side_dist(double rayDirX, double rayDirY)
{
	double deltaDistX;
	double deltaDistY;
	//compute the distance of the ray between one horizontal (Y) or vertical (X)
	//line to the next horizontal (Y) or vertical (X) line
	deltaDistX = abs(1 / rayDirX);
	deltaDistY = abs(1 / rayDirY);
}

bool	dda_algo()
{
	//as long as no wall is detected, continue to advance to the next square on the map
}

double	compute_ray_perp_dist()
{
	double perWallDist;
	//calculate distance of perpendicular ray to the wall encountered
}

int	compute_stripe_to_draw(double perWallDist)
{
	int stripeHeight;
	//calculate height of line to draw on screen
	stripeHeight = (int)(h / perpWallDist); //h is the screen height

	//calculate lowest and highest pixel to fill in current stripe
}
