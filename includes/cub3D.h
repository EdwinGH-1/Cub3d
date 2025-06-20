/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:49:42 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/20 20:03:44 by jthiew           ###   ########.fr       */
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
# include "libft.h"
# include "mlx.h"
// # include "../minilibx-linux/mlx.h"
// # include "../libft/includes/libft.h"

//-----------------------------CUB3D MACROS------------------------------------

# define WIN_LEN 1920
# define WIN_HEI 1080
// # define WIN_LEN 3820
// # define WIN_HEI 2160
# define WIN_NAME "GAME OF THE YEAR"
# define BORDER_SIZE 1
# define PLAYER_SPD 0.1f
# define LINE_STEP_SIZE 0.01f
# define FOV_ANG 60

//-----------------------------CUB3D STRUCTURES--------------------------------

typedef struct s_point
{
	int	x;
	int	y;
	int	value;
}	t_point;

typedef struct s_tex_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bbp;
	int		line_size;
	int		endian;
}	t_tex_img;

typedef struct s_texture
{
	t_tex_img		no_tex;
	t_tex_img		so_tex;
	t_tex_img		we_tex;
	t_tex_img		ea_tex;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	unsigned int	floor;
	unsigned int	ceiling;
}	t_texture;

typedef struct s_map
{
	t_point		**point;
	t_texture	texture;
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
}	t_vars;

//-----------------------------CUB3D FUNCTIONS---------------------------------

//		PARSE
//	parse.c
bool	parse_file(char **argv, t_vars *vars);

//	parse_utils.c
bool	set_bounds(t_map *map, char *file);
bool	is_map(char *str);
void	memfree_array(void **array);
void	free_texture(t_map *map);
void	free_part(t_map *map, int y);

//	parse_texture.c
bool	check_extension(char *file, char *extension);
int		set_textures(char *str, t_map *map);

void	get_map(t_vars *vars);

// draw.c
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_player(t_vars *vars, t_player player);
void	draw_map(t_vars *vars);
void	draw_fov(t_vars *vars, t_ray ray);

// free.c
void	delete_and_free_vars(t_vars *vars);

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

#endif // !CUB3D_H
