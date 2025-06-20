/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:16:21 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/20 14:49:38 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	is_map(char *str)
{
	int		i;
	size_t	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (!ft_isspace(str[i]) && str[i] != '1' && str[i] != '0'
			&& str[i] != 'N' && str[i] != 'S' && str[i] != 'E'
			&& str[i] != 'W' && str[i] != 'D' && str[i] != '\n')
			return (false);
		if (ft_isspace(str[i]))
			count++;
	}
	if (count == ft_strlen(str))
		return (false);
	return (true);
}

bool	set_bounds(t_map *map, char *file)
{
	int		fd;
	char	*str;

	fd = open(file, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		if (is_map(str))
		{
			if ((int)ft_strlen(str) > map->x_max)
				map->x_max = ft_strlen(str) - 1;
			map->y_max++;
		}
		free(str);
	}
	if (!map->x_max || !map->y_max)
		return (false);
	return (true);
}

void	free_part(t_map *map, int y)
{
	int	count;

	count = 0;
	while (count <= y)
	{
		free(map->pixel[count]);
		count++;
	}
}

void	memfree_array(void **array)
{
	int		i;
	char	**str;

	str = (char **)array;
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	free_texture(t_map *map)
{
	if (map->texture.no)
		free(map->texture.no);
	if (map->texture.so)
		free(map->texture.so);
	if (map->texture.ea)
		free(map->texture.ea);
	if (map->texture.we)
		free(map->texture.we);
	if (map->pixel)
		free(map->pixel);
}
