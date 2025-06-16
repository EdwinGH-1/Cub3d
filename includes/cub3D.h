/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:49:42 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/16 11:23:50 by jothomas         ###   ########.fr       */
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

#endif // !CUB3D_H
