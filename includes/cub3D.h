/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:49:42 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/12 14:37:35 by jthiew           ###   ########.fr       */
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
# include "libft.h"

# define WIN_LEN 1920
# define WIN_HEI 1080
# define WIN_NAME "GAME OF THE YEAR"

typedef struct s_map
{
	int	x_coor;
	int	y_coor;
	int	value;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bbp;
	int		line_size;
	int		endian;
}	t_img;

typedef struct t_vars
{
	char			*tex_no;
	char			*tex_so;
	char			*tex_we;
	char			*tex_ea;
	unsigned int	col_floor;
	unsigned int	col_ceil;
	t_map			**map;
	void			*mlx;
	void			*win;
	t_img			img;
}	t_vars;

#endif // !CUB3D_H
