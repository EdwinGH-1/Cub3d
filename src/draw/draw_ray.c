/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:51:35 by jothomas          #+#    #+#             */
/*   Updated: 2025/07/03 15:09:26 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_map_ray(t_meta *meta)
{
	double	angle;
	int		i;

	angle = meta->mini.base_angle - (P_FOV * PIE / 180 / 2);
	i = -1;
	while (++i <= RAY_N)
	{
		meta->ray.dir_x = cos(angle);
		meta->ray.dir_y = sin(angle);
		dda_logic(meta);
		meta->mini.ray_x = meta->ray.pos_x + meta->map.x_offset;
		meta->mini.ray_y = meta->ray.pos_y + meta->map.y_offset;
		draw_line(meta);
		angle += meta->mini.angle_shift;
	}
}

unsigned int	texture_color(t_meta *meta, t_texture tex)
{
	unsigned char	*pixel;

	pixel = (unsigned char *)tex.addr
		+ meta->map.y_tex * tex.line_length + (meta->map.x_tex * tex.bpp / 8);
	return (*(unsigned int *)pixel);
}

int	texture_index(t_meta *meta)
{
	if (meta->ray.side == 0)
	{
		if (meta->ray.dir_x > 0.0)
			return (EA);
		else
			return (WE);
	}
	else
	{
		if (meta->ray.dir_y > 0.0)
			return (SO);
		else
			return (NO);
	}
}

void	print_frag(t_meta *meta, int x)
{
	t_texture	texture;
	double		line_h;
	double		start;
	double		end;
	double		step;
	double		wall_x;
	int			y;

	line_h = TILE_SIZE
		* (WINX / 2 / tan(P_FOV * PIE / 180 / 2)) / meta->ray.perp_dist;
	start = (WINY - line_h) / 2.0;
	if (start < 0)
		start = 0;
	end = start + line_h;
	if (end >= WINY)
		end = WINY - 1;
	texture = meta->map.texture[texture_index(meta)];
	if (meta->ray.side == 0)
		wall_x = meta->ray.pos_x - floor(meta->ray.pos_x);
	else
		wall_x = meta->ray.pos_y - floor(meta->ray.pos_y);
	meta->map.x_tex = wall_x * (double)texture.width;
	if (meta->map.x_tex < 0)
		meta->map.x_tex = 0;
	else if (meta->map.x_tex >= texture.width)
		meta->map.x_tex = texture.width - 1;
	if ((meta->ray.side == 0 && meta->ray.dir_x > 0)
		|| (meta->ray.side == 1 && meta->ray.dir_y < 0))
		meta->map.x_tex = texture.width - meta->map.x_tex - 1;
	step = 1.0 * texture.height / line_h;
	y = -1;
	while (++y < WINY)
	{
		if (y < start)
			my_mlx_pixel_put(meta, x, y, meta->map.ceiling);
		else if (y > end)
			my_mlx_pixel_put(meta, x, y, meta->map.floor);
		else
		{
			if (meta->map.y_tex < 0)
				meta->map.y_tex = 0;
			else if (meta->map.y_tex >= texture.height)
				meta->map.y_tex = texture.height - 1;
			my_mlx_pixel_put(meta, x, y, texture_color(meta, texture));
			meta->map.y_tex += (int)step;
		}
	}
}

void	raycast(t_meta *meta)
{
	double	angle;
	double	shift;
	int		x;

	angle = meta->mini.base_angle - (P_FOV * PIE / 180 / 2);
	shift = (P_FOV * PIE / 180) / WINX;
	x = -1;
	while (++x < WINX)
	{
		meta->ray.dir_x = cos(angle);
		meta->ray.dir_y = sin(angle);
		dda_logic(meta);
		print_frag(meta, x);
		angle += shift;
	}
}
