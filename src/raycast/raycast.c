/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:54:01 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/26 17:45:34 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	find_dda(t_meta *meta, bool	map)
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
		meta->ray.delta_y
			= ((meta->ray.grid_y + 1) * MINI_SIZE - meta->player.pos_y)
			/ fabs(meta->ray.dir_y);
	else
		meta->ray.delta_y = (meta->player.pos_y - meta->ray.grid_y * MINI_SIZE)
			/ fabs(meta->ray.dir_y);
	while (1)
	{
		if (meta->ray.dist_x < meta->ray.delta_y)
		{
			meta->ray.dist_x += meta->ray.delta_x;
			meta->ray.grid_x += meta->ray.step_x;
		}
		else
		{
			meta->ray.delta_y += meta->ray.delta_y;
			meta->ray.grid_y += meta->ray.step_y;
		}
		if (meta->map.pixel[meta->ray.grid_y][meta->ray.grid_x].value == 1
			|| meta->map.pixel[meta->ray.grid_y][meta->ray.grid_x].value == -1)
			break ;
	}
}

// void	raycast(t_meta *meta)
// {
//		 
// }
