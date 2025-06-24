/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:05:39 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/24 21:03:49 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_map_size(t_map *map, int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str != NULL)
	{
		if (is_map(str) == true)
		{
			if ((int)ft_strlen(str) > map->x_max)
				map->x_max = ft_strlen(str) - 1;
			map->y_max++;
		}
		free(str);
		str = get_next_line(fd);
	}
}

void	parse_map_size(t_vars *vars, t_map *map, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error opening file\n", 2);
		delete_and_free_vars(vars);
		exit(1);
	}
	get_map_size(map, fd);
	close(fd);
	if (map->x_max == 0 || map->y_max == 0)
	{
		ft_putstr_fd("Error\nInvalid map size\n", 2);
		delete_and_free_vars(vars);
		exit(1);
	}
}

void	get_map_values_row(t_map *map, char *str, int y)
{
	int	x;

	x = 0;
	while (x < map->x_max)
	{
		if (x >= (int)ft_strlen(str) || ft_isspace(str[x]) == 1)
			map->point[y][x].value = -1;
		else if (ft_isdigit(str[x]) == 1)
			map->point[y][x].value = str[x] - '0';
		else
			map->point[y][x].value = str[x];
		map->point[y][x].x = x;
		map->point[y][x].y = y;
		x++;
	}
}

void	get_map_values(t_map *map, int fd)
{
	char	*str;
	int		x;
	int		y;

	y = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		if (is_map(str) == true)
		{
			x = 0;
			get_map_values_row(map, str, y);
			y++;
		}
		free(str);
		str = get_next_line(fd);
	}
}

void	parse_map_values(t_vars *vars, t_map *map, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error opening file\n", 2);
		delete_and_free_vars(vars);
		exit(1);
	}
	get_map_values(map, fd);
	close (fd);
}
