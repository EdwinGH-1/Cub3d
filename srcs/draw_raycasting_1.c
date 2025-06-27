/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycasting_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:45:22 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/27 23:45:32 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_step_and_side_dist(t_player *player, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->y) * ray->delta_dist_y;
	}
}

void	run_dda_loop(t_vars *vars, t_ray *ray)
{
	while (ray->hit_obstacle == false)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = HIT_VERT_WALL;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = HIT_HORIZ_WALL;
		}
		if (vars->map.point[ray->map_y][ray->map_x].value == 1
			|| vars->map.point[ray->map_y][ray->map_x].value == 'D')
			ray->hit_obstacle = true;
	}
}

void	get_perp_distance(t_vars *vars, t_player *player, t_ray *ray)
{
	ray->dir_x = player->dir_x - player->dir_y * ray->camera_x;
	ray->dir_y = player->dir_y + player->dir_x * ray->camera_x;
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
	get_step_and_side_dist(player, ray);
	run_dda_loop(vars, ray);
	if (ray->side == HIT_VERT_WALL)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
}

void	get_ray_texture(t_vars *vars, t_ray *ray)
{
	if (vars->map.point[ray->map_y][ray->map_x].value == 'D')
		ray->tex = &vars->texture.door_tex;
	else if (ray->side == HIT_VERT_WALL)
	{
		if (ray->dir_x > 0)
			ray->tex = &vars->texture.we_tex;
		else
			ray->tex = &vars->texture.ea_tex;
	}
	else
	{
		if (ray->dir_y > 0)
			ray->tex = &vars->texture.no_tex;
		else
			ray->tex = &vars->texture.so_tex;
	}
}

void	draw_raycasting(t_vars *vars)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIN_LEN)
	{
		ft_memset(&ray, 0, sizeof(t_ray));
		ray.camera_x = 2.0 * x / WIN_LEN - 1;
		get_perp_distance(vars, &vars->player, &ray);
		get_ray_texture(vars, &ray);
		get_column_strip_extent(&ray);
		sample_and_draw_strip(vars, &ray, x);
		x++;
	}
}
