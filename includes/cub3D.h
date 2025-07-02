/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:49:42 by jthiew            #+#    #+#             */
/*   Updated: 2025/07/02 14:29:24 by jthiew           ###   ########.fr       */
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

// MLX WINDOW
# define WIN_LEN 1920
# define WIN_HEI 1080
# define WIN_NAME "HAND SIMULATOR"

// MINIMAP
# define MINIMAP_SIZE 1.0
# define MINIMAP_CELL_SIZE 1.0
# define MINIMAP_GRID_BORDER_SIZE 1
# define MINIMAP_BORDER_COLOR 0x909090
# define MINIMAP_BORDER_SIZE 3
# define DOOR_CLOSE_COLOR 0xffff00
# define DOOR_OPEN_COLOR 0x0000ff
# define WALL_COLOR 0xffffff
# define TILE_COLOR 0x555555
# define PLAYER_COLOR 0x00ff00

// ANIMATION
# define LEFT_HAND 0
# define RIGHT_HAND 1
# define ANIM_TOGGLE_DOOR 10
# define ANIM_THUMBS_UP 11
# define ANIM_EAST_EGG 12
# define DUR_TOGGLE_DOOR 0.05f
# define DUR_THUMBS_UP 0.07f
# define DUR_EAST_EGG 0.07f

// FOV
# define FOV_ANG 66
# define FOV_DRAW_ANG 0.5f
# define FOV_DRAW_DIST 4.5f
# define FOV_COLOR 0xaaaaaa
# define LINE_STEP_SIZE 0.01f

// FPS
# define FPS_PRINT_INTERVAL 0.5f

// RAYCASTING
# define HIT_VERT_WALL 0
# define HIT_HORIZ_WALL 1
# define WALL_HEIGHT 1.0f

// PLAYER
# define PLAYER_MOV_SPD 2.0f
# define PLAYER_ROT_SENS 1.0f
# define MOUSE_SENSITIVITY 0.0005f

//-----------------------------CUB3D STRUCTURES--------------------------------

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bbp;
	int		line_size;
	int		endian;
}	t_img;

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
	int		bbp;
	int		line_size;
	int		endian;
	int		width;
	int		height;
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

typedef struct s_move_vec
{
	float	x;
	float	y;
}	t_move_vec;

typedef struct s_ray
{
	float		start_ang;
	float		end_ang;
	float		camera_x;
	float		dir_x;
	float		dir_y;
	int			map_x;
	int			map_y;
	float		side_dist_x;
	float		side_dist_y;
	float		delta_dist_x;
	float		delta_dist_y;
	int			step_x;
	int			step_y;
	int			side;
	float		perp_wall_dist;
	bool		hit_obstacle;
	t_tex_img	*tex;
	int			col_height;
	int			col_draw_start;
	int			col_draw_end;
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

typedef struct s_fov
{
	float			start_ang;
	float			end_ang;
	float			x;
	float			y;
	unsigned int	color;
}	t_fov;

typedef struct s_mmap_player
{
	float	x;
	float	y;
	float	rot_x;
	float	rot_y;
}	t_mmap_player;

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
	int	grid_border;
}	t_minimap;

typedef struct s_time
{
	struct timeval	last_frame_time;
	struct timeval	last_print_time;
	float			fps_count;
	float			delta_time;
}	t_time;

typedef struct s_sprite_scale
{
	int		dest_x;
	int		dest_y;
	int		src_x;
	int		src_y;
	float	scale_x;
	float	scale_y;
	int		scaled_width;
	int		scaled_height;
	int		x_offset;
	int		y_offset;
}	t_sprite_scale;

typedef struct s_sprite
{
	t_tex_img	*sprite_imgs;
	int			img_count;
	int			frame;
	int			tick;
	bool		is_playing;
	float		accum_time;
	float		frame_duration;
	int			is_hand;
}	t_sprite;

typedef struct s_anim
{
	t_sprite	thumbs_up;
	t_sprite	toggle_door;
	t_sprite	east_egg;
	bool		rhand_playing;
	bool		lhand_playing;
}	t_anim;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		map;
	t_player	player;
	t_ray		ray;
	t_key_state	key_state;
	t_minimap	minimap;
	t_fov		fov;
	t_texture	texture;
	t_anim		animation;
	t_time		time;
}	t_vars;

// ----------------------------CUB3D FUNCTIONS---------------------------------

// parse.c
void	parse_texture(t_vars *vars, char *file);
void	parse_color(t_vars *vars, char *file);
void	parse_map(t_vars *vars, char *file);

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

// free_1.c
void	delete_and_free_vars(t_vars *vars);
void	ft_free_split(char **split);

// free_2.c
void	free_animation(t_vars *vars, t_anim *animation);

// loop.c
int		game_loop(t_vars *vars);

// hooks.c
void	hook_handler(t_vars *vars);

// init_mlx.c
void	init_mlx_data(t_vars *vars);

// init_minimap.c
void	init_minimap_data(t_minimap *minimap);

// init_player.c
void	init_player_data(t_vars *vars, t_map *map, t_player *player);

// init_ray.c
void	init_ray_data(t_vars *vars, t_ray *ray);

// init_texture.c
void	load_texture(t_vars *vars, t_tex_img *tex, char *path);
void	init_texture_data(t_vars *vars, t_texture *texture);

// init_animation_1.c
void	init_animation_data(t_vars *vars, t_anim *animation);

// init_animation_2.c
void	load_thumbs_up_imgs(t_vars *vars, t_tex_img **imgs);
void	load_east_egg_imgs(t_vars *vars, t_tex_img **imgs);
void	load_toggle_door_imgs(t_vars *vars, t_tex_img **imgs);

// key_press_func.c
int		close_win(t_vars *vars);
void	set_anim(t_anim *anim, t_sprite *sprite, int anim_type);
void	toggle_door(t_vars *vars, t_anim *anim, t_sprite *sprite);

// handle_animation.c
void	handle_animations(t_vars *vars, t_anim *animation);

// handle_movement.c
void	handle_movement(t_vars *vars, t_player *player, t_time *time);

// handle_rotation.c
void	handle_rotation(t_vars *vars, t_player *player, t_time *time);

// draw_background.c
void	draw_background(t_vars *vars, t_texture *texture);

// draw_raycasting.c
void	draw_raycasting(t_vars *vars);

// draw_minimap.c
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
bool	is_in_minimap(t_minimap *minimap, int x, int y);
void	draw_minimap(t_vars *vars);

// draw_map.c
void	draw_map(t_vars *vars, t_map *map, t_point ***point);

// draw_player.c
void	draw_player(t_vars *vars, t_minimap *minimap, t_player *player);

// draw_fov.c
void	draw_fov(t_vars *vars, t_minimap *minimap, t_fov *fov);

// draw_raycasting_1.c
void	draw_raycasting(t_vars *vars);

// draw_raycasting_2.c
void	get_column_strip_extent(t_ray *ray);
void	sample_and_draw_strip(t_vars *vars, t_ray *ray, int screen_x);

#endif // !CUB3D_H
