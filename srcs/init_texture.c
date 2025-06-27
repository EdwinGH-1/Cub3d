/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 07:04:52 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/27 20:42:30 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	load_texture(t_vars *vars, t_tex_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(vars->mlx, path,
			&tex->width, &tex->height);
	if (tex->img == NULL)
	{
		ft_putstr_fd("error: failed to load texture\n", 2);
		delete_and_free_vars(vars);
		exit(1);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bbp,
			&tex->line_size, &tex->endian);
}

void	init_texture_data(t_vars *vars, t_texture *texture)
{
	load_texture(vars, &texture->no_tex, texture->no_tex.path);
	load_texture(vars, &texture->so_tex, texture->so_tex.path);
	load_texture(vars, &texture->ea_tex, texture->ea_tex.path);
	load_texture(vars, &texture->we_tex, texture->we_tex.path);
	load_texture(vars, &texture->door_tex, texture->door_tex.path);
}
