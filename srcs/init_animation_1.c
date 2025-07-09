/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animation_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:45:03 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/27 19:54:23 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_east_egg_anim(t_vars *vars, t_sprite *sprite)
{
	sprite->img_count = 17;
	sprite->sprite_imgs = malloc(sprite->img_count * sizeof(t_tex_img));
	if (sprite->sprite_imgs == NULL)
	{
		delete_and_free_vars(vars);
		exit(1);
	}
	load_east_egg_imgs(vars, &sprite->sprite_imgs);
	sprite->frame = 0;
	sprite->tick = 0;
	sprite->is_hand = RIGHT_HAND;
}

void	init_thumbs_up_anim(t_vars *vars, t_sprite *sprite)
{
	sprite->img_count = 16;
	sprite->sprite_imgs = malloc(sprite->img_count * sizeof(t_tex_img));
	if (sprite->sprite_imgs == NULL)
	{
		delete_and_free_vars(vars);
		exit(1);
	}
	load_thumbs_up_imgs(vars, &sprite->sprite_imgs);
	sprite->frame = 0;
	sprite->tick = 0;
	sprite->is_hand = RIGHT_HAND;
}

void	init_toggle_door_anim(t_vars *vars, t_sprite *sprite)
{
	sprite->img_count = 10;
	sprite->sprite_imgs = malloc(sprite->img_count * sizeof(t_tex_img));
	if (sprite->sprite_imgs == NULL)
	{
		delete_and_free_vars(vars);
		exit(1);
	}
	load_toggle_door_imgs(vars, &sprite->sprite_imgs);
	sprite->frame = 0;
	sprite->tick = 0;
	sprite->is_hand = LEFT_HAND;
}

void	init_animation_data(t_vars *vars, t_anim *animation)
{
	init_toggle_door_anim(vars, &animation->toggle_door);
	init_thumbs_up_anim(vars, &animation->thumbs_up);
	init_east_egg_anim(vars, &animation->east_egg);
}
