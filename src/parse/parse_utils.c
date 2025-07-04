/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:16:21 by jothomas          #+#    #+#             */
/*   Updated: 2025/07/04 16:41:06 by jothomas         ###   ########.fr       */
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
			&& str[i] != 'W' && str[i] != 'D' && str[i] != 'O'
			&& str[i] != '\n')
			return (false);
		if (ft_isspace(str[i]) || str[i] == '\n')
			count++;
	}
	if (count == ft_strlen(str))
		return (false);
	return (true);
}

bool	set_bounds(t_meta *meta, char *file)
{
	int		fd;
	char	*str;

	fd = open(file, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		meta->parse.is_map = set_textures(meta, str);
		if (meta->parse.is_map < 0)
			return (close(fd), free(str), false);
		if (meta->parse.is_map == 1 && is_map(str))
		{
			if ((int)ft_strlen(str) > meta->map.x_max)
				meta->map.x_max = ft_strlen(str) - 1;
			meta->map.y_max++;
		}
		if (!meta->map.y_max)
			meta->parse.map_start++;
		free(str);
	}
	if (!meta->map.x_max || !meta->map.y_max)
		return (close(fd), ft_putstr_fd("Invalid Map\n", 2), false);
	return (close(fd), true);
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

void	free_texture(t_meta *meta)
{
	if (meta->parse.textures[NO])
		free(meta->map.texture[NO].path);
	if (meta->parse.textures[SO])
		free(meta->map.texture[SO].path);
	if (meta->parse.textures[EA])
		free(meta->map.texture[EA].path);
	if (meta->parse.textures[WE])
		free(meta->map.texture[WE].path);
	if (meta->parse.textures[DO])
		free(meta->map.texture[DO].path);
}
