/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:27:02 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/27 19:31:34 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_cell(t_vars *vars, int x, int y, int color)
{
	int	i;
	int	j;
	int	cell_size;
	int	offset_x;
	int	offset_y;

	cell_size = vars->minimap.cell_size;
	offset_x = vars->minimap.center_x - (vars->player.x
			* cell_size + cell_size / 2.0);
	offset_y = vars->minimap.center_y - (vars->player.y
			* cell_size + cell_size / 2.0);
	x = offset_x + x * cell_size + cell_size / 2;
	y = offset_y + y * cell_size + cell_size / 2;
	j = vars->minimap.grid_border;
	while (j < cell_size - vars->minimap.grid_border)
	{
		i = vars->minimap.grid_border;
		while (i < cell_size - vars->minimap.grid_border)
		{
			if (is_in_minimap(&vars->minimap, x + i, y + j) == true)
				my_mlx_pixel_put(&vars->img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_map_border(t_img *img, t_minimap *minimap)
{
	int	x;
	int	y;
	int	i;

	x = minimap->left - MINIMAP_BORDER_SIZE - 1;
	while (++x <= minimap->right + MINIMAP_BORDER_SIZE)
	{
		i = 0;
		while (++i <= MINIMAP_BORDER_SIZE)
		{
			my_mlx_pixel_put(img, x, minimap->top - i, MINIMAP_BORDER_COLOR);
			my_mlx_pixel_put(img, x, minimap->bottom + i, MINIMAP_BORDER_COLOR);
		}
	}
	y = minimap->top - 1;
	while (++y <= minimap->bottom)
	{
		i = 0;
		while (++i <= MINIMAP_BORDER_SIZE)
		{
			my_mlx_pixel_put(img, minimap->left - i, y, MINIMAP_BORDER_COLOR);
			my_mlx_pixel_put(img, minimap->right + i, y, MINIMAP_BORDER_COLOR);
		}
	}
}

unsigned int	get_map_point_color(int value)
{
	if (value == 0)
		return (TILE_COLOR);
	else if (value == 1)
		return (WALL_COLOR);
	else if (value == 'O')
		return (DOOR_OPEN_COLOR);
	else
		return (DOOR_CLOSE_COLOR);
}

void	draw_map(t_vars *vars, t_map *map, t_point ***point)
{
	int	x;
	int	y;
	int	color;

	draw_map_border(&vars->img, &vars->minimap);
	y = 0;
	while (y < map->y_max)
	{
		x = 0;
		while (x < map->x_max)
		{
			if ((*point)[y][x].value == 0 || (*point)[y][x].value == 1
				|| (*point)[y][x].value == 'O' || (*point)[y][x].value == 'D')
				color = get_map_point_color((*point)[y][x].value);
			else
			{
				x++;
				continue ;
			}
			draw_cell(vars, x, y, color);
			x++;
		}
		y++;
	}
}
