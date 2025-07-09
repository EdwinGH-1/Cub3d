/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:11:32 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/27 20:08:39 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_press(int key, t_vars *vars)
{
	if (key == XK_Escape)
		close_win(vars);
	else if (key == XK_w)
		vars->key_state.w = true;
	else if (key == XK_a)
		vars->key_state.a = true;
	else if (key == XK_s)
		vars->key_state.s = true;
	else if (key == XK_d)
		vars->key_state.d = true;
	else if (key == XK_Left)
		vars->key_state.l_arr = true;
	else if (key == XK_Right)
		vars->key_state.r_arr = true;
	else if (key == XK_e)
		toggle_door(vars, &vars->animation, &vars->animation.toggle_door);
	else if (key == XK_m)
		set_anim(&vars->animation, &vars->animation.east_egg, ANIM_EAST_EGG);
	else if (key == XK_q)
		set_anim(&vars->animation, &vars->animation.thumbs_up, ANIM_THUMBS_UP);
	return (0);
}

int	key_release(int key, t_vars *vars)
{
	if (key == XK_w)
		vars->key_state.w = false;
	else if (key == XK_a)
		vars->key_state.a = false;
	else if (key == XK_s)
		vars->key_state.s = false;
	else if (key == XK_d)
		vars->key_state.d = false;
	else if (key == XK_Left)
		vars->key_state.l_arr = false;
	else if (key == XK_Right)
		vars->key_state.r_arr = false;
	return (0);
}

int	mouse_rot(int x, int y, t_vars *vars)
{
	int	start_x;

	(void)y;
	start_x = WIN_LEN / 2;
	if (x == start_x)
		return (0);
	vars->player.dir += (x - start_x) * MOUSE_SENSITIVITY;
	if (vars->player.dir <= 0)
		vars->player.dir += 2 * M_PI;
	if (vars->player.dir >= 2 * M_PI)
		vars->player.dir -= 2 * M_PI;
	vars->player.dir_x = cos(vars->player.dir);
	vars->player.dir_y = sin(vars->player.dir);
	mlx_mouse_move(vars->mlx, vars->win, WIN_LEN / 2, WIN_HEI / 2);
	return (0);
}

void	hook_handler(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, key_press, vars);
	mlx_hook(vars->win, 3, 1L << 1, key_release, vars);
	mlx_hook(vars->win, 6, 1L << 6, mouse_rot, vars);
	mlx_hook(vars->win, 17, 0L, close_win, vars);
}
