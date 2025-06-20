/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:12:09 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/20 21:50:11 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <stdbool.h>

bool	check_start(t_map *map, t_point *pos)
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
			if (map->point[y][x].value == 'N' || map->point[y][x].value == 'S'
				|| map->point[y][x].value == 'E'
				|| map->point[y][x].value == 'W')
			{
				start++;
				*pos = map->point[y][x];
			}
			x++;
		}
		y++;
	}
	if (start != 1)
		return (false);
	return (true);
}

bool	check_row(t_point *point, t_map *map, t_point *pos)
{
	int	x1;
	int	x2;

	x1 = 0;
	x2 = map->x_max - 1;
	while (point[x1].value == -1)
		x1++;
	while (point[x2].value == -1)
		x2--;
	if (point[x1].value != 1 || point[x2].value != 1)
		return (false);
	if (point[x1].y == 0 || point[x1].y == map->y_max - 1)
	{
		while (++x1 < x2)
			if (!point[x1].value)
				return (false);
	}
	if (point[x1].y == map->y_max - 1 && !check_start(map, pos))
		return (false);
	return (true);
}

// bool	basic_check(t_map *map, int *fd, char *file)//int argc)
// {
// 	if (argc != 2)
// 		return (ft_putstr_fd("Incorrect Argument Count\n", 2), false);
// 	if (!check_extension(file, ".cub"))
// 		return (ft_putstr_fd("Invalid File Type\n", 2), false);
// 	*fd = open(file, O_RDONLY);
// 	if (*fd < 0)
// 		return (ft_putstr_fd("Invalid File\n", 2), false);
// 	if (!set_bounds(map, file))
// 		return (ft_putstr_fd("Invalid Map\n", 2), false);
// 	map->point = malloc((map->y_max) * sizeof(t_point *));
// 	if (!map->point)
// 		return (ft_putstr_fd("Malloc Error\n", 2), false);
// 	return (true);
// }

bool	set_map(char *str, t_map *map, int y, t_point *pos)
{
	int	x;

	x = 0;
	map->point[y] = malloc(map->x_max * (sizeof(t_point)));
	while (x < map->x_max)
	{
		if (x >= (int)ft_strlen(str) || ft_isspace(str[x]))
			map->point[y][x].value = -1;
		else if (ft_isdigit(str[x]))
			map->point[y][x].value = str[x] - '0';
		else
			map->point[y][x].value = str[x];
		map->point[y][x].x = x;
		map->point[y][x].y = y;
		x++;
	}
	if (!check_row(map->point[y], map, pos))
		return (free_part(map, y), free_texture(map),
			ft_putstr_fd("Invalid Map Format\n", 2), false);
	return (true);
}

// bool	parse_file(char **argv, t_vars *vars, int argc)
// {
// 	char	*str;
// 	int		fd;
// 	int		is_texture;
// 	int		y;
//
// 	if (!basic_check(&vars->map, &fd, argv[1]))
// 		return (false);
// 	y = 0;
// 	while (1)
// 	{
// 		str = get_next_line(fd);
// 		if (!str)
// 			break ;
// 		is_texture = set_textures(str, &vars->map);
// 		if (!is_texture && y < vars->map.y_max && is_map(str))
// 		{
// 			if (!set_map(str, &vars->map, y++, &vars->player.pos))
// 				return (free(str), false);
// 		}
// 		else if (is_texture == -1)
// 			return (free(str), false);
// 		free(str);
// 	}
// 	return (true);
// }

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

void	get_map_size(t_map *map, char *file)
{
	int		fd;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error opening file\n", 2);
		exit(1);
	}
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		if (is_map(str) == true)
		{
			if ((int)ft_strlen(str) > map->x_max)
				map->x_max = ft_strlen(str) - 1;
			map->y_max++;
		}
		free(str);
	}
	close (fd);
	if (map->x_max == 0 || map->y_max == 0)
	{
		ft_putstr_fd("Error\nInvalid map size\n", 2);
		exit(1);
	}
}

bool	is_valid_extension(char *filename, char *extension)
{
	int	count;

	count = ft_strlen(extension);
	while (*filename != '\0')
		filename++;
	while (*extension != '\0')
		extension++;
	while (count >= 0)
	{
		if (*extension != *filename)
			return (false);
		extension--;
		filename--;
		count--;
	}
	return (true);
}

bool	is_valid_file(char *file)
{
	int	fd;

	if (is_valid_extension(file, ".cub") == false)
	{
		ft_putstr_fd("Error\nInvalid file type\n", 2);
		return (false);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nInvalid file\n", 2);
		return (false);
	}
	close(fd);
	return (true);
}

bool	is_texture(char *str)
{
	if (ft_strncmp(str, "NO", 2) != 0
		|| ft_strncmp(str, "SO", 2) != 0
		|| ft_strncmp(str, "WE", 2) != 0
		|| ft_strncmp(str, "EA", 2) != 0)
		return (true);
	return (true);
}

bool	is_color(char *str)
{
	if (ft_strncmp(str, "C", 1) != 0
		|| ft_strncmp(str, "F", 1) != 0)
		return (true);
	return (true);
}

void	set_texture(char *str, t_texture *texture)
{


}

void	set_color(char *str, t_texture *texture)
{

}

bool	is_valid_texture(char *str)
{
	char	**split;

	split = ft_split(str, ' ');
	if (split == NULL)
	{
		ft_putstr_fd("Error splitting\n", 2);
		return (false);
	}
	if (ft_strncmp(str, "NO ", 3) != 0 || ft_strncmp(str, "SO ", 3) != 0
		|| ft_strncmp(str, "WE ", 3) != 0 || ft_strncmp(str, "EA ", 3) != 0)
	{
		ft_putstr_fd("Error\nInvalid texture format\n", 2);
		return (false);
	}
	str += 2;
	while (ft_isspace(*str) == 1)
		str++;
	if (is_valid_extension(str, ".xpm") == false)
		return (false);
	return (true);
}

bool	is_valid_color(char *str)
{
	if (ft_strncmp(str, "C ", 2) != 0
		|| ft_strncmp(str, "F ", 2) != 0)
	{
		ft_putstr_fd("Error\nInvalid color format\n", 2);
		return (false);
	}
	return (true);
}

void	get_textures_and_color(char *file, t_vars *vars)
{
	char	*str;
	int		fd;
	int		error;

	error = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error opening file\n", 2);
		exit(1);
	}
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		if (is_texture(str) == true)
		{
			if(is_valid_texture(str) == true)
				set_texture(str, &vars->map.texture);
			else
			{
				error = 1;
				free(str);
				break ;
			}
		}
		if (is_color(str) == true)
		{
			if (is_valid_color(str) == true)
				set_color(str, &vars->map.texture);
			else
			{
				error = 1;
				free(str);
				break ;
			}
		}
		free(str);
	}
	close(fd);
	if (error == 1)
	{
		delete_and_free_vars(vars);
		exit(1);
	}
}

bool	parse_file(char **argv, t_vars *vars)
{

	if (is_valid_file(argv[1]) == false)
		exit(1);
	get_textures_and_color(argv[1], vars);
	get_map_size(&vars->map, argv[1]);
	vars->map.point = malloc((vars->map.y_max) * sizeof(t_point *));
	if (vars->map.point == NULL)
	{
		ft_putstr_fd("Malloc error\n", 2);
		exit (1);
	}
	return (true);
}
