/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:16:21 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/17 15:29:43 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	is_map(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (!ft_isspace(str[i]) && str[i] != '1' && str[i] != '0'
			&& str[i] != 'N' && str[i] != 'S' && str[i] != 'E'
			&& str[i] != 'W' && str[i] != 'D')
			return (false);
		if (ft_isspace(str[i]))
			count++;
	}
	if (count == ft_strlen(str))
		return (false);
	return (true);
}

bool	check_extension(char *file, char *extension)
{
	while (file && *file != *extension)
		file++;
	if (!file)
		return (false);
	if (ft_strcmp(file, extension))
		return (false);
	return (true);
}

int	map_pos(char *file)
{
	char	*str;
	int		fd;
	int		count;
	int		pos;

	count = 0;
	pos = -1;
	fd = open(file, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		count++;
		if (is_str_space(str))
			pos = count;
		free(str);
	}
	return (pos + 1);
}

void	set_bounds(t_map *map, char *file)
{
	int		fd;
	char	*str;
	int		count;
	int		pos;

	fd = open(file, O_RDONLY);
	pos = map_pos(file);
	count = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str || (count >= pos && is_str_space(str)))
			break ;
		count++;
		if (count >= pos)
		{
			if (ft_strlen(str) > map->x_max)
				map->x_max = ft_strlen(str);
		}
		free(str);
	}
	map->y_max = count - pos + 1;
}

void	terminate(t_vars *vars)
{
	if (vars->map.pixel)
		free(vars->map.pixel);
	if (vars->map.texture.no)
		free(vars->map.texture.no);
	if (vars->map.texture.so)
		free(vars->map.texture.so);
	if (vars->map.texture.ea)
		free(vars->map.texture.ea);
	if (vars->map.texture.we)
		free(vars->map.texture.we);
	if (vars->map.texture.floor)
		free(vars->map.texture.floor);
	if (vars->map.texture.ceiling)
		free(vars->map.texture.ceiling);
}
