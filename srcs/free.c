/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:47:11 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/20 18:08:03 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_textures(t_vars *vars, t_texture *texture)
{
	if (texture->no != NULL)
		free(texture->no);
	if (texture->so != NULL)
		free(texture->so);
	if (texture->we != NULL)
		free(texture->we);
	if (texture->ea != NULL)
		free(texture->ea);
	if (texture->no_tex.img != NULL)
		mlx_destroy_image(vars->mlx, texture->no_tex.img);
	if (texture->so_tex.img != NULL)
		mlx_destroy_image(vars->mlx, texture->so_tex.img);
	if (texture->we_tex.img != NULL)
		mlx_destroy_image(vars->mlx, texture->we_tex.img);
	if (texture->ea_tex.img != NULL)
		mlx_destroy_image(vars->mlx, texture->ea_tex.img);
}

void	free_map(t_vars *vars)
{
	int	y;

	if (vars->map.point != NULL)
	{
		y = 0;
		while (y < vars->map.y_max && vars->map.point[y] != NULL)
		{
			if (vars->map.point[y] != NULL)
				free(vars->map.point[y]);
			y++;
		}
		free(vars->map.point);
	}
}

void	free_mlx(t_vars *vars)
{
	if (vars->img.img != NULL)
		mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->win != NULL)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx != NULL)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
}

void	delete_and_free_vars(t_vars *vars)
{
	free_textures(vars, &vars->map.texture);
	free_map(vars);
	free_mlx(vars);
}
