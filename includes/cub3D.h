/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:49:42 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/18 17:55:28 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <errno.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"

# define WIN_LEN 1920
# define WIN_HEI 1080
# define WIN_NAME "GAME OF THE YEAR"

typedef struct s_pixel
{
	size_t	x;
	size_t	y;
	int		value;
}	t_pixel;

typedef struct s_texture
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	unsigned int	floor;
	unsigned int	ceiling;
}	t_texture;

typedef struct s_map
{
	t_pixel		**pixel;
	t_texture	texture;
	size_t		x_max;
	size_t		y_max;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bbp;
	int		line_size;
	int		endian;
}	t_img;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		map;
}	t_vars;

//		PARSE
//	parse.c
bool	parse_map(int argc, char **argv, t_vars *vars);

//	parse_utils.c
bool	set_bounds(t_map *map, char *file);
bool	is_map(char *str);
void	memfree_array(void **array);
void	free_texture(t_map *map);
void	free_part(t_map *map, int y);

//	parse_texture.c
bool	check_extension(char *file, char *extension);
int		set_textures(char *str, t_map *map);

#endif // !CUB3D_H
