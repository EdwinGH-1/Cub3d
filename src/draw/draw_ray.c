/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:51:35 by jothomas          #+#    #+#             */
/*   Updated: 2025/07/02 16:20:20 by jothomas         ###   ########.fr       */
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

unsigned int	texture_pixel(t_texture tex, int x, int y)
{
	unsigned char	*pixel;

	pixel = (unsigned char *)tex.addr
		+ y * tex.line_length + x * (tex.bpp / 8);
	return (*(int *)pixel);
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
	double		height;
	double		start;
	double		end;
	double		step;
	double		tex_pos;
	int			tex_x;
	int			tex_y;
	int			y;

	height = TILE_SIZE
		* (WINX / 2 / tan(P_FOV * PIE / 180 / 2)) / meta->ray.perp_dist;
	start = (WINY - height) / 2;
	end = start + height;
	texture = meta->map.texture[texture_index(meta)];
	tex_x = meta->ray.pos_x * (double)texture.x;
	if ((meta->ray.side == 0 && meta->ray.dir_x > 0)
		|| (meta->ray.side == 1 && meta->ray.dir_y < 0))
		tex_x = texture.x - tex_x - 1;
	step = texture.y / height;
	tex_pos = (start - WINY / 2 + height / 2) * step;
	y = -1;
	while (++y <= WINY)
	{
		if (y < start)
			my_mlx_pixel_put(meta, x, y, meta->map.ceiling);
		else if (y > end)
			my_mlx_pixel_put(meta, x, y, meta->map.floor);
		else
		{
			tex_y = (int)tex_pos;
			if (tex_y < 0)
				tex_y = 0;
			else if (tex_y >= texture.y)
				tex_y = texture.y - 1;
			tex_pos += step;
			my_mlx_pixel_put(meta, x, y,
				texture_pixel(texture, (int)tex_x, (int)tex_y));
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
	while (++x <= WINX)
	{
		meta->ray.dir_x = cos(angle);
		meta->ray.dir_y = sin(angle);
		dda_logic(meta);
		print_frag(meta, x);
		angle += shift;
	}
}
