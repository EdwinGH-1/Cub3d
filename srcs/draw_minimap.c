/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:20:36 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/27 19:31:30 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_LEN && y >= 0 && y < WIN_HEI)
	{
		dst = img->addr + (y * img->line_size + x * (img->bbp / 8));
		*(unsigned int *)dst = color;
	}
}

bool	is_in_minimap(t_minimap *minimap, int x, int y)
{
	if (x >= minimap->left && x <= minimap->right
		&& y >= minimap->top && y <= minimap->bottom)
		return (true);
	return (false);
}

void	draw_minimap(t_vars *vars)
{
	draw_map(vars, &vars->map, &vars->map.point);
	draw_fov(vars, &vars->minimap, &vars->fov);
	draw_player(vars, &vars->minimap, &vars->player);
}
