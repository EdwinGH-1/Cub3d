/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:51:35 by jothomas          #+#    #+#             */
/*   Updated: 2025/07/07 10:14:11 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_map_ray(t_meta *meta)
{
	double	angle;
	double	shift;
	int		i;

	angle = meta->player.base_angle - (P_FOV * PIE / 180.0 / 2.0);
	shift = (P_FOV * PIE / 180.0) / RAY_N;
	i = -1;
	while (++i <= RAY_N)
	{
		meta->ray.dir_x = cos(angle);
		meta->ray.dir_y = sin(angle);
		dda_logic(meta, 0);
		meta->ray.pos_x = meta->player.pos_x
			- (meta->ray.perp_dist * meta->ray.dir_x) + meta->map.x_offset;
		meta->ray.pos_y = meta->player.pos_y
			- (meta->ray.perp_dist * meta->ray.dir_y) + meta->map.y_offset;
		draw_line(meta);
		angle += shift;
	}
}

void	texture_strip(t_meta *meta, int x)
{
	t_texture	texture;
	double		start;
	double		end;
	double		step;
	int			y;

	texture_bounds(meta, &start, &end);
	texture_coord(meta, &texture);
	step = 1.0 * texture.height / meta->ray.line_h;
	meta->map.y_tex = (start - WINY / 2.0 + meta->ray.line_h / 2.0) * step;
	y = -1;
	while (++y < WINY)
	{
		if (y < start)
			my_mlx_pixel_put(meta, x, y, meta->map.ceiling);
		else if (y > end)
			my_mlx_pixel_put(meta, x, y, meta->map.floor);
		else
			my_mlx_pixel_put(meta, x, y,
				texture_color(meta, texture, &step));
	}
}

void	raycast(t_meta *meta)
{
	double	angle;
	double	shift;
	int		x;

	angle = meta->player.base_angle - (P_FOV * PIE / 180 / 2);
	shift = (P_FOV * PIE / 180) / WINX;
	x = -1;
	while (++x < WINX)
	{
		meta->ray.dir_x = cos(angle);
		meta->ray.dir_y = sin(angle);
		dda_logic(meta, 0);
		meta->ray.perp_dist *= (meta->player.dir_x * meta->ray.dir_x
				+ meta->player.dir_y * meta->ray.dir_y);
		meta->ray.pos_x = (meta->player.pos_x
				+ (meta->ray.perp_dist * meta->ray.dir_x))
			/ MINI_SIZE;
		meta->ray.pos_y = (meta->player.pos_y
				+ (meta->ray.perp_dist * meta->ray.dir_y))
			/ MINI_SIZE;
		texture_strip(meta, x);
		angle += shift;
	}
}
