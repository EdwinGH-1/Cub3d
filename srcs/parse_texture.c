/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:03:54 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/25 07:11:37 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_texture_path(char *str, t_tex_img *tex_img, int *is_err)
{
	if (is_valid_texture(str, tex_img, is_err) == false)
		return ;
	while (ft_isspace(*str) == 1)
		str++;
	tex_img->path = ft_strndup(str, ft_strlen(str) - 1);
	if (tex_img->path == NULL)
	{
		ft_putstr_fd("Error strdup\n", 2);
		*is_err = 1;
	}
}

void	set_texture(char *str, t_texture *tex, int *is_err)
{
	while (ft_isspace(*str) == 1)
		str++;
	if (ft_strncmp(str, "NO", 2) == 0 && ft_isspace(*(str + 2)) == 1)
		get_texture_path(str + 2, &tex->no_tex, is_err);
	else if (ft_strncmp(str, "SO", 2) == 0 && ft_isspace(*(str + 2)) == 1)
		get_texture_path(str + 2, &tex->so_tex, is_err);
	else if (ft_strncmp(str, "WE", 2) == 0 && ft_isspace(*(str + 2)) == 1)
		get_texture_path(str + 2, &tex->we_tex, is_err);
	else if (ft_strncmp(str, "EA", 2) == 0 && ft_isspace(*(str + 2)) == 1)
		get_texture_path(str + 2, &tex->ea_tex, is_err);
	else if (ft_strncmp(str, "DO", 2) == 0 && ft_isspace(*(str + 2)) == 1)
		get_texture_path(str + 2, &tex->door_tex, is_err);
}

bool	is_texture(char *str)
{
	while (ft_isspace(*str) == 1)
		str++;
	if (ft_strncmp(str, "NO", 2) == 0
		|| ft_strncmp(str, "SO", 2) == 0
		|| ft_strncmp(str, "WE", 2) == 0
		|| ft_strncmp(str, "EA", 2) == 0
		|| ft_strncmp(str, "DO", 2) == 0)
		return (true);
	return (false);
}

void	get_texture_data(t_vars *vars, int fd, int *is_err)
{
	char	*str;

	str = get_next_line(fd);
	while (str != NULL)
	{
		if (is_texture(str) == true)
		{
			set_texture(str, &vars->texture, is_err);
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
