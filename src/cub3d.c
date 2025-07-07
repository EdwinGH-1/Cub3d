/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:46:24 by jothomas          #+#    #+#             */
/*   Updated: 2025/07/07 15:34:03 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_sprite(t_meta *meta)
{
	int	fd;

	fd = open("./gun.xpm", O_RDONLY);
	if (fd < 0)
		meta->map.sprite.path = NULL;
	else
	{
		meta->map.sprite.path = ft_strdup("./gun.xpm");
		meta->map.sprite.img = mlx_xpm_file_to_image(meta->mlx,
				meta->map.sprite.path, &meta->map.sprite.width,
				&meta->map.sprite.height);
		meta->map.sprite.addr = mlx_get_data_addr(meta->map.sprite.img,
				&meta->map.sprite.bpp, &meta->map.sprite.line_length,
				&meta->map.sprite.endian);
	}
}

void	init_render(t_meta *meta)
{
	t_texture		*tex;
	struct timeval	tv;
	int				index;

	index = -1;
	tex = NULL;
	while (++index <= DO && meta->parse.textures[index])
	{
		tex = &meta->map.texture[index];
		tex->img = mlx_xpm_file_to_image(meta->mlx,
				tex->path, &tex->width, &tex->height);
		tex->addr = mlx_get_data_addr(tex->img,
				&tex->bpp, &tex->line_length, &tex->endian);
	}
	// init_sprite(meta);
	gettimeofday(&tv, NULL);
	meta->time.current_frame = tv.tv_sec + tv.tv_usec * 1e-9;
	mlx_mouse_hide(meta->mlx, meta->win);
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
	mlx_hook(meta.win, 2, 1L << 0, key_press, &meta);
	mlx_hook(meta.win, 3, 1L << 1, key_release, &meta);
	mlx_hook(meta.win, 6, 1L << 6, mouse_move, &meta);
	mlx_hook(meta.win, 17, 0, terminate, &meta);
	mlx_loop(meta.mlx);
	return (0);
}
