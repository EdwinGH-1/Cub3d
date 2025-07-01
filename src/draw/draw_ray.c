/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshua <joshua@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:51:35 by jothomas          #+#    #+#             */
/*   Updated: 2025/07/01 20:07:07 by joshua           ###   ########.fr       */
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

unsigned int	texture_pixel(t_meta *meta,
	int index, int x, int y)
{
	unsigned char	*pixel;

	meta->map.texture.img[index] = mlx_xpm_file_to_image(meta->mlx,
		meta->map.texture.path[index], &meta->map.texture.x,
		&meta->map.texture.y);
	meta->map.texture.addr = mlx_get_data_addr(meta->map.texture.img[index],
		&meta->map.texture.bpp, &meta->map.texture.line_length,
		&meta->map.texture.endian);
	pixel = (unsigned char *)meta->map.texture.addr
		+ y * meta->map.texture.line_length + x * (meta->map.texture.bpp / 8);
	return (*(int *)pixel);
}

int	texture_index(t_meta *meta)
{
	if (meta->ray.side == 0)
	{
		if (meta->ray.dir_x > 0.0)
			return (2);
		else
			return (3);
	}
	else
	{
		if (meta->ray.dir_y > 0.0)
			return (1);
		else
			return (0);
	}
}

void	print_frag(t_meta *meta, int x)
{
	double	height;
	double	start;
	double	end;
	int		index;
	int		y;

	height = TILE_SIZE
		* (WINX / 2 / tan(P_FOV * PIE / 180 / 2)) / meta->ray.perp_dist;
	start = (WINY - height) / 2;
	end = start + height;
	y = -1;
	index = texture_index(meta);
	while (++y <= WINY)
	{
		if (y < start)
			my_mlx_pixel_put(meta, x, y, meta->map.texture.ceiling);
		else if (y > end)
			my_mlx_pixel_put(meta, x, y, meta->map.texture.floor);
		else
			my_mlx_pixel_put(meta, x, y,
				texture_pixel(meta, index, x, y));
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
