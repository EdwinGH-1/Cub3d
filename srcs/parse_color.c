/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:51:34 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/24 20:59:46 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_color_value(char *str, t_surface *surface, int *is_err)
{
	char	**split;

	if (is_valid_color(str, surface->is_set, is_err) == false)
		return ;
	split = ft_split(str, ',');
	if (split == NULL)
	{
		ft_putstr_fd("Error splitting str\n", 2);
		*is_err = 1;
		return ;
	}
	surface->r = ft_atoi(split[0]);
	surface->g = ft_atoi(split[1]);
	surface->b = ft_atoi(split[2]);
	ft_free_split(split);
	if (is_valid_color_range(surface, is_err) == false)
		return ;
	surface->color = ((surface->r & 0xff) << 16) | ((surface->g & 0xff) << 8)
		| (surface->b & 0xff);
	surface->is_set = true;
}

void	set_color(char *str, t_texture *tex, int *is_err)
{
	while (ft_isspace(*str) == 1)
		str++;
	if (ft_strncmp(str, "C", 1) == 0 && ft_isspace(*(str + 1)) == 1)
		get_color_value(str + 1, &tex->ceiling, is_err);
	else if (ft_strncmp(str, "F", 1) == 0 && ft_isspace(*(str + 1)) == 1)
		get_color_value(str + 1, &tex->floor, is_err);
}

bool	is_color(char *str)
{
	while (ft_isspace(*str) == 1)
		str++;
	if (ft_strncmp(str, "C", 1) == 0 || ft_strncmp(str, "F", 1) == 0)
		return (true);
	return (false);
}

void	get_color_data(t_vars *vars, int fd, int *is_err)
{
	char	*str;

	str = get_next_line(fd);
	while (str != NULL)
	{
		if (is_color(str) == true)
		{
			set_color(str, &vars->texture, is_err);
			if (*is_err == 1)
			{
				while (str != NULL)
				{
					free(str);
					str = get_next_line(fd);
				}
				delete_and_free_vars(vars);
				exit(1);
			}
		}
		free(str);
		str = get_next_line(fd);
	}
}
