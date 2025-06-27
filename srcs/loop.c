/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:18:14 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/27 20:43:34 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_image(t_vars *vars)
{
	draw_background(vars, &vars->texture);
	draw_raycasting(vars);
	draw_minimap(vars);
}

void	handle_user_input(t_vars *vars)
{
	handle_movement(vars, &vars->player, &vars->time);
	handle_rotation(vars, &vars->player, &vars->time);
	handle_animations(vars, &vars->animation);
}

void	update_time(t_time *time)
{
	struct timeval	current_time;
	float			elapsed;

	gettimeofday(&current_time, NULL);
	elapsed = (current_time.tv_sec - time->last_frame_time.tv_sec)
		+ (current_time.tv_usec - time->last_frame_time.tv_usec) / 1000000.0;
	if (elapsed > 0)
		time->fps_count = 1.0f / elapsed;
	time->last_frame_time = current_time;
	time->delta_time = elapsed;
}

void	print_fps(t_time *time)
{
	struct timeval	current_time;
	float			elapsed;

	gettimeofday(&current_time, NULL);
	elapsed = (current_time.tv_sec - time->last_print_time.tv_sec)
		+ (current_time.tv_usec - time->last_print_time.tv_usec) / 1000000.0;
	if (elapsed >= FPS_PRINT_INTERVAL)
	{
		printf("FPS: %.2f\n", time->fps_count);
		time->last_print_time = current_time;
	}
}

int	game_loop(t_vars *vars)
{
	draw_image(vars);
	handle_user_input(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	update_time(&vars->time);
	print_fps(&vars->time);
	return (0);
}
