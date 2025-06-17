/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:33:00 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/17 14:45:52 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	grab_color(char *str, char **color)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 0;
	if (*color)
		return (ft_putstr_fd("Invalid Map\n", 2), false);
	str++;
	while (ft_isspace(*str))
		str++;
	while (str[i] != ',')
		i++;
	str[i] = '\0';
	
	return (true);
}

bool	grab_texture(char *str, char **texture)
{
	int	i;
	int	n;

	if (*texture)
		return (ft_putstr_fd("Invalid Map\n", 2), false);
	i = 1;
	while (ft_isspace(str[++i]))
		;
	n = i;
	while (str[++n])
		;
	*texture = ft_substr(str, i, n - i + 1);
	if (!check_extension(texture, ".xlm"))
		return (ft_putstr_fd("Invalid texture\n", 2), false);
	return (true);
}

int	set_textures(char *str, t_map *map)
{
	if (map->texture.ceiling && map->texture.floor
		&& map->texture.no && map->texture.so
		&& map->texture.we && map->texture.ea)
		return (0);
	if ((!ft_strcmp(str, "NO") && !grab_texture(str, &map->texture.no))
		|| (!ft_strcmp(str, "SO") && !grab_texture(str, &map->texture.so))
		|| (!ft_strcmp(str, "EA") && !grab_texture(str, &map->texture.ea))
		|| (!ft_strcmp(str, "WE") && !grab_texture(str, &map->texture.we))
		|| (!ft_strcmp(str, "F") && !grab_color(str, &map->texture.floor))
		|| (!ft_strcmp(str, "C") && !grab_color(str, &map->texture.ceiling)))
		return (-1);
}
