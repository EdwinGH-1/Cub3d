/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:29:54 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/26 14:33:02 by jothomas         ###   ########.fr       */
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

void	translate(t_meta *meta)
{
	int	offset[2];

	offset[0] = meta->map.x_offset;
	offset[1] = meta->map.y_offset;
	if (meta->state.key_w)
		meta->map.y_offset += P_MOVE;
	if (meta->state.key_s)
		meta->map.y_offset -= P_MOVE;
	if (meta->state.key_a)
		meta->map.x_offset += P_MOVE;
	if (meta->state.key_d)
		meta->map.x_offset -= P_MOVE;
	if (meta->state.key_r)
		meta->player.angle -= (P_TURN * PIE / 180);
	if (meta->state.key_l)
		meta->player.angle += (P_TURN * PIE / 180);
	if (!collision_check(meta))
	{
		meta->map.x_offset = offset[0];
		meta->map.y_offset = offset[1];
	}
}
