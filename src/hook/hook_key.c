/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:29:54 by jothomas          #+#    #+#             */
/*   Updated: 2025/07/01 12:05:38 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	key_press(int keysym, t_meta *meta)
{
	if (keysym == XK_w)
		meta->state.key_w = true;
	else if (keysym == XK_s)
		meta->state.key_s = true;
	else if (keysym == XK_a)
		meta->state.key_a = true;
	else if (keysym == XK_d)
		meta->state.key_d = true;
	else if (keysym == XK_Right)
		meta->state.key_r = true;
	else if (keysym == XK_Left)
		meta->state.key_l = true;
	else if (keysym == XK_Escape)
		terminate(meta);
	return (0);
}

int	key_release(int keysym, t_meta *meta)
{
	if (keysym == XK_w)
		meta->state.key_w = false;
	else if (keysym == XK_s)
		meta->state.key_s = false;
	else if (keysym == XK_a)
		meta->state.key_a = false;
	else if (keysym == XK_d)
		meta->state.key_d = false;
	else if (keysym == XK_Right)
		meta->state.key_r = false;
	else if (keysym == XK_Left)
		meta->state.key_l = false;
	return (0);
}

void	rotation(t_meta *meta)
{
	if (meta->state.key_r)
		meta->mini.base_angle += (P_TORQUE * PIE / 180);
	if (meta->state.key_l)
		meta->mini.base_angle -= (P_TORQUE * PIE / 180);
}

void	translate(t_meta *meta)
{
	int		offset[2];
	double	velocity_x;
	double	velocity_y;

	offset[0] = meta->map.x_offset;
	offset[1] = meta->map.y_offset;
	velocity_x = P_SPEED * meta->player.dir_x;
	velocity_y = P_SPEED * meta->player.dir_y;
	if (meta->state.key_w)
	{
		meta->map.x_offset -= velocity_x;
		meta->map.y_offset -= velocity_y;
	}
	if (meta->state.key_s)
	{
		meta->map.x_offset += velocity_x;
		meta->map.y_offset += velocity_y;
	}
	if (meta->state.key_a)
	{
		meta->map.x_offset -= velocity_y;
		meta->map.y_offset -= -velocity_x;
	}
	if (meta->state.key_d)
	{
		meta->map.x_offset += velocity_y;
		meta->map.y_offset += -velocity_x;
	}
	if (!collision_check(meta))
	{
		meta->map.x_offset = offset[0];
		meta->map.y_offset = offset[1];
	}
	rotation(meta);
}
