/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:12:09 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/17 15:45:05 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	initialise_map(t_map *map, int *fd, char *file, int argc)
{
	map->texture.no = NULL;
	map->texture.so = NULL;
	map->texture.we = NULL;
	map->texture.ea = NULL;
	map->texture.floor = 0;
	map->texture.ceiling = 0;
	map->x_max = 0;
	map->y_max = 0;
	if (argc != 2)
		return (ft_putstr_fd("Incorrect Argument Count\n", 2), false);
	if (!check_extension(file, ".cub"))
		return (ft_putstr_fd("Invalid File Type\n", 2), false);
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		return (ft_putstr_fd("Invalid File\n", 2), false);
	set_bounds(map, file);
	map->pixel = malloc((map->y_max) * sizeof(t_pixel *));
	if (!map->pixel)
		return (ft_putstr_fd("Malloc Error\n", 2), false);
	return (true);
}

bool	set_map(char *str, t_map *map, int *y)
{
	int	x;
	int	value;

	x = 0;
	map->pixel[*y] = malloc(map->x_max * (sizeof(t_pixel)));
	while (x <= map->x_max)
	{
		if (ft_isspace(str[x]) || x >= ft_strlen(str))
			map->pixel[*y][x].value = -1;
		else
			map->pixel[*y][x].value = str[x];
		map->pixel[*y][x].x = x;
		map->pixel[*y][x].y = *y;
		x++;
	}
	if (!is_valid_map(map, *y))
		return (false);
	*y++;
	return (true);
}

bool	parse_map(int argc, char **argv, t_vars *vars)
{
	char	*str;
	int		fd;
	int		is_texture;
	int		y;

	if (!initialise_map(&vars->map, &fd, argv[1], argc))
		return (false);
	y = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		is_texture = set_textures(str, &vars->map);
		if (!is_texture && is_map(str))
			set_map(str, &vars->map, &y);
		else if (is_texture == -1)
			return (terminate(vars), free(str), false);
		free(str);
	}
	return (true);
}
