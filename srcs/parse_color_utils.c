/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:34:17 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/24 20:01:54 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_valid_color_str(char *str)
{
	int	comma_count;

	comma_count = 0;
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == 0 && ft_isspace(*str) == 0 && *str != ',')
		{
			ft_putstr_fd("Error\nInvalid color\n", 2);
			return (false);
		}
		if (*str == ',')
			comma_count++;
		str++;
	}
	if (comma_count != 2)
	{
		ft_putstr_fd("Error\nInvalid color\n", 2);
		return (false);
	}
	return (true);
}

bool	is_valid_color(char *str, bool is_set, int *is_err)
{
	if (is_set == true)
	{
		ft_putstr_fd("Error\nColor assigned\n", 2);
		*is_err = 1;
		return (false);
	}
	while (ft_isspace(*str) == 1)
		str++;
	if (is_valid_color_str(str) == false)
	{
		*is_err = 1;
		return (false);
	}
	return (true);
}

bool	is_valid_color_range(t_surface *surface, int *is_err)
{
	if (surface->r < 0 || surface->r > 255
		|| surface->g < 0 || surface->g > 255
		|| surface->b < 0 || surface->b > 255)
	{
		ft_putstr_fd("Error\nInvalid color value\n", 2);
		*is_err = 1;
		return (false);
	}
	return (true);
}
