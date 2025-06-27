/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:20:03 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/27 20:41:23 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	can_draw_fov(t_vars *vars, int x, int y)
{
	if (x <= 0 || x >= vars->map.x_max || y <= 0 || y >= vars->map.y_max)
		return (false);
	if (vars->map.point[y][x].value == 1 || vars->map.point[y][x].value == 'D')
		return (false);
	return (true);
}

unsigned int	blend_color(unsigned int c1, unsigned int c2, float t)
{
	int	r;
	int	g;
	int	b;

	r = (int)((1.0f - t) * ((c1 >> 16) & 0xff) + t * ((c2 >> 16) & 0xff));
	g = (int)((1.0f - t) * ((c1 >> 8) & 0xff) + t * ((c2 >> 8) & 0xff));
	b = (int)((1.0f - t) * (c1 & 0xff) + t * (c2 & 0xff));
	return ((r << 16) | (g << 8) | b);
}

unsigned int	get_fov_color(t_point ***point, int x, int y)
{
	if ((*point)[y][x].value == 'O')
		return (blend_color(FOV_COLOR, DOOR_OPEN_COLOR, 0.15));
	return (FOV_COLOR);
}

void	get_fov_angles(t_player *player, t_fov *fov)
{
	fov->start_ang = player->dir - ((FOV_ANG / 2.0) * M_PI / 180.0f);
	fov->end_ang = player->dir + ((FOV_ANG / 2.0) * M_PI / 180.0f);
}

void	draw_fov(t_vars *vars, t_minimap *minimap, t_fov *fov)
{
	float	distance;
	int		cell_size;

	cell_size = minimap->cell_size;
	get_fov_angles(&vars->player, fov);
	while (fov->start_ang <= fov->end_ang)
	{
		distance = 0;
		while (1)
		{
			fov->x = vars->player.x + cos(fov->start_ang) * distance;
			fov->y = vars->player.y + sin(fov->start_ang) * distance;
			if (can_draw_fov(vars, fov->x, fov->y) == false)
				break ;
			fov->color = get_fov_color(&vars->map.point, fov->x, fov->y);
			fov->x = minimap->center_x + (fov->x - vars->player.x) * cell_size;
			fov->y = minimap->center_y + (fov->y - vars->player.y) * cell_size;
			if (is_in_minimap(&vars->minimap, fov->x, fov->y) == true)
				my_mlx_pixel_put(&vars->img, fov->x, fov->y, fov->color);
			distance += LINE_STEP_SIZE;
			if (distance > FOV_DRAW_DIST)
				break ;
		}
		fov->start_ang += FOV_DRAW_ANG * M_PI / 180;
	}
}
