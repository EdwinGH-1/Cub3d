/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:16:21 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/16 15:34:26 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*grab_texture(char *str)
{
	int	i;
	int	n;

	i = -1;
	while (ft_isspace(str[++i]))
		;
	n = i;
	while (str[++n])
		;
	return (ft_substr(str, i, n - i + 1));
}

bool	is_map(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (!ft_isspace(str[i]))
				return (false);
			count++;
		}
	}
	if (!count)
		return (false);
	return (true);
}

bool	set_bounds(char *file, t_map *map)
{
	char	*str;
	int		fd;
	int		count;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Invalid File\n", 2), false);
	while (1)
	{
		str = get_next_line(fd);
		if (!str || (map->y_max && !is_map(str)))
			break ;
		if (is_map(str))
		{
			count = -1;
			while (str[++count])
				;
			if (count > map->x_max)
				map->x_max = count;
			map->y_max++;
		}
		free(str);
	}
	return (true);
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
