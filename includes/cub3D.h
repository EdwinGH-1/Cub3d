/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:49:42 by jthiew            #+#    #+#             */
/*   Updated: 2025/07/07 15:34:14 by jothomas         ###   ########.fr       */
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
# include <sys/time.h>
# include <stdbool.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"

//-----------------------------CUB3D MACROS------------------------------------

# define WINX 1920
# define WINY 1080
# define PIE 3.14159

# define MINI_RAD 200
# define MINI_BORDER 0x808080
# define MINI_POS 50
# define MINI_SIZE 30

# define P_COLOR 0xFF0000
# define P_SIZE 8
# define P_FOV 66
# define P_SPEED 70
# define P_TORQUE 70
# define P_PRECISION 0.01

# define RAY_N 120
# define RAY_COLOR 0x800080
# define TILE_SIZE 30

# define NO 0
# define SO 1
# define EA 2
# define WE 3
# define DO 4
# define F 5
# define C 6
# define GU 7
//-----------------------------CUB3D STRUCTURES--------------------------------

//---------PARSING STRUCT
typedef struct s_utils
{
	int		fd;
	int		map_start;
	int		y;
	int		count;
	int		is_map;
	bool	textures[7];
}	t_utils;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	value;
}	t_pixel;

typedef struct s_texture
{
	char			*path;
	void			*img;
	char			*addr;
	int				height;
	int				width;
	int				bpp;
	int				line_length;
	int				endian;
}	t_texture;

typedef struct s_map
{
	t_pixel			**pixel;
	t_texture		texture[6];
	t_texture		sprite;
	unsigned int	floor;
	unsigned int	ceiling;
	int				x_max;
	int				y_max;
	double			x_tex;
	double			y_tex;
	double			x_offset;
	double			y_offset;
}	t_map;

//---------PLAYER STRUCT
typedef struct s_state
{
	bool	key_w;
	bool	key_a;
	bool	key_s;
	bool	key_d;
	bool	key_r;
	bool	key_l;
	bool	key_door;
}	t_state;

// World position
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	base_angle;
}	t_player;

//---------RAYCASTING STRUCT
typedef struct s_ray
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	perp_dist;
	double	line_h;
	double	dist_x;
	double	dist_y;
	double	delta_x;
	double	delta_y;
	int		grid_x;
	int		grid_y;
	int		step_x;
	int		step_y;
	int		side;
}	t_ray;

typedef struct s_time
{
	double	delta_time;
	double	last_frame;
	double	current_frame;
	double	fps;
}	t_time;

//---------META DATA STRUCT
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
	t_utils		parse;
	t_bitmap	bitmap;
	t_map		map;
	t_player	player;
	t_state		state;
	t_ray		ray;
	t_time		time;
}	t_meta;

//-----------------------------CUB3D FUNCTIONS---------------------------------

//		PARSE
//	parse.c
bool			parse_map(int argc, char **argv, t_meta *meta);

//	parse_utils.c
bool			set_bounds(t_meta *meta, char *file);
bool			is_map(char *str);
void			memfree_array(void **array);
void			free_texture(t_meta *meta);

//	parse_texture.c
bool			check_extension(char *file, char *extension);
int				set_textures(t_meta *meta, char *str);

//	parse_error.c
bool			parse_error(t_meta *meta);

//		HOOK
//	hook.c
int				render_image(t_meta *meta);
int				terminate(t_meta *meta);
bool			collision_check(t_meta *meta);

//	hook_key.c
int				key_press(int keysym, t_meta *meta);
int				key_release(int keysym, t_meta *meta);
void			movement_state(t_meta *meta);
int				mouse_move(int mx, int my, t_meta *meta);

//		DRAW
//	draw_map.c
bool			in_circle(int x, int y, int r);
void			render_minimap(t_meta *meta);

//	draw_line.c
void			draw_line(t_meta *meta);
void			my_mlx_pixel_put(t_meta *meta, int x, int y,
					unsigned int color);
unsigned int	get_pixel(t_meta *meta, int x, int y);

//	draw_gun.c
void			animation(t_meta *meta);

//		RAYCAST
//	raycast.c
void			dda_logic(t_meta *meta, int state);

//	draw_ray.c
void			draw_map_ray(t_meta *meta);
void			raycast(t_meta *meta);

//	ray_utils.c
int				texture_index(t_meta *meta);
unsigned int	texture_color(t_meta *meta, t_texture tex, double *step);
void			texture_coord(t_meta *meta, t_texture *texture);
void			texture_bounds(t_meta *meta, double *start, double *end);

#endif // !CUB3D_H
