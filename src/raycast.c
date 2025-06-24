/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:54:01 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/24 16:27:54 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	raycast_point(t_meta *meta, t_pos *current)
{
	double	delta_x;
	double	delta_y;
	double	dist_x;
	double	dist_y;
	int		step[2];

	step[0] = 1;
	if (meta->player.dir_x < 0.0)
		step[0] = -1;
	step[1] = 1;
	if (meta->player.dir_y < 0.0)
		step[1] = -1;
	delta_x = fabs(MINI_SIZE / meta->player.dir_x);
	delta_y = fabs(MINI_SIZE / meta->player.dir_y);
	current->grid_x = current->x / MINI_SIZE;
	current->grid_y = current->y / MINI_SIZE;
	if (step[0] > 0)
		dist_x = ((current->grid_x + 1) * MINI_SIZE - current->x)
			/ meta->player.dir_x;
	else
		dist_x = (current->x - current->grid_x * MINI_SIZE)
			/ meta->player.dir_x;
	if (step[1] > 0)
		dist_y = ((current->grid_y + 1) * MINI_SIZE - current->y)
			/ meta->player.dir_y;
	else
		dist_y = (current->y - current->grid_y * MINI_SIZE)
			/ meta->player.dir_y;
	while (1)
	{
		if (dist_x < dist_y)
		{
			current->dist = dist_x;
			dist_x += delta_x;
			current->grid_x += step[0];
		}
		else
		{
			current->dist = dist_y;
			dist_y += delta_y;
			current->grid_y += step[1];
		}
		if (meta->map.pixel[current->grid_y][current->grid_x].value == 1
			|| meta->map.pixel[current->grid_y][current->grid_x].value == -1)
			break ;
	}
}

// void	raycast(t_meta *meta)
// {
	
// }
