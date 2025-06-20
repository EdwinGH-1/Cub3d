/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:35:32 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/20 15:48:14 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	in_circle(int x, int y)
{
	int	v1;
	int	v2;

	v1 = (int)x - MINI_RAD - MINI_POS;
	v2 = (int)y - MINI_RAD - MINI_POS;
	if (((v1 * v1) + (v2 * v2)) <= (MINI_RAD * MINI_RAD))
		return (true);
	return (false);
}

void	draw_player(t_meta *meta)
{
	int	count_x;
	int	count_y;

	count_y = 0;
	while (count_y < P_SIZE)
	{
		count_x = 0;
		while (count_x < P_SIZE)
		{
			my_mlx_pixel_put(meta,
				MINI_RAD + MINI_POS + count_x - (P_SIZE / 2),
				MINI_RAD + MINI_POS + count_y - (P_SIZE / 2),
				P_COLOR);
			count_x++;
		}
		count_y++;
	}
}

void	draw_circle(t_meta *meta)
{
	int	x;
	int	y;
	int	d;
	int	centre;

	x = 0;
	y = MINI_RAD;
	centre = MINI_RAD + MINI_POS;
	d = 3 - (2 * y);
	while (x <= y)
	{
		my_mlx_pixel_put(meta, x + centre, y + centre, MINI_BORDER);
		my_mlx_pixel_put(meta, -x + centre, y + centre, MINI_BORDER);
		my_mlx_pixel_put(meta, x + centre, -y + centre, MINI_BORDER);
		my_mlx_pixel_put(meta, -x + centre, -y + centre, MINI_BORDER);
		my_mlx_pixel_put(meta, y + centre, x + centre, MINI_BORDER);
		my_mlx_pixel_put(meta, -y + centre, x + centre, MINI_BORDER);
		my_mlx_pixel_put(meta, y + centre, -x + centre, MINI_BORDER);
		my_mlx_pixel_put(meta, -y + centre, -x + centre, MINI_BORDER);
		if (d < 0)
			d = d + (4 * x) + 6;
		else
			d = d + 4 * (x - (y--)) + 10;
		x++;
	}
}

void	draw_grid(t_meta *meta, t_pixel pixel, int count_x, int count_y)
{
	int		val_x;
	int		val_y;

	val_x = pixel.x * MINI_SIZE + count_x + meta->map.x_offset;
	val_y = pixel.y * MINI_SIZE + count_y + meta->map.y_offset;
	if (in_circle(val_x, val_y))
	{
		if (count_x == MINI_SIZE - 1 || count_y == MINI_SIZE - 1
			|| count_x == 0 || count_y == 0)
			my_mlx_pixel_put(meta, val_x, val_y, MINI_BORDER);
		else if (pixel.value != 1 && pixel.value != -1)
			my_mlx_pixel_put(meta, val_x, val_y, 0xffffff);
	}
}

void	render_minimap(t_meta *meta)
{
	int	x;
	int	y;
	int	count_x;
	int	count_y;

	y = 0;
	while (y < meta->map.y_max)
	{
		x = 0;
		while (x < meta->map.x_max)
		{
			count_y = 0;
			while (count_y < MINI_SIZE)
			{
				count_x = 0;
				while (count_x < MINI_SIZE)
					draw_grid(meta,
						meta->map.pixel[y][x], count_x++, count_y);
				count_y++;
			}
			x++;
		}
		y++;
	}
}
