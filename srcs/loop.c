/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:18:14 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/24 18:20:56 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx.h"
#include <stdbool.h>

// bool	can_move(t_vars *vars, float new_x, float new_y)
// {
// 	int		left;
// 	int		right;
// 	int		top;
// 	int		bottom;
//
// 	left = new_x - (vars->player.size / 2.0) / vars->minimap.cell_size;
// 	right = new_x + (vars->player.size / 2.0) / vars->minimap.cell_size;
// 	top = new_y - (vars->player.size / 2.0) / vars->minimap.cell_size;
// 	bottom = new_y + (vars->player.size / 2.0) / vars->minimap.cell_size;
// 	if (left <= 0 || right >= vars->map.x_max
// 		|| top <= 0 || bottom >= vars->map.y_max)
// 		return (false);
// 	if (vars->map.point[top][left].value == 1
// 		|| vars->map.point[top][right].value == 1
// 		|| vars->map.point[bottom][left].value == 1
// 		|| vars->map.point[bottom][right].value == 1)
// 		return (false);
// 	return (true);
// }

bool	can_move_x(t_vars *vars, float new_x, float ori_y)
{
	int		left;
	int		right;

	left = new_x - (vars->player.size / 2.0) / vars->minimap.cell_size;
	right = new_x + (vars->player.size / 2.0) / vars->minimap.cell_size;
	if (left <= 0 || right >= vars->map.x_max)
		return (false);
	if (vars->map.point[(int)ori_y][left].value == 1
		|| vars->map.point[(int)ori_y][right].value == 1
		|| vars->map.point[(int)ori_y][left].value == 'D'
		|| vars->map.point[(int)ori_y][right].value == 'D')
		return (false);
	return (true);
}

bool	can_move_y(t_vars *vars, float ori_x, float new_y)
{
	int		top;
	int		bottom;

	top = new_y - (vars->player.size / 2.0) / vars->minimap.cell_size;
	bottom = new_y + (vars->player.size / 2.0) / vars->minimap.cell_size;
	if (top <= 0 || bottom >= vars->map.y_max)
		return (false);
	if (vars->map.point[top][(int)ori_x].value == 1
		|| vars->map.point[bottom][(int)ori_x].value == 1
		|| vars->map.point[top][(int)ori_x].value == 'D'
		|| vars->map.point[bottom][(int)ori_x].value == 'D')
		return (false);
	return (true);
}

void	handle_movement(t_vars *vars)
{
	float	dir_x;
	float	dir_y;
	float	move_x;
	float	move_y;
	float	length;
	float	new_x;
	float	new_y;

	dir_x = cos(vars->player.dir);
	dir_y = sin(vars->player.dir);
	move_x = 0;
	move_y = 0;
	if (vars->key_state.w == true)
	{
		move_x += dir_x;
		move_y += dir_y;
	}
	if (vars->key_state.s == true)
	{
		move_x -= dir_x;
		move_y -= dir_y;
	}
	if (vars->key_state.a == true)
	{
		move_x += dir_y;
		move_y -= dir_x;
	}
	if (vars->key_state.d == true)
	{
		move_x -= dir_y;
		move_y += dir_x;
	}
	length = sqrt(move_x * move_x + move_y * move_y);
	if (length > 0)
	{
		move_x = (move_x / length) * vars->player.speed;
		move_y = (move_y / length) * vars->player.speed;
		new_x = vars->player.x + move_x;
		new_y = vars->player.y + move_y;
		if (can_move_x(vars, new_x, vars->player.y) == true)
			vars->player.x = new_x;
		if (can_move_y(vars, vars->player.x, new_y) == true)
			vars->player.y = new_y;
	}
}

void	handle_rotation(t_vars *vars)
{
	if (vars->key_state.l_arr == true)
	{
		vars->player.dir -= 2.0 * M_PI / 180;
		if (vars->player.dir <= 0)
			vars->player.dir += 2 * M_PI;
	}
	if (vars->key_state.r_arr == true)
	{
		vars->player.dir += 2.0 * M_PI / 180;
		if (vars->player.dir >= 2 * M_PI)
			vars->player.dir -= 2 * M_PI;
	}
}

void	clear_background(t_vars *vars, unsigned int	ceiling_col, unsigned int floor_col)
{
	int				x;
	int				y;

	y = 0;
	while (y < WIN_HEI)
	{
		x = 0;
		while (x < WIN_LEN)
		{
			if (y < WIN_HEI / 2)
				my_mlx_pixel_put(&vars->img, x, y, ceiling_col);
			else
				my_mlx_pixel_put(&vars->img, x, y, floor_col);
			x++;
		}
		y++;
	}
}

