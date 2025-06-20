/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:37:18 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/20 14:42:35 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	terminate(t_meta *meta)
{
	(void)meta;
	exit(0);
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

int	handle_key(int keysym, t_meta *meta)
{
	if (keysym == XK_w)
		meta->map.y_offset += MOVE;
	if (keysym == XK_s)
		meta->map.y_offset -= MOVE;
	if (keysym == XK_a)
		meta->map.x_offset += MOVE;
	if (keysym == XK_d)
		meta->map.x_offset -= MOVE;
	if (keysym == XK_Escape)
		exit(0);
	render_image(meta);
	return (0);
}
