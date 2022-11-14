#include "cub3d.h"

void	create_win(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx,1000, 1000, "CUB3D");
	vars->two_D.img_ptr = mlx_new_image(vars->mlx,1000, 1000);
	vars->two_D.address = mlx_get_data_addr(vars->two_D.img_ptr,
			&vars->two_D.bits_per_pixel,
			&vars->two_D.line_size, &vars->two_D.endian);
}


// -7 up +7 down, 
void create_player(t_vars *vars, int player_x, int player_y)
{

	int x = player_x;
	int y = player_y;
	printf("player x %d y %d\n",player_x,player_y);
	
	while (player_x > x - 3)
	{
		y = player_y;
		while (y - 3 < player_y)
		{
			my_mlx_pixel_put(&vars->two_D, x, y, 0X000000);
			y++;
		}
		x++;
	}
    
	int a = 0;
	for (double i = -0.3; i < 0.3; i+=0.0008)
	{
		vars->player.ray[a] = draw_ray(vars, vars->player.pa + i, 0XFF0000);
		a++;
		// printf("---------------------\n");

	}
	// printf("a %d var %d\n",a,vars->player.ray[a -1]);
	// vars->player.ray[a] = -1;
	// draw_ray(vars, vars->player.pa, 0XFF0000);
	draw3Dstart(vars);
	draw_angle(vars, vars->player.pa , 8, 0X000000);

}





//walls color 0X4C1130
//space  0XFFFFFF
void create_elemntry(t_vars *vars, int wall_x, int wall_y, int color)
{
	int x = wall_x * 50;
	int y = wall_y * 50;
	

	while (x < (wall_x * 50) + 49)
	{
		y = wall_y * 50;
		while (y < (wall_y * 50) + 49 )
		{
			my_mlx_pixel_put(&vars->two_D, x, y, color);
			y++;
		}
		x++;
	}
}
