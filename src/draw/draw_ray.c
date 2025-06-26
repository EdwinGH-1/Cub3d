/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:51:35 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/26 17:47:18 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_map_ray(t_meta *meta)
{
	int		centre;
	double	end;
	double	shift;

	centre = MINI_POS + MINI_RAD;
	end = meta->player.angle + P_FOV * PIE / 180;
	shift = meta->player.angle;
	while (shift <= end)
	{
		meta->ray.dir_x = cos(shift);
		meta->ray.dir_y = sin(shift);
		raycast_point(meta);
		current.x = centre - current.dist * meta->player.dir_x;
		current.y = centre - current.dist * meta->player.dir_y;
		draw_line(meta);
	}
}
