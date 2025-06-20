/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:18:53 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/18 13:18:55 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_ray_data(t_vars *vars, t_ray *ray)
{
	ray->start_ang = vars->player.dir - ((FOV_ANG / 2.0) * M_PI / 180.0f);
	ray->end_ang = vars->player.dir + ((FOV_ANG / 2.0) * M_PI / 180.0f);
}
