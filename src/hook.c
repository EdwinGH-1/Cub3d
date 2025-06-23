/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:37:18 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/23 12:47:35 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	terminate(t_meta *meta)
{
	free_part(&meta->map, meta->map.y_max);
	free_texture(&meta->map);
	mlx_destroy_image(meta->mlx, meta->bitmap.img);
	mlx_destroy_window(meta->mlx, meta->win);
	mlx_destroy_display(meta->mlx);
	free(meta->mlx);
	exit(EXIT_SUCCESS);
}

bool	collision_check(t_meta *meta)
{
	int	grid_x;
	int	grid_y;

	grid_x = (MINI_RAD + MINI_POS - meta->map.x_offset)
		/ MINI_SIZE;
	grid_y = (MINI_RAD + MINI_POS - meta->map.y_offset)
		/ MINI_SIZE;
	if (meta->map.pixel[grid_y][grid_x].value == 1
		|| meta->map.pixel[grid_y][grid_x].value == -1)
		return (false);
	grid_x = (MINI_RAD + MINI_POS - meta->map.x_offset - P_SIZE / 2)
		/ MINI_SIZE;
	grid_y = (MINI_RAD + MINI_POS - meta->map.y_offset - P_SIZE / 2)
		/ MINI_SIZE;
	if (meta->map.pixel[grid_y][grid_x].value == 1
		|| meta->map.pixel[grid_y][grid_x].value == -1)
		return (false);
	return (true);
}

int	handle_key(int keysym, t_meta *meta)
{
	int	offset[2];

	offset[0] = meta->map.x_offset;
	offset[1] = meta->map.y_offset;
	if (keysym == XK_w)
		meta->map.y_offset += MOVE;
	if (keysym == XK_s)
		meta->map.y_offset -= MOVE;
	if (keysym == XK_a)
		meta->map.x_offset += MOVE;
	if (keysym == XK_d)
		meta->map.x_offset -= MOVE;
	if (keysym == XK_Escape)
		terminate(meta);
	if (!collision_check(meta))
	{
		meta->map.x_offset = offset[0];
		meta->map.y_offset = offset[1];
	}
	render_image(meta);
	return (0);
}

int	render_image(void *data)
{
	t_meta	*meta;

	meta = (t_meta *)data;
	ft_bzero(meta->bitmap.addr, WINY * meta->bitmap.line_length);
	render_minimap(meta);
	draw_circle(meta);
	draw_player(meta);
	mlx_put_image_to_window(meta->mlx, meta->win, meta->bitmap.img, 0, 0);
	return (0);
}
