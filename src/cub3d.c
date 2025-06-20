/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:46:24 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/20 14:55:31 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	my_mlx_pixel_put(t_meta *meta, int x, int y, unsigned int color)
{
	char	*dst;

	if (y > WINY || y < 0 || x > WINX || x < 0)
		return ;
	dst = meta->bitmap.addr
		+ ((x * meta->bitmap.bpp / 8)
			+ (y * meta->bitmap.line_length));
	*(unsigned int *)dst = color;
}

void	render_minimap(t_meta *meta)
{
	int	x;
	int	y;
	int	count_x;
	int	count_y;

	y = 0;
	while (y < meta->map.y_max)
	{
		x = 0;
		while (x < meta->map.x_max)
		{
			count_y = 0;
			while (count_y <= MINI_SIZE)
			{
				count_x = 0;
				while (count_x <= MINI_SIZE)
					draw_grid(meta,
						meta->map.pixel[y][x], count_x++, count_y);
				count_y++;
			}
			x++;
		}
		y++;
	}
}

void	init_offset(t_map *map)
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
				map->x_offset -= x * MINI_SIZE;
				map->y_offset -= y * MINI_SIZE;
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
	// init_offset(&meta.map);
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