/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:59:27 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/24 21:01:06 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse_map(t_vars *vars, char *file)
{
	if (is_texture_filled(vars->texture) == false)
	{
		delete_and_free_vars(vars);
		exit(1);
	}
	parse_map_size(vars, &vars->map, file);
	init_map_points(vars, &vars->map);
	parse_map_values(vars, &vars->map, file);
	if (is_valid_map(&vars->map) == false
		|| is_valid_player(&vars->map) == false)
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		delete_and_free_vars(vars);
		exit(1);
	}
}

void	parse_color(t_vars *vars, char *file)
{
	int		fd;
	int		is_error;

	is_error = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error opening file\n", 2);
		delete_and_free_vars(vars);
		exit(1);
	}
	get_color_data(vars, fd, &is_error);
	close(fd);
}

void	parse_texture(t_vars *vars, char *file)
{
	int		fd;
	int		is_error;

	is_error = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error opening file\n", 2);
		delete_and_free_vars(vars);
		exit(1);
	}
	get_texture_data(vars, fd, &is_error);
	close(fd);
}

void	parse_file(char **argv, t_vars *vars)
{
	if (is_valid_file(argv[1]) == false)
		exit(1);
	parse_texture(vars, argv[1]);
	parse_color(vars, argv[1]);
	parse_map(vars, argv[1]);
}
