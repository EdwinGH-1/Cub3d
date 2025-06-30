/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:49:42 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/30 14:57:59 by jothomas         ###   ########.fr       */
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

# define MINI_RAD 200
# define MINI_BORDER 0x808080
# define MINI_POS 50
# define MINI_SIZE 30

# define P_COLOR 0xFF0000
# define P_SIZE 8
# define P_FOV 66
# define P_SPEED 5
# define P_TORQUE 4

# define RAY_N 120
# define RAY_COLOR 0x800080
# define TILE_SIZE 60
//-----------------------------CUB3D STRUCTURES--------------------------------

//---------PARSING STRUCT
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

//---------PLAYER STRUCT
typedef struct s_state
{
	bool	key_w;
	bool	key_a;
	bool	key_s;
	bool	key_d;
	bool	key_r;
	bool	key_l;
}	t_state;

// World position
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

//---------RAYCASTING STRUCT
typedef struct s_ray
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	perp_dist;
	double	dist_x;
	double	dist_y;
	double	delta_x;
	double	delta_y;
	int		grid_x;
	int		grid_y;
	int		step_x;
	int		step_y;
}	t_ray;

// Map position
typedef struct s_mini
{
	double	centre_x;
	double	centre_y;
	double	ray_x;
	double	ray_y;
	double	base_angle;
	double	angle_shift;
}	t_mini;

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
	t_bitmap	bitmap;
	t_map		map;
	t_mini		mini;
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
bool			collision_check(t_meta *meta);

//	hook_key.c
int				key_press(int keysym, t_meta *meta);
int				key_release(int keysym, t_meta *meta);
void			translate(t_meta *meta);

//		DRAW
//	draw_map.c
bool			in_circle(int x, int y);
void			render_minimap(t_meta *meta);

//	draw_ray.c
void			draw_map_ray(t_meta *meta);
void			raycast(t_meta *meta);

//	draw_line.c
void			draw_line(t_meta *meta);
void			my_mlx_pixel_put(t_meta *meta, int x, int y,
					unsigned int color);
unsigned int	get_pixel(t_meta *meta, int x, int y);

//		RAYCAST
//	raycast.c
void			dda_logic(t_meta *meta);

#endif // !CUB3D_H
