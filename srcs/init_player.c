/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:07:14 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/19 22:33:59 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	get_player_angle(char dir)
{
	if (dir == 'N')
		return (3.0f * M_PI / 2.0f);
	if (dir == 'E')
		return (0.0f);
	if (dir == 'S')
		return (M_PI / 2.0f);
	if (dir == 'W')
		return (M_PI);
	return (0.0f);
}

bool	is_player(int value)
{
	if (value == 'N' || value == 'E' || value == 'S' || value == 'W')
		return (true);
	return (false);
}

void	init_player_data(t_vars *vars, t_map *map, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y_max)
	{
		x = 0;
		while (x < map->x_max)
		{
			if (is_player(map->point[y][x].value) == true)
			{
				player->x = x + 0.5;
				player->y = y + 0.5;
				player->speed = PLAYER_SPD;
				player->size =  vars->minimap.cell_size / 2;
				player->dir = get_player_angle(map->point[y][x].value);
				printf("player spawned at (%f, %f)\n", player->x, player->y);
				map->point[y][x].value = 0;
			}
			x++;
		}
		y++;
	}
}
