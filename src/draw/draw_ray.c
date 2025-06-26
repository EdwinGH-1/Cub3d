/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:51:35 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/26 14:57:42 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_map_ray(t_meta *meta)
{
	t_pos	current;
	t_pos	start;
	int		centre;
	double	end;
	double	shift;

	centre = MINI_POS + MINI_RAD;
	meta->player.pos.x = centre - meta->map.x_offset;
	meta->player.pos.y = centre - meta->map.y_offset;
	start.x = centre;
	start.y = centre;
	meta->player.increment = (P_FOV * PIE / 180) / RAY_N;
	end = meta->player.angle + P_FOV * PIE / 180;
	shift = meta->player.angle;
	while (shift <= end)
	{
		shift += meta->player.increment;
		meta->player.dir_x = cos(shift);
		meta->player.dir_y = sin(shift);
		current = meta->player.pos;
		raycast_point(meta, &current);
		current.x = centre - current.dist * meta->player.dir_x;
		current.y = centre - current.dist * meta->player.dir_y;
		draw_line(meta, start, current);
	}
}