void	cast_ray(t_vars *vars, int screen_x)
{
	t_player	*player = &vars->player;
	t_ray		ray;
	int			map_x;
	int			map_y;
	bool		hit = false;
	int			side;
	float		camera_x = 2 * screen_x / (float)WIN_LEN - 1;

	ray.dir_x = cos(player->dir) - sin(player->dir) * camera_x;
	ray.dir_y = sin(player->dir) + cos(player->dir) * camera_x;

	map_x = (int)player->x;
	map_y = (int)player->y;

	ray.delta_dist_x = fabs(1 / ray.dir_x);
	ray.delta_dist_y = fabs(1 / ray.dir_y);

	if (ray.dir_x < 0)
	{
		ray.step_x = -1;
		ray.side_dist_x = (player->x - map_x) * ray.delta_dist_x;
	}
	else
{
		ray.step_x = 1;
		ray.side_dist_x = (map_x + 1.0 - player->x) * ray.delta_dist_x;
	}
	if (ray.dir_y < 0)
	{
		ray.step_y = -1;
		ray.side_dist_y = (player->y - map_y) * ray.delta_dist_y;
	}
	else
	{
		ray.step_y = 1;
		ray.side_dist_y = (map_y + 1.0 - player->y) * ray.delta_dist_y;
	}

	while (hit == false)
	{
		if (ray.side_dist_x < ray.side_dist_y)
		{
			ray.side_dist_x += ray.delta_dist_x;
			map_x += ray.step_x;
			side = 0;
		}
		else
		{
			ray.side_dist_y += ray.delta_dist_y;
			map_y += ray.step_y;
			side = 1;
		}
		if (vars->map.point[map_y][map_x].value == 1
			|| vars->map.point[map_y][map_x].value == 'D')
			hit = true;
	}

	if (side == 0)
		ray.perp_wall_dist = (ray.side_dist_x - ray.delta_dist_x);
	else
	{
		ray.perp_wall_dist = (ray.side_dist_y - ray.delta_dist_y);
	}

	int	line_height = (int)(WIN_HEI / ray.perp_wall_dist);
	int	draw_start = -line_height / 2 + WIN_HEI / 2;

	if (draw_start < 0)
		draw_start = 0;
	int	draw_end = line_height / 2 + WIN_HEI / 2;
	if (draw_end >= WIN_HEI)
		draw_end = WIN_HEI - 1;

	t_tex_img	*tex;
	if (side == 0)
	{
		if (ray.dir_x > 0)
			tex = &vars->texture.we_tex;
		else
			tex = &vars->texture.ea_tex;
	}
	else
	{
		if (ray.dir_y > 0)
			tex = &vars->texture.no_tex;
		else
			tex = &vars->texture.so_tex;
	}
	
	
	float	wall_x;
	if (side == 0)
		wall_x = player->y + ray.perp_wall_dist * ray.dir_y;
	else
		wall_x = player->x + ray.perp_wall_dist * ray.dir_x;
	wall_x -= floor(wall_x);
	int	tex_x = (int)(wall_x * (float)tex->width);
	if ((side == 0 && ray.dir_x > 0) || (side == 1 && ray.dir_y < 0))
		tex_x = tex->width - tex_x - 1;



	int	y;
	int	d;
	int	tex_y;
	unsigned int	color;
	y = draw_start;
	while (y < draw_end)
	{
		d = y * 256 - WIN_HEI * 128 + line_height * 128;
		tex_y = ((d * tex->height) / line_height) / 256;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		char	*pixel = tex->addr + (tex_y * tex->line_size + tex_x * (tex->bbp / 8));
		color = *(unsigned int *)pixel;
		my_mlx_pixel_put(&vars->img, screen_x, y, color);
		y++;
	}
}

void	draw_raycasting(t_vars *vars)
{
	int	x;

	x = 0;
	while (x < WIN_LEN)
	{
		cast_ray(vars, x);
		x++;
	}
}

int	game_loop(t_vars *vars)
{
	ft_memset(vars->img.addr, 0, WIN_LEN * WIN_HEI * (vars->img.bbp / 8));
	handle_movement(vars);
	handle_rotation(vars);
	init_ray_data(vars, &vars->ray);
	clear_background(vars, vars->texture.ceiling.color, vars->texture.floor.color);
	draw_raycasting(vars);
	draw_map(vars);
	draw_fov(vars, vars->ray);
	draw_player(vars, vars->player);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}
