/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:13:37 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/27 16:13:43 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	handle_rotation(t_vars *vars, t_player *player, t_time *time)
{
	if (vars->key_state.l_arr == true)
	{
		player->dir -= 180.0 * M_PI / 180 * time->delta_time;
		if (player->dir <= 0)
			player->dir += 2 * M_PI;
		player->dir_x = cos(player->dir);
		player->dir_y = sin(player->dir);
	}
	if (vars->key_state.r_arr == true)
	{
		player->dir += 180.0 * M_PI / 180 * time->delta_time;
		if (player->dir >= 2 * M_PI)
			player->dir -= 2 * M_PI;
		player->dir_x = cos(player->dir);
		player->dir_y = sin(player->dir);
	}
}
