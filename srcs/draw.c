/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:20:36 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/19 22:32:41 by jthiew           ###   ########.fr       */
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

void	draw_cell(t_vars *vars, int x, int y, int color)
{
	int	i;
	int	j;
	int	cell_size;

	cell_size = vars->minimap.cell_size;
	j = vars->minimap.border;
	while (j < cell_size - vars->minimap.border)
	{
		i = vars->minimap.border;
		while (i < cell_size - vars->minimap.border)
		{
			my_mlx_pixel_put(&vars->img,
				vars->minimap.right_align + (x * cell_size + cell_size / 2 + i),
				y * cell_size + cell_size / 2 + j,
				color);
			i++;
		}
		j++;
	}
}

void	draw_player(t_vars *vars, t_player player)
{
	int		i;
	int		j;
	float	k;

	float center_x = player.x * vars->minimap.cell_size + vars->minimap.cell_size / 2.0;
	float center_y = player.y * vars->minimap.cell_size + vars->minimap.cell_size / 2.0;

	j = 0;
	k = 0;
	while (j < player.size)
	{
		i = 0;
		while (i < player.size)
		{
			if (i >= player.size / 2 - (int)k && i <= player.size / 2 + (int)k)
			{
				float local_x = -j + player.size / 2.0;
				float local_y = i - player.size / 2.0;
				float rot_x = local_x * cos(player.dir) - local_y * sin(player.dir);
				float rot_y = local_x * sin(player.dir) + local_y * cos(player.dir);
				int screen_x = center_x + rot_x;
				int screen_y = center_y + rot_y;
				my_mlx_pixel_put(&vars->img, vars->minimap.right_align + screen_x, screen_y, 0x00ff00);
			}
			i++;
		}
		k += 0.75;
		j++;
	}
}

void	draw_map(t_vars *vars)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < vars->map.y_max)
	{
		x = 0;
		while (x < vars->map.x_max)
		{
			if (vars->map.point[y][x].value == 1)
				color = 0xffffff;
			else if (vars->map.point[y][x].value == 'D')
				color = 0xffff00;
			else if (vars->map.point[y][x].value == 'O')
				color = 0x0000ff;
			else
				color = 0x555555;
			draw_cell(vars, x, y, color);
			x++;
		}
		y++;
	}
}

bool	can_cast_ray(t_vars *vars, float new_x, float new_y)
{
	if (new_x <= 0 || new_x >= vars->map.x_max
		|| new_y <= 0 || new_y >= vars->map.y_max)
		return (false);
	if (vars->map.point[(int)new_y][(int)new_x].value == 1
		|| vars->map.point[(int)new_y][(int)new_x].value == 'D')
		return (false);
	return (true);
}

void	draw_fov(t_vars *vars, t_ray ray)
{
	float	distance;

	while (ray.start_ang <= ray.end_ang)
	{
		distance = 0;
		while (1)
		{
			ray.x = vars->player.x + cos(ray.start_ang) * distance;
			ray.y = vars->player.y + sin(ray.start_ang) * distance;
			if (can_cast_ray(vars, ray.x, ray.y) == false)
				break ;
			my_mlx_pixel_put(&vars->img,
				vars->minimap.right_align + ((ray.x + 0.5) * vars->minimap.cell_size),
				((ray.y + 0.5) * vars->minimap.cell_size),
				0xff0000);
			distance += LINE_STEP_SIZE;
		}
		ray.start_ang += 0.5 * M_PI / 180;
	}
}
