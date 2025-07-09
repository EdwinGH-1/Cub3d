/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycasting_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:45:22 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/30 16:26:33 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_column_strip_extent(t_ray *ray)
{
	ray->col_height = (int)((WIN_HEI / ray->perp_wall_dist) * WALL_HEIGHT);
	ray->col_draw_start = WIN_HEI / 2 - ray->col_height / 2;
	ray->col_draw_end = WIN_HEI / 2 + ray->col_height / 2;
	if (ray->col_draw_start < 0)
		ray->col_draw_start = 0;
	if (ray->col_draw_end >= WIN_HEI)
		ray->col_draw_end = WIN_HEI - 1;
}

int	get_pixel_x(t_vars *vars, t_ray *ray)
{
	int				pix_x;
	float			wall_x;

	if (ray->side == HIT_VERT_WALL)
		wall_x = vars->player.y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = vars->player.x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	pix_x = (int)(wall_x * (float)ray->tex->width);
	if ((ray->side == HIT_VERT_WALL && ray->dir_x > 0)
		|| (ray->side == HIT_HORIZ_WALL && ray->dir_y < 0))
		pix_x = ray->tex->width - pix_x - 1;
	return (pix_x);
}

int	get_pixel_y(t_ray *ray, int y)
{
	float	wall_top;
	int		pix_y;

	wall_top = (WIN_HEI / 2.0) - (ray->col_height / 2.0);
	pix_y = (int)(((y - wall_top) / ray->col_height) * ray->tex->height);
	if (pix_y < 0)
		pix_y = 0;
	if (pix_y >= ray->tex->height)
		pix_y = ray->tex->height - 1;
	return (pix_y);
}

void	sample_and_draw_strip(t_vars *vars, t_ray *ray, int screen_x)
{
	int				y;
	int				pix_x;
	int				pix_y;
	char			*pixel;

	pix_x = get_pixel_x(vars, ray);
	y = ray->col_draw_start;
	while (y < ray->col_draw_end)
	{
		pix_y = get_pixel_y(ray, y);
		pixel = ray->tex->addr + (pix_y * ray->tex->line_size
				+ pix_x * (ray->tex->bbp / 8));
		my_mlx_pixel_put(&vars->img, screen_x, y, *(unsigned int *)pixel);
		y++;
	}
}
