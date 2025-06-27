/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:31:08 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/27 20:41:01 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_sprite_to_image(t_vars *vars, t_tex_img *sprite)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < sprite->height)
	{
		x = 0;
		while (x < sprite->width)
		{
			color = *(unsigned int *)(sprite->addr + y * sprite->line_size
					+ x *(sprite->bbp / 8));
			if (color != 0x000000)
				my_mlx_pixel_put(&vars->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	play_animation(t_vars *vars, t_sprite *sprite, int hand)
{
	if (sprite->is_playing == true)
	{
		sprite->accum_time += vars->time.delta_time;
		if (sprite->accum_time >= sprite->frame_duration)
		{
			sprite->accum_time -= sprite->frame_duration;
			sprite->frame++;
			if (sprite->frame >= sprite->img_count)
			{
				sprite->frame = 0;
				sprite->is_playing = false;
				if (hand == LEFT_HAND)
					vars->animation.lhand_playing = false;
				if (hand == RIGHT_HAND)
					vars->animation.rhand_playing = false;
			}
		}
		draw_sprite_to_image(vars, &sprite->sprite_imgs[sprite->frame]);
	}
}

void	handle_animations(t_vars *vars, t_anim *animation)
{
	play_animation(vars, &animation->toggle_door, LEFT_HAND);
	play_animation(vars, &animation->thumbs_up, RIGHT_HAND);
	play_animation(vars, &animation->east_egg, RIGHT_HAND);
}
