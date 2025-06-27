/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:43:39 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/27 19:43:52 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_background(t_vars *vars, t_texture *texture)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEI)
	{
		x = 0;
		while (x < WIN_LEN)
		{
			if (y < WIN_HEI / 2)
				my_mlx_pixel_put(&vars->img, x, y, texture->ceiling.color);
			else
				my_mlx_pixel_put(&vars->img, x, y, texture->floor.color);
			x++;
		}
		y++;
	}
}
