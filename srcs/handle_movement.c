/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:33:23 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/27 16:11:41 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	can_move(t_map *map, t_player *player, float x, float y)
{
	int		left;
	int		right;
	int		top;
	int		bottom;

	left = x - player->hit_box;
	right = x + player->hit_box;
	top = y - player->hit_box;
	bottom = y + player->hit_box;
	if (left <= 0 || right >= map->x_max
		|| top <= 0 || bottom >= map->y_max)
		return (false);
	if (map->point[top][left].value == 1
		|| map->point[top][right].value == 1
		|| map->point[bottom][left].value == 1
		|| map->point[bottom][right].value == 1
		|| map->point[top][left].value == 'D'
		|| map->point[top][right].value == 'D'
		|| map->point[bottom][left].value == 'D'
		|| map->point[bottom][right].value == 'D')
		return (false);
	return (true);
}

void	get_move_vector(t_key_state *state, t_player *player, t_move_vec *vec)
{
	vec->x = 0;
	vec->y = 0;
	if (state->w == true)
	{
		vec->x += player->dir_x;
		vec->y += player->dir_y;
	}
	if (state->s == true)
	{
		vec->x -= player->dir_x;
		vec->y -= player->dir_y;
	}
	if (state->a == true)
	{
		vec->x += player->dir_y;
		vec->y -= player->dir_x;
	}
	if (state->d == true)
	{
		vec->x -= player->dir_y;
		vec->y += player->dir_x;
	}
}

void	handle_movement(t_vars *vars, t_player *player, t_time *time)
{
	t_move_vec	move_vec;
	float		length;
	float		new_x;
	float		new_y;

	get_move_vector(&vars->key_state, player, &move_vec);
	length = sqrt(move_vec.x * move_vec.x + move_vec.y * move_vec.y);
	if (length > 0)
	{
		move_vec.x = (move_vec.x / length) * player->speed * time->delta_time;
		move_vec.y = (move_vec.y / length) * player->speed * time->delta_time;
		new_x = player->x + move_vec.x;
		new_y = player->y + move_vec.y;
		if (can_move(&vars->map, player, new_x, player->y) == true)
			player->x = new_x;
		if (can_move(&vars->map, player, player->x, new_y) == true)
			player->y = new_y;
	}
}
