/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:32:29 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/20 14:33:03 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	gradient_less_than_one(t_meta *meta, t_pixel mask, int dx, int dy)
{
	int	p;
	int	i;

	i = -1;
	p = 2 * abs(dy) - abs(dx);
	while (++i < abs(dx))
	{
		my_mlx_pixel_put(meta, mask.x, mask.y, meta->player.target.value);
		if (dx > 0)
			mask.x--;
		else if (dx < 0)
			mask.x++;
		if (p < 0)
			p = p + 2 * abs(dy);
		else
		{
			if (dy > 0)
				mask.y--;
			else if (dy < 0)
				mask.y++;
			p = p + 2 * abs(dy) - 2 * abs(dx);
		}
	}
}

static void	gradient_more_than_one(t_meta *meta, t_pixel mask, int dx, int dy)
{
	int	p;
	int	i;

	i = -1;
	p = 2 * abs(dx) - abs(dy);
	while (++i < abs(dy))
	{
		my_mlx_pixel_put(meta, mask.x, mask.y, meta->player.target.value);
		if (dy > 0)
			mask.y--;
		else if (dy < 0)
			mask.y++;
		if (p < 0)
			p = p + 2 * abs(dx);
		else
		{
			if (dx > 0)
				mask.x--;
			else if (dx < 0)
				mask.x++;
			p = p + 2 * abs(dx) - 2 * abs(dy);
		}
	}
}

void	draw_line(t_meta *meta)
{
	t_pixel	mask;
	int		dx;
	int		dy;

	dx = meta->player.target.x - meta->player.pos.x;
	dy = meta->player.target.y - meta->player.pos.y;
	mask = meta->player.pos;
	if (abs(dx) > abs(dy))
		gradient_less_than_one(meta, mask, dx, dy);
	else
		gradient_more_than_one(meta, mask, dx, dy);
}
