/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:39:52 by gt-serst          #+#    #+#             */
/*   Updated: 2023/12/22 17:30:57 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

int	ft_closebis(int keycode, t_window *window)
{
	if (keycode && window->mlx)
	{
		(void)window;
		exit(ft_putstr_fd("Successfully left the game, have a great day!\n", 2));
	}
	return (0);
}

bool	is_walkable(char c)
{
	if (c && (c == '3' || c == '4'))
		return (true);
	return (false);
}

int	ft_handle_input(int keycode, t_window *window)
{
	t_map	*map;

	map = window->map;
	if (keycode == 126 && window->mlx)
		move_backward(window);
	else if (keycode == 125 && window->mlx)
		move_forward(window);
	else if (keycode == 123 && window->mlx)
		rotate_left(window);
	else if (keycode == 124 && window->mlx)
		rotate_right(window);
	else if (keycode == 53 && window->mlx)
	{
		(void)window;
		ft_exit("Successfully left the game, have a great day!\n", map);
	}
	mlx_destroy_image(window->mlx, window->img);
	ft_raycasting(window->map, window);
	return (0);
}
