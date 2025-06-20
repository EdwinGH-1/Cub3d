/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:11:32 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/18 13:47:39 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_win(t_vars *vars)
{
	delete_and_free_vars(vars);
	exit (0);
}

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

void	hook_handler(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, key_press, vars);
	mlx_hook(vars->win, 3, 1L << 1, key_release, vars);
	mlx_hook(vars->win, 17, 0L, close_win, vars);
}
