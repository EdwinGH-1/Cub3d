/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:52:09 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/27 18:21:44 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_player(t_vars *vars, t_minimap *minimap, t_player *player)
{
	t_mmap_player	m_ply;
	int				i;
	int				j;
	float			k;

	j = -1;
	k = 0;
	while (++j < player->size)
	{
		i = -1;
		while (++i < player->size)
		{
			if (i >= player->size / 2.0 - k && i <= player->size / 2.0 + k)
			{
				m_ply.x = -j + player->size / 2.0;
				m_ply.y = i - player->size / 2.0;
				m_ply.rot_x = m_ply.x * player->dir_x - m_ply.y * player->dir_y;
				m_ply.rot_y = m_ply.x * player->dir_y + m_ply.y * player->dir_x;
				m_ply.x = minimap->center_x + m_ply.rot_x;
				m_ply.y = minimap->center_y + m_ply.rot_y;
				my_mlx_pixel_put(&vars->img, m_ply.x, m_ply.y, PLAYER_COLOR);
			}
		}
		k += 0.75;
	}
}
