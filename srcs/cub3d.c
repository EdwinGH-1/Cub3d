/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:46:24 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/24 20:56:21 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	launch_render(t_vars *vars)
{
	hook_handler(vars);
	mlx_loop_hook(vars->mlx, game_loop, vars);
	mlx_loop(vars->mlx);
}

void	init_minimap_data(t_minimap *minimap)
{
	minimap->size = WIN_LEN / 7;
	minimap->edge_offset = WIN_LEN / 100;
	minimap->right_align = WIN_LEN - minimap->size - minimap->edge_offset;
	minimap->cell_size = minimap->size / 10;
	minimap->border = minimap->cell_size / (minimap->cell_size * BORDER_SIZE);
}

void	load_texture(t_vars *vars, t_tex_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(vars->mlx, path, &tex->width, &tex->height);
	if (tex->img == NULL)
	{
		ft_putstr_fd("error: failed to load texture\n", 2);
		delete_and_free_vars(vars);
		exit(1);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bbp, &tex->line_size, &tex->endian);
}

void	init_data(t_vars *vars)
{
	init_mlx_data(vars);
	init_minimap_data(&vars->minimap);
	init_player_data(vars, &vars->map, &vars->player);
	printf("%s\n", vars->texture.no_tex.path);
	printf("%s\n", vars->texture.so_tex.path);
	printf("%s\n", vars->texture.we_tex.path);
	printf("%s\n", vars->texture.ea_tex.path);
	load_texture(vars, &vars->texture.no_tex, vars->texture.no_tex.path);
	load_texture(vars, &vars->texture.so_tex, vars->texture.so_tex.path);
	load_texture(vars, &vars->texture.ea_tex, vars->texture.ea_tex.path);
	load_texture(vars, &vars->texture.we_tex, vars->texture.we_tex.path);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./cub3d *.cub\n", 2);
		return (1);
	}
	else
	{
		ft_memset(&vars, 0, sizeof(t_vars));
		parse_file(argv, &vars);
		init_data(&vars);
		launch_render(&vars);
	}
	return (0);
}
