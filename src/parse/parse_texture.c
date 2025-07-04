/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:33:00 by jothomas          #+#    #+#             */
/*   Updated: 2025/07/04 16:47:51 by jothomas         ###   ########.fr       */
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

bool	grab_color(char *str, unsigned int *color, bool *index)
{
	char	**colors;
	int		r;
	int		g;
	int		b;

	if (*index)
		return (ft_putstr_fd("Invalid Color Format", 2), false);
	str++;
	while (*str && ft_isspace(*str))
		str++;
	colors = ft_split(str, ',');
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	*color = ((r & 0xff) << 16) | ((g & 0xff) << 8) | (b & 0xff);
	memfree_array((void **)colors);
	*index = true;
	return (true);
}

bool	grab_texture(char *str, char **texture, bool *index)
{
	int	i;
	int	n;
	int	fd;

	i = 1;
	if (*index)
		return (ft_putstr_fd("Invalid Texture Format", 2), false);
	while (ft_isspace(str[++i]))
		;
	n = i;
	while (str[n] && str[n] != '\n')
		n++;
	*texture = ft_substr(str, i, n - i);
	*index = true;
	if (!check_extension(*texture, ".xpm"))
		return (ft_putstr_fd("Invalid Texture Type\n", 2), false);
	fd = open(*texture, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Invalid Texture Path\n", 2), close(fd), false);
	close(fd);
	return (true);
}

int	set_textures(t_meta *meta, char *str)
{
	int	i;

	if ((!ft_strncmp(str, "NO ", 3) && !grab_texture(str,
				&(meta->map.texture[NO].path), &(meta->parse.textures[NO])))
		|| (!ft_strncmp(str, "SO ", 3) && !grab_texture(str,
				&(meta->map.texture[SO].path), &(meta->parse.textures[SO])))
		|| (!ft_strncmp(str, "EA ", 3) && !grab_texture(str,
				&(meta->map.texture[EA].path), &(meta->parse.textures[EA])))
		|| (!ft_strncmp(str, "WE ", 3) && !grab_texture(str,
				&(meta->map.texture[WE].path), &(meta->parse.textures[WE])))
		|| (!ft_strncmp(str, "DO ", 3) && !grab_texture(str,
				&(meta->map.texture[DO].path), &(meta->parse.textures[DO])))
		|| (!ft_strncmp(str, "F ", 2) && !grab_color(str,
				&(meta->map.floor), &(meta->parse.textures[F])))
		|| (!ft_strncmp(str, "C ", 2) && !grab_color(str,
				&(meta->map.ceiling), &(meta->parse.textures[C]))))
		return (-1);
	i = -1;
	while (++i <= C)
		if (!meta->parse.textures[i] && i != DO)
			return (0);
	return (1);
}
