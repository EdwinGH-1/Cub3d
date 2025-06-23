/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshua <joshua@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:54:01 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/23 22:43:17 by joshua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	raycast_point(t_meta *meta, t_pixel *current)
{
	int		dist_x;
	int		dist_y;
	int		delta_x;
	int		delta_y;
	int		side_x;
	int		side_y;
	t_pixel	tmp;
	
	delta_x = ((current->x / MINI_SIZE * MINI_SIZE) + MINI_SIZE - current->x)
	/ meta->player.dir_x;
	delta_y = ((current->y / MINI_SIZE * MINI_SIZE) - current->y)
	/ meta->player.dir_y;
	tmp = *current;
	while (1)
	{
		if (dist_x < dist_y)
		{
			tmp.x = current->x + dist_x;
			tmp.y = current->y + sqrt(dist_x * dist_x - tmp.x * tmp.x);
		}
		else
		{
		    tmp.y = current->y + dist_y;
			tmp.x = current->x + sqrt(dist_y * dist_y - tmp.y * tmp.y);
		}
		*current = tmp;
		tmp = meta->map.pixel[current->y / MINI_SIZE][current->x / MINI_SIZE];
		if (tmp.value == 1 || tmp.value == -1)
			break ;
	}
}
    
void	raycast(t_meta *meta)
{
	
}
