/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:18:06 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/18 13:35:44 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_mlx_data(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
	{
		delete_and_free_vars(vars);
		exit (1);
	}
	vars->win = mlx_new_window(vars->mlx, WIN_LEN, WIN_HEI, WIN_NAME);
	if (vars->win == NULL)
	{
		delete_and_free_vars(vars);
		exit (1);
	}
	vars->img.img = mlx_new_image(vars->mlx, WIN_LEN, WIN_HEI);
	if (vars->img.img == NULL)
	{
		delete_and_free_vars(vars);
		exit (1);
	}
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bbp,
			&vars->img.line_size, &vars->img.endian);
}
