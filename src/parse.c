/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:12:09 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/16 15:44:35 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

bool	initialise_map(t_map *map, char *file)
{
	map->texture.no = NULL;
	map->texture.so = NULL;
	map->texture.we = NULL;
	map->texture.ea = NULL;
	map->texture.floor = 0;
	map->texture.ceiling = 0;
	map->x_max = 0;
	map->y_max = 0;
	if (!set_bounds(file, map))
		return (false);
	if (!map->y_max || !map->x_max)
		return (ft_putstr_fd("Invalid Map\n", 2), false);
	map->pixel = malloc((map->x_max * map->y_max) * sizeof(t_pixel));
	if (!map->pixel)
		return (ft_putstr_fd("Malloc Error\n", 2), false);
	return (true);
}

bool	set_textures(char *str, t_map *map)
{
	char	*texture;

	texture = NULL;
	if (ft_strcmp(str, "NO"))
		texture = map->texture.no;
	else if (ft_strcmp(str, "SO"))
		texture = map->texture.so;
	else if (ft_strcmp(str, "WE"))
		texture = map->texture.we;
	else if (ft_strcmp(str, "EA"))
		texture = map->texture.ea;
	else if (ft_strcmp(str, "F"))
		texture = map->texture.floor;
	else if (ft_strcmp(str, "C"))
		texture = map->texture.ceiling;
	else
		return (true);
	if (texture)
		return (ft_putstr_fd("Invalid Map\n", 2), false);
	map->texture.no = grab_texture(str);
	return (true);
}

bool	set_map(t_map *map, int *y, char *str)
{
	int		x;

	x = 0;
	while (x <= map->x_max && *y <= map->y_max)
	{
		if (ft_isspace(str[x]))
			map->pixel[*y][x].value = -1;
		else
			map->pixel[*y][x].value = str[x];
		map->pixel[*y][x].x = x;
		map->pixel[*y][x].y = *y;
	}
	*y++;
}

bool	parse_map(int argc, char **argv, t_vars *vars)
{
	char	*str;
	int		fd;
	int		y;

	if (argc != 2)
		return (ft_putstr_fd("Incorrect Argument Count\n", 2), false);
	if (!initialise_map(&vars->map, argv[1]))
		return (false);
	fd = open(argv[1], O_RDONLY);
	y = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		if (!is_map(str) && !y)
		{
			if (!set_textures(str, &vars->map))
				return (terminate(vars), free(str), false);
		}
		else
			set_map(&vars->map, &y, str);
		free(str);
	}
	return (true);
}
