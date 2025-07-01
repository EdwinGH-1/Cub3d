/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:54:01 by jothomas          #+#    #+#             */
/*   Updated: 2025/07/01 12:57:23 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_dda(t_meta *meta)
{
	meta->ray.step_x = 1;
	if (meta->ray.dir_x < 0.0)
		meta->ray.step_x = -1;
	meta->ray.step_y = 1;
	if (meta->ray.dir_y < 0.0)
		meta->ray.step_y = -1;
	meta->ray.delta_x = fabs(MINI_SIZE / meta->ray.dir_x);
	meta->ray.delta_y = fabs(MINI_SIZE / meta->ray.dir_y);
	meta->ray.grid_x = meta->player.pos_x / MINI_SIZE;
	meta->ray.grid_y = meta->player.pos_y / MINI_SIZE;
	if (meta->ray.step_x > 0)
		meta->ray.dist_x
			= ((meta->ray.grid_x + 1) * MINI_SIZE - meta->player.pos_x)
			/ fabs(meta->ray.dir_x);
	else
		meta->ray.dist_x = (meta->player.pos_x - meta->ray.grid_x * MINI_SIZE)
			/ fabs(meta->ray.dir_x);
	if (meta->ray.step_y > 0)
		meta->ray.dist_y
			= ((meta->ray.grid_y + 1) * MINI_SIZE - meta->player.pos_y)
			/ fabs(meta->ray.dir_y);
	else
		meta->ray.dist_y = (meta->player.pos_y - meta->ray.grid_y * MINI_SIZE)
			/ fabs(meta->ray.dir_y);
}

void	dda_logic(t_meta *meta)
{
	init_dda(meta);
	while (1)
	{
		if (meta->ray.dist_x < meta->ray.dist_y)
		{
			meta->ray.perp_dist = meta->ray.dist_x;
			meta->ray.dist_x += meta->ray.delta_x;
			meta->ray.grid_x += meta->ray.step_x;
			meta->ray.side = 0;
		}
		else
		{
			meta->ray.perp_dist = meta->ray.dist_y;
			meta->ray.dist_y += meta->ray.delta_y;
			meta->ray.grid_y += meta->ray.step_y;
			meta->ray.side = 1;
		}
		if (meta->map.pixel[meta->ray.grid_y][meta->ray.grid_x].value == 1
			|| meta->map.pixel[meta->ray.grid_y][meta->ray.grid_x].value == -1)
			break ;
	}
	meta->ray.pos_x = meta->player.pos_x
		- (meta->ray.perp_dist * meta->ray.dir_x);
	meta->ray.pos_y = meta->player.pos_y
		- (meta->ray.perp_dist * meta->ray.dir_y);
	meta->ray.perp_dist *= (meta->player.dir_x * meta->ray.dir_x
			+ meta->player.dir_y * meta->ray.dir_y);
}
