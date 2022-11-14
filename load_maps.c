#include "cub3d.h"

t_vars	*maps_load(t_vars *vars, int where)
{
	int	a;
	int	x;

	x = 0;
	while (vars->map_info.maps[x])
	{
		a = 0;
		while (vars->map_info.maps[x][a])
		{
			if (vars->map_info.maps[x][a] == '0')
				create_elemntry(vars, a, x, 0XFFFFFF);
			else if (vars->map_info.maps[x][a] == '1')
			{
				create_elemntry(vars, a, x, 0X4C1130);
			}
			
			else if (vars->map_info.maps[x][a] == 'P' )
			{
				create_elemntry(vars, a, x, 0XFFFFFF);
				if (where == 0)
				{				
					vars->player.y = x * 50;
					vars->player.x  = a * 50; ;
				
					vars->player.pa = 2 * M_PI;
					vars->player.d_x = cos(vars->player.pa) * 5;
					vars->player.d_y = sin(vars->player.pa) * 5;
					printf("dx %f dy %f\n",vars->player.d_x, vars->player.d_y);
					// printf("x %d y %d ,angel value = %f, y value = %f\n",vars->player.x, vars->player.y ,vars->player.d_x, vars->player.d_y);

				}

			}
			a++;
		}
		x++;
	}
					create_player(vars, (int) vars->player.x, (int) vars->player.y);
				    mlx_put_image_to_window(vars->mlx, vars->win,
		vars->two_D.img_ptr, 0, 0);
					// draw3Dstart(vars);
	return (vars);
}

