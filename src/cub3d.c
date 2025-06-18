/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:46:24 by jothomas          #+#    #+#             */
/*   Updated: 2025/06/18 19:23:05 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (!parse_map(argc, argv, &vars))
		exit (1);
}

// size_t	x;
// size_t	y;
// y = 0;
// while (y < vars.map.y_max)
// {
// 	x = 0;
// 	while (x < vars.map.x_max)
// 	{
// 		printf("%i", vars.map.pixel[y][x].value);
// 		x++;
// 	}
// 	printf("\n");
// 	y++;
// }