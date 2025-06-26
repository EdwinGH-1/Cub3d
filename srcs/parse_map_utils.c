/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:14:33 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/26 12:39:07 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_valid_map_row(t_map *map)
{
	int	y;
	int	x1;
	int	x2;

	y = 0;
	while (y < map->y_max)
	{
		x1 = 0;
		x2 = map->x_max - 1;
		while (map->point[y][x1].value == -1)
			x1++;
		while (map->point[y][x2].value == -1)
			x2--;
		if (map->point[y][x1].value != 1 || map->point[y][x2].value != 1)
			return (false);
		if (y == 0 || y == map->y_max - 1)
		{
			while (++x1 < x2)
				if (map->point[y][x1].value == 0)
					return (false);
		}
		y++;
	}
	return (true);
}

bool	is_valid_map_col(t_map *map)
{
	int	x;
	int	y1;
	int	y2;

	x = 0;
	while (x < map->x_max)
	{
		y1 = 0;
		y2 = map->y_max - 1;
		while (map->point[y1][x].value == -1)
			y1++;
		while (map->point[y2][x].value == -1)
			y2--;
		if (map->point[y1][x].value != 1 || map->point[y2][x].value != 1)
			return (false);
		if (x == 0 || x == map->x_max - 1)
		{
			while (++y1 < y2)
				if (map->point[y1][x].value == 0)
					return (false);
		}
		x++;
	}
	return (true);
}

bool	is_valid_player(t_map *map)
{
	int	player_count;
	int	x;
	int	y;

	y = 0;
	player_count = 0;
	while (y < map->y_max)
	{
		x = 0;
		while (x < map->x_max)
		{
			if (map->point[y][x].value == 'N'
				|| map->point[y][x].value == 'S'
				|| map->point[y][x].value == 'W'
				|| map->point[y][x].value == 'E')
				player_count++;
			x++;
		}
		y++;
	}
	if (player_count == 1)
		return (true);
	return (false);
}

bool	is_map(char *str)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]) == 0 && str[i] != '1' && str[i] != '0'
			&& str[i] != 'N' && str[i] != 'S' && str[i] != 'E'
			&& str[i] != 'W' && str[i] != 'D' && str[i] != '\n')
			return (false);
		if (ft_isspace(str[i]) == 1)
			count++;
		i++;
	}
	if (count == ft_strlen(str))
		return (false);
	return (true);
}

void	init_map_points(t_vars *vars, t_map *map)
{
	int	y;

	map->point = malloc(map->y_max * sizeof(t_point *));
	if (map->point == NULL)
	{
		ft_putstr_fd("Error malloc\n", 2);
		delete_and_free_vars(vars);
		exit(1);
	}
	y = 0;
	while (y < map->y_max)
	{
		map->point[y] = malloc(map->x_max * sizeof(t_point));
		if (map->point[y] == NULL)
		{
			ft_putstr_fd("Error malloc\n", 2);
			delete_and_free_vars(vars);
			exit(1);
		}
		y++;
	}
}
