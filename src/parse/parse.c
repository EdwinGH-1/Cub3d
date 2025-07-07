/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:12:09 by jothomas          #+#    #+#             */
/*   Updated: 2025/07/07 15:30:32 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	init_parse(t_meta *meta, char *file, int argc)
{
	if (argc != 2)
		return (ft_putstr_fd("Incorrect Argument Count\n", 2), false);
	if (!check_extension(file, ".cub"))
		return (ft_putstr_fd("Invalid File Type\n", 2), false);
	ft_memset(meta, 0, sizeof(t_meta));
	meta->parse.fd = open(file, O_RDONLY);
	if (meta->parse.fd < 0)
		return (ft_putstr_fd("Invalid File\n", 2), false);
	if (!set_bounds(meta, file))
		return (free_texture(meta), false);
	meta->map.pixel = malloc((meta->map.y_max) * sizeof(t_pixel *));
	if (!meta->map.pixel)
		return (ft_putstr_fd("Malloc Error\n", 2), false);
	return (true);
}

void	set_map(t_meta *meta, char *str)
{
	int	x;

	x = 0;
	meta->map.pixel[meta->parse.y]
		= malloc(meta->map.x_max * (sizeof(t_pixel)));
	while (x < meta->map.x_max)
	{
		if (x >= (int)ft_strlen(str) || ft_isspace(str[x]))
			meta->map.pixel[meta->parse.y][x].value = -1;
		else if (ft_isdigit(str[x]))
			meta->map.pixel[meta->parse.y][x].value = str[x] - '0';
		else
			meta->map.pixel[meta->parse.y][x].value = str[x];
		meta->map.pixel[meta->parse.y][x].x = x;
		meta->map.pixel[meta->parse.y][x].y = meta->parse.y;
		x++;
	}
	meta->parse.y++;
}

bool	parse_map(int argc, char **argv, t_meta *meta)
{
	char	*str;

	if (!init_parse(meta, argv[1], argc))
		return (false);
	while (1)
	{
		str = get_next_line(meta->parse.fd);
		if (!str)
			break ;
		if (meta->parse.count >= meta->parse.map_start
			&& meta->parse.y < meta->map.y_max && is_map(str))
			set_map(meta, str);
		free(str);
		meta->parse.count++;
	}
	close(meta->parse.fd);
	if (!parse_error(meta))
		return (free_texture(meta),
			memfree_array((void **)meta->map.pixel), false);
	return (true);
}
