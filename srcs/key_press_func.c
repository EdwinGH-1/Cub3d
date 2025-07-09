/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:13:23 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/27 20:38:57 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_win(t_vars *vars)
{
	delete_and_free_vars(vars);
	exit (0);
}

bool	can_close(t_vars *vars, int x, int y)
{
	float		left;
	float		right;
	float		top;
	float		bottom;

	left = x - vars->player.hit_box;
	right = x + vars->player.hit_box + 1;
	top = y - vars->player.hit_box;
	bottom = y + vars->player.hit_box + 1;
	if ((vars->player.x >= left && vars->player.x <= right)
		&& (vars->player.y >= top && vars->player.y <= bottom))
		return (false);
	return (true);
}

void	set_anim(t_anim *anim, t_sprite *sprite, int anim_type)
{
	bool	*hand_playing;

	if (sprite->is_hand == LEFT_HAND)
		hand_playing = &anim->lhand_playing;
	else
		hand_playing = &anim->rhand_playing;
	if (*hand_playing == false && sprite->is_playing == false)
	{
		*hand_playing = true;
		sprite->is_playing = true;
		sprite->frame = 0;
		if (anim_type == ANIM_TOGGLE_DOOR)
			sprite->frame_duration = DUR_TOGGLE_DOOR;
		else if (anim_type == ANIM_THUMBS_UP)
			sprite->frame_duration = DUR_THUMBS_UP;
		else if (anim_type == ANIM_EAST_EGG)
			sprite->frame_duration = DUR_EAST_EGG;
		sprite->accum_time = 0.0;
	}
}

bool	is_diagonally_blocked(t_map *map, t_player *player, int dx, int dy)
{
	int	side_1;
	int	side_2;

	if (abs(dx) == 1 && abs(dy) == 1)
	{
		side_1 = map->point[(int)player->y][(int)player->x + dx].value;
		side_2 = map->point[(int)player->y + dy][(int)player->x].value;
		if ((side_1 == 1 || side_1 == 'D') && (side_2 == 1 || side_2 == 'D'))
			return (true);
	}
	return (false);
}

void	toggle_door(t_vars *vars, t_anim *anim, t_sprite *sprite)
{
	int	x;
	int	y;
	int	dx;
	int	dy;

	if (anim->lhand_playing == false && sprite->is_playing == false)
	{
		set_anim(anim, sprite, ANIM_TOGGLE_DOOR);
		x = vars->player.dir_x * 0.75 + vars->player.x;
		y = vars->player.dir_y * 0.75 + vars->player.y;
		dx = (int)x - (int)vars->player.x;
		dy = (int)y - (int)vars->player.y;
		if (is_diagonally_blocked(&vars->map, &vars->player, dx, dy) == true)
			return ;
		if (vars->map.point[y][x].value == 'D')
			vars->map.point[y][x].value = 'O';
		else if (vars->map.point[y][x].value == 'O')
			if (can_close(vars, x, y) == true)
				vars->map.point[y][x].value = 'D';
	}
}
