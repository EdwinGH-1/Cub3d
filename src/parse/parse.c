/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:12:09 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/23 15:50:42 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	check_start(t_map *map, t_pixel *pos)
{
	int	start;
	int	x;
	int	y;

	y = 0;
	start = 0;
	while (y < map->y_max)
	{
		x = 0;
		while (x < map->x_max)
		{
			if (map->pixel[y][x].value == 'N' || map->pixel[y][x].value == 'S'
				|| map->pixel[y][x].value == 'E'
				|| map->pixel[y][x].value == 'W')
			{
				start++;
				map->x_offset -= x * MINI_SIZE
					- MINI_RAD - MINI_POS + (MINI_SIZE / 2);
				map->y_offset -= y * MINI_SIZE
					- MINI_RAD - MINI_POS + (MINI_SIZE / 2);
			}
			x++;
		}
		y++;
	}
	if (start != 1)
		return (false);
	return (true);
}

bool	check_row(t_pixel *pixel, t_map *map, t_pixel *pos)
{
	int	x1;
	int	x2;

	x1 = 0;
	x2 = map->x_max - 1;
	while (pixel[x1].value == -1)
		x1++;
	while (pixel[x2].value == -1)
		x2--;
	if (pixel[x1].value != 1 || pixel[x2].value != 1)
		return (false);
	if (pixel[x1].y == 0 || pixel[x1].y == map->y_max - 1)
	{
		while (++x1 < x2)
			if (!pixel[x1].value)
				return (false);
	}
	if (pixel[x1].y == map->y_max - 1 && !check_start(map, pos))
		return (false);
	return (true);
}

bool	basic_check(t_map *map, int *fd, char *file, int argc)
{
	if (argc != 2)
		return (ft_putstr_fd("Incorrect Argument Count\n", 2), false);
	if (!check_extension(file, ".cub"))
		return (ft_putstr_fd("Invalid File Type\n", 2), false);
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		return (ft_putstr_fd("Invalid File\n", 2), false);
	if (!set_bounds(map, file))
		return (ft_putstr_fd("Invalid Map\n", 2), false);
	map->pixel = malloc((map->y_max) * sizeof(t_pixel *));
	if (!map->pixel)
		return (ft_putstr_fd("Malloc Error\n", 2), false);
	return (true);
}

bool	set_map(char *str, t_map *map, int y, t_pixel *pos)
{
	int	x;

	x = 0;
	map->pixel[y] = malloc(map->x_max * (sizeof(t_pixel)));
	while (x < map->x_max)
	{
		if (x >= (int)ft_strlen(str) || ft_isspace(str[x]))
			map->pixel[y][x].value = -1;
		else if (ft_isdigit(str[x]))
			map->pixel[y][x].value = str[x] - '0';
		else
			map->pixel[y][x].value = str[x];
		map->pixel[y][x].x = x;
		map->pixel[y][x].y = y;
		x++;
	}
	if (!check_row(map->pixel[y], map, pos))
		return (free_part(map, y), free_texture(map),
			ft_putstr_fd("Invalid Map Format\n", 2), false);
	return (true);
}

bool	parse_map(int argc, char **argv, t_meta *meta)
{
	char	*str;
	int		fd;
	int		is_texture;
	int		y;

	ft_memset(meta, 0, sizeof(t_meta));
	if (!basic_check(&meta->map, &fd, argv[1], argc))
		return (false);
	y = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		is_texture = set_textures(str, &meta->map);
		if (!is_texture && y < meta->map.y_max && is_map(str))
		{
			if (!set_map(str, &meta->map, y++, &meta->player.pos))
				return (free(str), false);
		}
		else if (is_texture == -1)
			return (free(str), false);
		free(str);
	}
	return (true);
}
