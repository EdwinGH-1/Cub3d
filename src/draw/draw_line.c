/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:32:29 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/20 16:32:25 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

unsigned int	get_pixel(t_meta *meta, int x, int y)
{
	char	*dst;

	if (y > WINY || y < 0 || x > WINX || x < 0)
		return (0);
	dst = meta->bitmap.addr
		+ ((x * meta->bitmap.bpp / 8)
			+ (y * meta->bitmap.line_length));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_meta *meta, int x, int y, unsigned int color)
{
	char	*dst;

	if (y > WINY || y < 0 || x > WINX || x < 0)
		return ;
	dst = meta->bitmap.addr
		+ ((x * meta->bitmap.bpp / 8)
			+ (y * meta->bitmap.line_length));
	*(unsigned int *)dst = color;
}

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
