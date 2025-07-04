/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:43:24 by jothomas          #+#    #+#             */
/*   Updated: 2025/07/04 11:03:21 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_view(t_meta *meta, int x, int y)
{
	int	value;

	value = meta->map.pixel[y][x].value;
	if (value == 'N')
		meta->player.base_angle = 3 * PIE / 2;
	else if (value == 'S')
		meta->player.base_angle = PIE / 2;
	else if (value == 'E')
		meta->player.base_angle = 0;
	else if (value == 'W')
		meta->player.base_angle = PIE;
	meta->map.x_offset -= x * MINI_SIZE
		- MINI_RAD - MINI_POS + (MINI_SIZE / 2);
	meta->map.y_offset -= y * MINI_SIZE
		- MINI_RAD - MINI_POS + (MINI_SIZE / 2);
}

bool	init_start(t_meta *meta)
{
	int	start;
	int	x;
	int	y;

	y = -1;
	start = 0;
	while (++y < meta->map.y_max)
	{
		x = -1;
		while (++x < meta->map.x_max)
		{
			if (meta->map.pixel[y][x].value == 'N'
				|| meta->map.pixel[y][x].value == 'S'
				|| meta->map.pixel[y][x].value == 'E'
				|| meta->map.pixel[y][x].value == 'W')
			{
				start++;
				init_view(meta, x, y);
			}
		}
	}
	if (start != 1)
		return (false);
	return (true);
}

bool	check_row(t_meta *meta, t_pixel *pixel)
{
	int	x1;
	int	x2;

	x1 = 0;
	x2 = meta->map.x_max - 1;
	while (pixel[x1].value == -1)
		x1++;
	while (pixel[x2].value == -1)
		x2--;
	if (pixel[x1].value != 1 || pixel[x2].value != 1)
		return (false);
	if (pixel[x1].y == 0 || pixel[x1].y == meta->map.y_max - 1)
	{
		while (++x1 < x2)
			if (!pixel[x1].value)
				return (false);
	}
	return (true);
}

bool	check_col(t_meta *meta, int x)
{
	int	y1;
	int	y2;

	y1 = 0;
	y2 = meta->map.y_max - 1;
	while (meta->map.pixel[y1][x].value == -1)
		y1++;
	while (meta->map.pixel[y2][x].value == -1)
		y2--;
	if (meta->map.pixel[y1][x].value != 1 || meta->map.pixel[y1][x].value != 1)
		return (false);
	if (x == 0 || x == meta->map.x_max - 1)
	{
		while (++y1 < y2)
			if (!meta->map.pixel[y1][x].value)
				return (false);
	}
	return (true);
}

bool	parse_error(t_meta *meta)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (++y < meta->map.y_max)
		if (!check_row(meta, meta->map.pixel[y]))
			return (ft_putstr_fd("Invalid Map Format\n", 2), false);
	while (++x < meta->map.x_max)
		if (!check_col(meta, x))
			return (ft_putstr_fd("Invalid Map Format\n", 2), false);
	if (!init_start(meta))
		return (ft_putstr_fd("Invalid Starting Position\n", 2), false);
	return (true);
}
