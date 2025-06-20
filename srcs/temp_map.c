
#include "cub3D.h"

# define MAP_HEI 10
# define MAP_WID 20

void	get_map(t_vars *vars)
{
	static int	raw_map[MAP_HEI][MAP_WID] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 'D', 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 0, 0, 'N', 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	int	x;
	int	y;

	vars->map.x_max = MAP_WID;
	vars->map.y_max = MAP_HEI;
	vars->map.point = malloc(MAP_HEI * sizeof(t_point *));
	if (vars->map.point == NULL)
		delete_and_free_vars(vars);
	ft_memset(vars->map.point, 0, MAP_HEI * sizeof(t_point *));
	y = 0;
	while (y < MAP_HEI)
	{
		vars->map.point[y] = malloc(MAP_WID * sizeof(t_point)); 
		if (vars->map.point[y] == NULL)
			delete_and_free_vars(vars);
		ft_memset(vars->map.point[y], 0, MAP_WID * sizeof(t_point));
		x = 0;
		while (x < MAP_WID)
		{
			vars->map.point[y][x].x = x;
			vars->map.point[y][x].y = y;
			vars->map.point[y][x].value = raw_map[y][x];
			x++;
		}
		y++;
	}
}
