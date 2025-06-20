/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:46:24 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/20 15:51:43 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	init_offset(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y_max)
	{
		x = 0;
		while (x < map->x_max)
		{
			if (map->pixel[y][x].value == 'N' || map->pixel[y][x].value == 'S'
				|| map->pixel[y][x].value == 'E'
				|| map->pixel[y][x].value == 'W')
			{
				map->x_offset -= x * MINI_SIZE
					- MINI_RAD - MINI_POS + (MINI_SIZE / 2);
				map->y_offset -= y * MINI_SIZE
					- MINI_RAD - MINI_POS + (MINI_SIZE / 2);
				return ;
			}
			x++;
		}
		y++;
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
	init_offset(&meta.map);
	mlx_loop_hook(meta.mlx, render_image, &meta);
	mlx_hook(meta.win, 2, 1L >> 0, handle_key, &meta);
	mlx_hook(meta.win, 17, 0, terminate, &meta);
	mlx_loop(meta.mlx);
	return (0);
}

// size_t	x;
// size_t	y;
// y = 0;
// while (y < meta.map.y_max)
// {
// 	x = 0;
// 	while (x < meta.map.x_max)
// 	{
// 		printf("%i", meta.map.pixel[y][x].value);
// 		x++;
// 	}
// 	printf("\n");
// 	y++;
// }