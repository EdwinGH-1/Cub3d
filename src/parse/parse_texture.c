/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshua <joshua@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:33:00 by jothomas          #+#    #+#             */
/*   Updated: 2025/07/01 20:16:32 by joshua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	check_extension(char *file, char *extension)
{
	int	count;

	count = ft_strlen(extension);
	while (*file)
		file++;
	while (*extension)
		extension++;
	while (--count)
	{
		if (*extension != *file)
			return (false);
		extension--;
		file--;
	}
	return (true);
}

bool	grab_color(char *str, unsigned int *color)
{
	char	**colors;
	int		r;
	int		g;
	int		b;

	if (*color)
		return (ft_putstr_fd("Invalid Color\n", 2), false);
	str++;
	while (*str && ft_isspace(*str))
		str++;
	colors = ft_split(str, ',');
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	*color = ((r & 0xff) << 16) | ((g & 0xff) << 8) | (b & 0xff);
	memfree_array((void **)colors);
	return (true);
}

bool	grab_texture(char *str, char **texture)
{
	int	i;
	int	n;

	if (*texture)
		return (ft_putstr_fd("Invalid Texture\n", 2), false);
	i = 1;
	while (ft_isspace(str[++i]))
		;
	n = i;
	while (str[n] && str[n] != '\n')
		n++;
	*texture = ft_substr(str, i, n - i);
	if (!check_extension(*texture, ".xpm"))
		return (ft_putstr_fd("Invalid texture type\n", 2), false);
	return (true);
}

int	set_textures(char *str, t_map *map)
{
	if (map->texture.ceiling && map->texture.floor
		&& map->texture.no && map->texture.so
		&& map->texture.we && map->texture.ea)
		return (0);
	if ((!ft_strncmp(str, "NO ", 3) && !grab_texture(str, &map->texture.no))
		|| (!ft_strncmp(str, "SO ", 3) && !grab_texture(str, &map->texture.so))
		|| (!ft_strncmp(str, "EA ", 3) && !grab_texture(str, &map->texture.ea))
		|| (!ft_strncmp(str, "WE ", 3) && !grab_texture(str, &map->texture.we))
		|| (!ft_strncmp(str, "C", 1) && !grab_color(str, &map->texture.ceiling))
		|| (!ft_strncmp(str, "F", 1) && !grab_color(str, &map->texture.floor)))
		return (free_texture(map), -1);
	return (1);
}
