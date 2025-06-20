/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:26:21 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/20 18:04:58 by jthiew           ###   ########.fr       */
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
		exit (1);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bbp, &tex->line_size, &tex->endian);
}

void	init_data(t_vars *vars)
{
	init_mlx_data(vars);
	init_minimap_data(&vars->minimap);
	init_player_data(vars, &vars->map, &vars->player);
	load_texture(vars, &vars->map.texture.no_tex, "./textures/AnyConv.com__BRICK_1A.xpm");
	load_texture(vars, &vars->map.texture.so_tex, "./textures/AnyConv.com__BRICK_2B.xpm");
	load_texture(vars, &vars->map.texture.ea_tex, "./textures/AnyConv.com__BRICK_3B.xpm");
	load_texture(vars, &vars->map.texture.we_tex, "./textures/AnyConv.com__BRICK_3D.xpm");
}

int	main(void)
{
	t_vars	vars;

	ft_memset(&vars, 0, sizeof(t_vars));
	get_map(&vars);
	init_data(&vars);
	launch_render(&vars);
	return (0);
}
