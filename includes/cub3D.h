/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:49:42 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/26 12:34:23 by jthiew           ###   ########.fr       */
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
# include <sys/time.h>
# include "libft.h"
# include "mlx.h"

//-----------------------------CUB3D MACROS------------------------------------

# define WIN_LEN 1920
# define WIN_HEI 1080
// # define WIN_LEN 3820
// # define WIN_HEI 2160
# define WIN_NAME "GAME OF THE YEAR"
# define MINIMAP_BORDER_COL 0x909090
# define BORDER_SIZE 1
# define PLAYER_SPD 0.05f
# define LINE_STEP_SIZE 0.01f
# define FOV_ANG 60
# define MOUSE_SENSITIVITY 0.0005f

//-----------------------------CUB3D STRUCTURES--------------------------------

typedef struct s_point
{
	int	x;
	int	y;
	int	value;
}	t_point;

typedef struct s_tex_img
{
	char	*path;
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bbp;
	int		line_size;
	int		endian;
}	t_tex_img;

typedef struct s_surface
{
	int				r;
	int				g;
	int				b;
	unsigned int	color;
	bool			is_set;
}	t_surface;

typedef struct s_texture
{
	t_tex_img	no_tex;
	t_tex_img	so_tex;
	t_tex_img	we_tex;
	t_tex_img	ea_tex;
	t_tex_img	door_tex;
	t_surface	floor;
	t_surface	ceiling;
}	t_texture;

typedef struct s_map
{
	t_point		**point;
	int			x_max;
	int			y_max;
}	t_map;

typedef struct s_player
{
	t_point	pos;
	float	x;
	float	y;
	float	speed;
	int		size;
	float	dir;
	float	dir_x;
	float	dir_y;
	float	hit_box;
}	t_player;

typedef struct s_ray
{
	float	start_ang;
	float	end_ang;
	float	x;
	float	y;
	float	dir_x;
	float	dir_y;
	int		map_x;
	int		map_y;
	float	side_dist_x;
	float	side_dist_y;
	float	delta_dist_x;
	float	delta_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	float	perp_wall_dist;
}	t_ray;

typedef struct s_key_state
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	l_arr;
	bool	r_arr;
}	t_key_state;

typedef struct s_minimap
{
	int	size;
	int	center_x;
	int	center_y;
	int	top;
	int	bottom;
	int	left;
	int	right;
	int	edge_offset;
	int	right_align;
	int	cell_size;
	int	border;
}	t_minimap;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bbp;
	int		line_size;
	int		endian;
}	t_img;

typedef struct s_fps
{
	struct timeval	last_frame_time;
	float			fps_count;
}	t_fps;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_map			map;
	t_player		player;
	t_ray			ray;
	t_key_state		key_state;
	t_minimap		minimap;
	t_texture		texture;
	t_fps			fps;
}	t_vars;

// ----------------------------CUB3D FUNCTIONS---------------------------------

// --------------PARSING---------------
// parse.c
void	parse_file(char **argv, t_vars *vars);

// parse_utils.c
bool	is_valid_extension(char *filename, char *extension);
bool	is_valid_file(char *file);
bool	is_texture_filled(t_texture tex);

// parse_color.c
void	get_color_data(t_vars *vars, int fd, int *is_err);

// parse_color_utils.c
bool	is_valid_color(char *str, bool is_set, int *is_err);
bool	is_valid_color_range(t_surface *surface, int *is_err);

// parse_map.c
void	parse_map_values(t_vars *vars, t_map *map, char *file);
void	parse_map_size(t_vars *vars, t_map *map, char *file);

// parse_map_utils.c
bool	is_valid_map_row(t_map *map);
bool	is_valid_map_col(t_map *map);
bool	is_valid_player(t_map *map);
bool	is_map(char *str);
void	init_map_points(t_vars *vars, t_map *map);

// parse_texture.c
void	get_texture_data(t_vars *vars, int fd, int *is_err);

// parse_texture_utils.c
char	*ft_strndup(char *str, int len);
bool	is_valid_texture(char *str, t_tex_img *tex_img, int *is_err);
// ------------END PARSING-------------

// draw.c
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_player(t_vars *vars, t_player player);
void	draw_map(t_vars *vars);
void	draw_fov(t_vars *vars, t_ray ray);

// free.c
void	delete_and_free_vars(t_vars *vars);
void	ft_free_split(char **split);

// loop.c
int		game_loop(t_vars *vars);

// hooks.c
void	hook_handler(t_vars *vars);

// init_mlx.c
void	init_mlx_data(t_vars *vars);

// init_player.c
void	init_player_data(t_vars *vars, t_map *map, t_player *player);

// init_ray.c
void	init_ray_data(t_vars *vars, t_ray *ray);

// init_texture.c
void	init_texture_data(t_vars *vars, t_texture *texture);

void	clear_background(t_vars *vars, unsigned int	ceiling_col, unsigned int floor_col);
#endif // !CUB3D_H
