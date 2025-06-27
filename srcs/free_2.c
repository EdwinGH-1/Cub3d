/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:03:51 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/26 21:07:33 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_sprite(t_vars *vars, t_sprite *sprite)
{
	int	i;

	if (sprite->sprite_imgs != NULL)
	{
		i = 0;
		while (i < sprite->img_count)
		{
			if (sprite->sprite_imgs[i].img != NULL)
				mlx_destroy_image(vars->mlx, sprite->sprite_imgs[i].img);
			else
				break ;
			i++;
		}
		free(sprite->sprite_imgs);
	}
}

void	free_animation(t_vars *vars, t_anim *animation)
{
	free_sprite(vars, &animation->east_egg);
	free_sprite(vars, &animation->toggle_door);
	free_sprite(vars, &animation->thumbs_up);
}
