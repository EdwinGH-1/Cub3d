/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:46:24 by jothomas          #+#    #+#             */
/*   Updated: 2025/07/04 18:57:50 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_render(t_meta *meta)
{
	t_texture		*tex;
	struct timeval	tv;
	int				index;
	int				fd;

	index = -1;
	tex = NULL;
	index = open("./gun.xpm", O_RDONLY);
	while (++index <= DO + 1 && meta->parse.textures[index])
	{
		tex = &meta->map.texture[index];
		if (index == DO + 1)
		{
			if (index < 0)
				break ;
			tex->path = ft_strdup("./gun.xpm");
		}
		tex->img = mlx_xpm_file_to_image(meta->mlx,
				tex->path, &tex->width, &tex->height);
		tex->addr = mlx_get_data_addr(tex->img,
				&tex->bpp, &tex->line_length, &tex->endian);
	}
	gettimeofday(&tv, NULL);
	meta->time.current_frame = tv.tv_sec + tv.tv_usec * 1e-9;
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
