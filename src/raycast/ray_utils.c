/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:29:43 by jothomas          #+#    #+#             */
/*   Updated: 2025/07/04 16:16:49 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	texture_index(t_meta *meta)
{
	if (meta->map.pixel[meta->ray.grid_y][meta->ray.grid_x].value == 'D'
		&& meta->parse.textures[DO])
		return (DO);
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

unsigned int	texture_color(t_meta *meta, t_texture tex, double *step)
{
	unsigned char	*pixel;

	if (meta->map.y_tex < 0)
		meta->map.y_tex = 0;
	else if (meta->map.y_tex >= tex.height)
		meta->map.y_tex = tex.height - 1;
	pixel = (unsigned char *)tex.addr
		+ (int)meta->map.y_tex * tex.line_length
		+ ((int)meta->map.x_tex * tex.bpp / 8);
	meta->map.y_tex += *step;
	return (*(unsigned int *)pixel);
}

void	texture_coord(t_meta *meta, t_texture *texture)
{
	double		wall_x;

	if (meta->ray.side == 0)
		wall_x = meta->ray.pos_y;
	else
		wall_x = meta->ray.pos_x;
	wall_x -= floor(wall_x);
	*texture = meta->map.texture[texture_index(meta)];
	meta->map.x_tex = wall_x * (double)texture->width;
	if (meta->map.x_tex < 0)
		meta->map.x_tex = 0;
	else if (meta->map.x_tex >= texture->width)
		meta->map.x_tex = texture->width - 1;
	if ((meta->ray.side == 0 && meta->ray.dir_x > 0)
		|| (meta->ray.side == 1 && meta->ray.dir_y < 0))
		meta->map.x_tex = texture->width - meta->map.x_tex - 1;
}

void	texture_bounds(t_meta *meta, double *start, double *end)
{
	meta->ray.line_h = TILE_SIZE
		* (WINX / 2 / tan(P_FOV * PIE / 180 / 2)) / meta->ray.perp_dist;
	*start = (WINY - meta->ray.line_h) / 2.0;
	if (*start < 0)
		*start = 0;
	*end = meta->ray.line_h / 2.0 + WINY / 2.0;
	if (*end >= WINY)
		*end = WINY - 1;
}
