/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:46:24 by jothomas          #+#    #+#             */
/*   Updated: 2025/07/02 15:09:15 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_render(t_meta *meta)
{
	t_texture	tex;
	int			index;

	meta->player.pos_x = MINI_POS + MINI_RAD - meta->map.x_offset;
	meta->player.pos_y = MINI_POS + MINI_RAD - meta->map.y_offset;
	meta->mini.centre_x = MINI_POS + MINI_RAD;
	meta->mini.centre_y = MINI_POS + MINI_RAD;
	meta->mini.angle_shift = (P_FOV * PIE / 180) / RAY_N;
	index = -1;
	while (++index <= DO && meta->parse.textures[index])
	{
		tex = meta->map.texture[index];
		tex.img = mlx_xpm_file_to_image(meta->mlx, tex.path, &tex.x, &tex.y);
		tex.addr = mlx_get_data_addr(tex.img,
				&tex.bpp, &tex.line_length, &tex.endian);
	}
}

int	main(int argc, char **argv)
{
	t_meta	meta;

	if (!parse_map(argc, argv, &meta))
		exit (1);
	meta.mlx = mlx_init();
	meta.win = mlx_new_window(meta.mlx, WINX, WINY, "DOOM: THE CURRY AGES");
	meta.bitmap.img = mlx_new_image(meta.mlx, WINX, WINY);
	meta.bitmap.addr = mlx_get_data_addr(meta.bitmap.img,
			&meta.bitmap.bpp, &meta.bitmap.line_length, &meta.bitmap.endian);
	init_render(&meta);
	mlx_loop_hook(meta.mlx, render_image, &meta);
	mlx_hook(meta.win, 2, 1L >> 0, key_press, &meta);
	mlx_hook(meta.win, 3, 2L >> 0, key_release, &meta);
	mlx_hook(meta.win, 17, 0, terminate, &meta);
	mlx_loop(meta.mlx);
	return (0);
}
