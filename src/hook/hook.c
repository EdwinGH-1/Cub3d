/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:37:18 by jothomas          #+#    #+#             */
/*   Updated: 2025/07/04 16:59:15 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	terminate(t_meta *meta)
{
	free_texture(meta);
	memfree_array((void **)meta->map.pixel);
	mlx_destroy_image(meta->mlx, meta->bitmap.img);
	mlx_destroy_window(meta->mlx, meta->win);
	mlx_destroy_display(meta->mlx);
	free(meta->mlx);
	exit(EXIT_SUCCESS);
}

void	collision_side(t_meta *meta, int *grid_x, int *grid_y, int side)
{
	if (side == 0)
	{
		*grid_x = (MINI_RAD + MINI_POS - meta->map.x_offset) / MINI_SIZE;
		*grid_y = (MINI_RAD + MINI_POS - meta->map.y_offset) / MINI_SIZE;
	}
	if (side == 1 || side == 3)
		*grid_x = (MINI_RAD + MINI_POS - meta->map.x_offset - P_SIZE / 2)
			/ MINI_SIZE;
	if (side == 2 || side == 4)
		*grid_x = (MINI_RAD + MINI_POS - meta->map.x_offset + P_SIZE / 2)
			/ MINI_SIZE;
	if (side == 1 || side == 4)
		*grid_y = (MINI_RAD + MINI_POS - meta->map.y_offset + P_SIZE / 2)
			/ MINI_SIZE;
	if (side == 2 || side == 3)
		*grid_y = (MINI_RAD + MINI_POS - meta->map.y_offset - P_SIZE / 2)
			/ MINI_SIZE;
}

bool	collision_check(t_meta *meta)
{
	int	grid_x;
	int	grid_y;
	int	side;

	side = -1;
	while (++side < 5)
	{
		collision_side(meta, &grid_x, &grid_y, side);
		if (meta->map.pixel[grid_y][grid_x].value == 1
			|| meta->map.pixel[grid_y][grid_x].value == -1
			|| meta->map.pixel[grid_y][grid_x].value == 'D')
			return (false);
	}
	return (true);
}

void	prep_render(t_meta *meta)
{
	struct timeval	tv;

	meta->player.pos_x = MINI_POS + MINI_RAD - meta->map.x_offset;
	meta->player.pos_y = MINI_POS + MINI_RAD - meta->map.y_offset;
	meta->player.dir_x = cos(meta->player.base_angle);
	meta->player.dir_y = sin(meta->player.base_angle);
	meta->time.last_frame = meta->time.current_frame;
	gettimeofday(&tv, NULL);
	meta->time.current_frame = tv.tv_sec + tv.tv_usec * 1e-6;
	meta->time.delta_time = meta->time.current_frame - meta->time.last_frame;
	meta->time.fps = 1 / meta->time.delta_time;
}

int	render_image(void *data)
{
	t_meta	*meta;

	meta = (t_meta *)data;
	ft_bzero(meta->bitmap.addr, WINY * meta->bitmap.line_length);
	movement_state(meta);
	prep_render(meta);
	raycast(meta);
	render_minimap(meta);
	mlx_put_image_to_window(meta->mlx, meta->win, meta->bitmap.img, 0, 0);
	return (0);
}
