/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:47:27 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/27 14:53:03 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	load_thumbs_up_imgs(t_vars *vars, t_tex_img **imgs)
{
	load_texture(vars, &(*imgs)[0], "./textures/thumbs_up/frame_00.xpm");
	load_texture(vars, &(*imgs)[1], "./textures/thumbs_up/frame_01.xpm");
	load_texture(vars, &(*imgs)[2], "./textures/thumbs_up/frame_02.xpm");
	load_texture(vars, &(*imgs)[3], "./textures/thumbs_up/frame_03.xpm");
	load_texture(vars, &(*imgs)[4], "./textures/thumbs_up/frame_04.xpm");
	load_texture(vars, &(*imgs)[5], "./textures/thumbs_up/frame_05.xpm");
	load_texture(vars, &(*imgs)[6], "./textures/thumbs_up/frame_06.xpm");
	load_texture(vars, &(*imgs)[7], "./textures/thumbs_up/frame_07.xpm");
	load_texture(vars, &(*imgs)[8], "./textures/thumbs_up/frame_08.xpm");
	load_texture(vars, &(*imgs)[9], "./textures/thumbs_up/frame_09.xpm");
	load_texture(vars, &(*imgs)[10], "./textures/thumbs_up/frame_10.xpm");
	load_texture(vars, &(*imgs)[11], "./textures/thumbs_up/frame_11.xpm");
	load_texture(vars, &(*imgs)[12], "./textures/thumbs_up/frame_12.xpm");
	load_texture(vars, &(*imgs)[13], "./textures/thumbs_up/frame_13.xpm");
	load_texture(vars, &(*imgs)[14], "./textures/thumbs_up/frame_14.xpm");
	load_texture(vars, &(*imgs)[15], "./textures/thumbs_up/frame_15.xpm");
}

void	load_east_egg_imgs(t_vars *vars, t_tex_img **imgs)
{
	load_texture(vars, &(*imgs)[0], "./textures/east_egg/frame_00.xpm");
	load_texture(vars, &(*imgs)[1], "./textures/east_egg/frame_01.xpm");
	load_texture(vars, &(*imgs)[2], "./textures/east_egg/frame_02.xpm");
	load_texture(vars, &(*imgs)[3], "./textures/east_egg/frame_03.xpm");
	load_texture(vars, &(*imgs)[4], "./textures/east_egg/frame_04.xpm");
	load_texture(vars, &(*imgs)[5], "./textures/east_egg/frame_05.xpm");
	load_texture(vars, &(*imgs)[6], "./textures/east_egg/frame_06.xpm");
	load_texture(vars, &(*imgs)[7], "./textures/east_egg/frame_07.xpm");
	load_texture(vars, &(*imgs)[8], "./textures/east_egg/frame_08.xpm");
	load_texture(vars, &(*imgs)[9], "./textures/east_egg/frame_09.xpm");
	load_texture(vars, &(*imgs)[10], "./textures/east_egg/frame_10.xpm");
	load_texture(vars, &(*imgs)[11], "./textures/east_egg/frame_11.xpm");
	load_texture(vars, &(*imgs)[12], "./textures/east_egg/frame_12.xpm");
	load_texture(vars, &(*imgs)[13], "./textures/east_egg/frame_13.xpm");
	load_texture(vars, &(*imgs)[14], "./textures/east_egg/frame_14.xpm");
	load_texture(vars, &(*imgs)[15], "./textures/east_egg/frame_15.xpm");
	load_texture(vars, &(*imgs)[16], "./textures/east_egg/frame_16.xpm");
}

void	load_toggle_door_imgs(t_vars *vars, t_tex_img **imgs)
{
	load_texture(vars, &(*imgs)[0], "./textures/toggle_door/frame_00.xpm");
	load_texture(vars, &(*imgs)[1], "./textures/toggle_door/frame_01.xpm");
	load_texture(vars, &(*imgs)[2], "./textures/toggle_door/frame_02.xpm");
	load_texture(vars, &(*imgs)[3], "./textures/toggle_door/frame_03.xpm");
	load_texture(vars, &(*imgs)[4], "./textures/toggle_door/frame_04.xpm");
	load_texture(vars, &(*imgs)[5], "./textures/toggle_door/frame_05.xpm");
	load_texture(vars, &(*imgs)[6], "./textures/toggle_door/frame_06.xpm");
	load_texture(vars, &(*imgs)[7], "./textures/toggle_door/frame_07.xpm");
	load_texture(vars, &(*imgs)[8], "./textures/toggle_door/frame_08.xpm");
	load_texture(vars, &(*imgs)[9], "./textures/toggle_door/frame_09.xpm");
}
