/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:46:24 by jothomas          #+#    #+#             */
/*   Updated: 2025/07/01 10:45:42 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_render(t_meta *meta)
{
	int	value;

	meta->player.pos_x = MINI_POS + MINI_RAD - meta->map.x_offset;
	meta->player.pos_y = MINI_POS + MINI_RAD - meta->map.y_offset;
	meta->mini.centre_x = MINI_POS + MINI_RAD;
	meta->mini.centre_y = MINI_POS + MINI_RAD;
	meta->mini.angle_shift = (P_FOV * PIE / 180) / RAY_N;
	value = meta->map.pixel[(int)meta->player.pos_y / MINI_SIZE][(int)meta->player.pos_x / MINI_SIZE].value;
	if (value == 'N')
		meta->mini.base_angle = 3 * PIE / 2;
	else if (value == 'S')
		meta->mini.base_angle = PIE / 2;
	else if (value == 'E')
		meta->mini.base_angle = 0;
	else if (value == 'W')
		meta->mini.base_angle = PIE;
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