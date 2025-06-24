/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:49:42 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/24 16:32:09 by jothomas         ###   ########.fr       */
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
# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"

//-----------------------------CUB3D MACROS------------------------------------

# define WINX 1920
# define WINY 1080
# define PIE 3.14159

# define MINI_RAD 500
# define MINI_BORDER 0x228B22
# define MINI_POS 100
# define MINI_SIZE 30

# define P_COLOR 0xFF0000
# define P_SIZE 10
# define P_FOV 66
# define P_MOVE 5

# define RAY_N 10
# define RAY_COLOR 0xFF0000

//-----------------------------CUB3D STRUCTURES--------------------------------

typedef struct s_pixel
{
	int	x;
	int	y;
	int	value;
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
	int			x_max;
	int			y_max;
	int			x_offset;
	int			y_offset;
}	t_map;

typedef struct s_state
{
	bool	key_w;
	bool	key_a;
	bool	key_s;
	bool	key_d;
	bool	key_r;
	bool	key_l;
}	t_state;

typedef struct s_pos
{
	double	x;
	double	y;
	double	dist;
	int		grid_x;
	int		grid_y;
}	t_pos;

typedef struct s_player
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	t_pos	pos;
}	t_player;

typedef struct s_bitmap
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_bitmap;

typedef struct s_meta
{
	void		*mlx;
	void		*win;
	t_bitmap	bitmap;
	t_map		map;
	t_player	player;
}	t_meta;

//-----------------------------CUB3D FUNCTIONS---------------------------------

//		PARSE
//	parse.c
bool			parse_map(int argc, char **argv, t_meta *meta);

//	parse_utils.c
bool			set_bounds(t_map *map, char *file);
bool			is_map(char *str);
void			memfree_array(void **array);
void			free_texture(t_map *map);
void			free_part(t_map *map, int y);

//	parse_texture.c
bool			check_extension(char *file, char *extension);
int				set_textures(char *str, t_map *map);

//		HOOK
//	hook.c
int				render_image(void *data);
int				terminate(t_meta *meta);
int				handle_key(int keysym, t_meta *meta);

//		DRAW
//	draw_map.c
void			draw_player(t_meta *meta);
void			draw_ray(t_meta *meta);
void			draw_circle(t_meta *meta);
void			draw_grid(t_meta *meta, t_pixel pixel,
					int count_x, int count_y);
void			render_minimap(t_meta *meta);

//	draw_line.c
void			draw_line(t_meta *meta, t_pos start, t_pos target);
void			my_mlx_pixel_put(t_meta *meta, int x, int y,
					unsigned int color);
unsigned int	get_pixel(t_meta *meta, int x, int y);

//		RAYCAST
//	raycast.c
void			raycast_point(t_meta *meta, t_pos *current);

#endif // !CUB3D_H
