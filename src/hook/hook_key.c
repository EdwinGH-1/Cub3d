/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:29:54 by jothomas          #+#    #+#             */
/*   Updated: 2025/07/07 11:56:18 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	door_toggle(t_meta *meta)
{
	t_pixel	*pixel;

	pixel = NULL;
	meta->ray.dir_x = meta->player.dir_x;
	meta->ray.dir_y = meta->player.dir_y;
	dda_logic(meta, 1);
	pixel = &meta->map.pixel[meta->ray.grid_y][meta->ray.grid_x];
	if (pixel->value == 'O')
		pixel->value = 'D';
	else if (pixel->value == 'D')
		pixel->value = 'O';
}

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
	else if (keysym == XK_e)
		door_toggle(meta);
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

void	check_state(t_meta *meta, double velocity_x, double velocity_y)
{
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
}

int	mouse_move(int mx, int my, t_meta *meta)
{
	double	precision;

	(void)my;
	precision = (mx - WINX / 2) * P_PRECISION * meta->time.delta_time;
	meta->player.base_angle += precision;
	mlx_mouse_move(meta->mlx, meta->win, WINX / 2, WINY / 2);
	return (0);
}

void	movement_state(t_meta *meta)
{
	int		offset[2];
	double	velocity_x;
	double	velocity_y;
	double	torque;

	offset[0] = meta->map.x_offset;
	offset[1] = meta->map.y_offset;
	velocity_x = P_SPEED * meta->player.dir_x * meta->time.delta_time;
	velocity_y = P_SPEED * meta->player.dir_y * meta->time.delta_time;
	torque = (P_TORQUE * PIE / 180) * meta->time.delta_time;
	check_state(meta, velocity_x, velocity_y);
	if (meta->state.key_r)
		meta->player.base_angle += torque;
	if (meta->state.key_l)
		meta->player.base_angle -= torque;
	if (!collision_check(meta))
	{
		meta->map.x_offset = offset[0];
		meta->map.y_offset = offset[1];
	}
}
