/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:39:07 by jothomas          #+#    #+#             */
/*   Updated: 2025/07/07 15:43:46 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	cross_hair(t_meta *meta)
{
	int	x;
	int	y;

	x = WINX / 2 - 10;
	y = WINY / 2 - 10;
	while (x <= 10)
	{
		my_mlx_pixel_put(meta, x, y, 0xffffff);
		x++;
	}
	while (y <= 10)
	{
		my_mlx_pixel_put(meta, x, y, 0xffffff);
		y--;
	}

}

void	animation(t_meta *meta)
{
	int				x;
	int				y;
	int				dst_x;
	int				dst_y;
	unsigned int	color;

	dst_x = (WINX - meta->map.sprite.width) / 2;
	dst_y = WINY / 2 - meta->map.sprite.height;
	y = -1;
	cross_hair(meta);
	while (++y < meta->map.sprite.height)
	{
		x = -1;
		while (++x < meta->map.sprite.width)
		{
			color = *(unsigned int *)meta->map.sprite.addr
				+ y * meta->map.sprite.line_length
				+ x * (meta->map.sprite.bpp / 8);
			my_mlx_pixel_put(meta, dst_x + x, dst_y + y, color);
		}
	}
}
