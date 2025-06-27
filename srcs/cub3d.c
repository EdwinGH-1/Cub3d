/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:46:24 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/27 16:24:12 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	launch_render(t_vars *vars)
{
	hook_handler(vars);
	mlx_mouse_move(vars->mlx, vars->win, WIN_LEN / 2, WIN_HEI / 2);
	mlx_mouse_hide(vars->mlx, vars->win);
	mlx_loop_hook(vars->mlx, game_loop, vars);
	mlx_loop(vars->mlx);
}

void	init_data(t_vars *vars)
{
	init_mlx_data(vars);
	init_texture_data(vars, &vars->texture);
	init_animation_data(vars, &vars->animation);
	init_minimap_data(&vars->minimap);
	init_player_data(vars, &vars->map, &vars->player);
	gettimeofday(&vars->time.last_frame_time, NULL);
	vars->time.last_print_time = vars->time.last_frame_time;
}

void	parse_file(char **argv, t_vars *vars)
{
	if (is_valid_file(argv[1]) == false)
		exit(1);
	parse_texture(vars, argv[1]);
	parse_color(vars, argv[1]);
	if (is_texture_filled(vars->texture) == false)
	{
		delete_and_free_vars(vars);
		exit(1);
	}
	parse_map(vars, argv[1]);
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
