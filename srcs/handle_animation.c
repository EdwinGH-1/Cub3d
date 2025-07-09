/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:31:08 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/30 13:06:44 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_scaled_image_data(t_sprite_scale *scale, t_tex_img *sprite)
{
	scale->scale_x = (float)WIN_LEN / sprite->width;
	scale->scale_y = (float)WIN_HEI / sprite->height;
	scale->scaled_width = sprite->width * scale->scale_x;
	scale->scaled_height = sprite->height * scale->scale_y;
	scale->x_offset = WIN_LEN / 2 - scale->scaled_width / 2;
	scale->y_offset = WIN_HEI / 2 - scale->scaled_height / 2;
}

void	draw_sprite_to_image(t_vars *vars, t_tex_img *sprite)
{
	t_sprite_scale	scale;
	unsigned int	color;

	get_scaled_image_data(&scale, sprite);
	scale.dest_y = 0;
	while (scale.dest_y < scale.scaled_height)
	{
		scale.dest_x = 0;
		while (scale.dest_x < scale.scaled_width)
		{
			scale.src_x = scale.dest_x / scale.scale_x;
			scale.src_y = scale.dest_y / scale.scale_y;
			color = *(unsigned int *)(sprite->addr + scale.src_y
					* sprite->line_size + scale.src_x *(sprite->bbp / 8));
			if (color != 0x000000)
				my_mlx_pixel_put(&vars->img, scale.dest_x + scale.x_offset,
					scale.dest_y + scale.y_offset, color);
			scale.dest_x++;
		}
		scale.dest_y++;
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
