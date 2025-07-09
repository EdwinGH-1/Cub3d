/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:11:28 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/26 18:11:41 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_minimap_data(t_minimap *minimap)
{
	minimap->size = WIN_LEN / 7.0 * MINIMAP_SIZE;
	minimap->edge_offset = WIN_LEN / 100;
	minimap->right_align = WIN_LEN - minimap->size - minimap->edge_offset;
	minimap->center_x = minimap->right_align + minimap->size / 2;
	minimap->center_y = minimap->size / 2 + minimap->edge_offset;
	minimap->top = minimap->center_y - minimap->size / 2;
	minimap->bottom = minimap->center_y + minimap->size / 2;
	minimap->left = minimap->center_x - minimap->size / 2;
	minimap->right = minimap->center_x + minimap->size / 2;
	minimap->cell_size = minimap->size / 10.0 * MINIMAP_CELL_SIZE;
	minimap->grid_border = MINIMAP_GRID_BORDER_SIZE;
}
