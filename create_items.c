#include "cub3d.h"

void	create_win(t_parsing_result *data)
{
	data->mlx = mlx_init((const uint32_t)screenWidth, (const uint32_t)screenHeight, "Cub3d", false);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->img = mlx_new_image(data->mlx, screenWidth, screenHeight);
}


// -7 up +7 down, 
void create_player(t_parsing_result *data, int player_x, int player_y)
{

	int x = player_x * 50;
	int y = player_y * 50;
	printf("player x %d y %d\n",player_x,player_y);
	
	while (player_x > x - 3)
	{
		y = player_y;
		while (y - 3 < player_y)
		{
			mlx_put_pixel(data->img, x, y, 0X000000);
			y++;
		}
		x++;
	}
	draw_angle(data, data->player.pa , 8, 0X000000);
    
	// int a = 0;
	// for (double i = -0.3; i < 0.3; i+=0.0008)
	// {
		// data->player.ray = draw_ray(data, data->player.pa + i, 0XFF0000);
		data->player.ray = draw_ray(data, data->player.pa, 0XFF0000);
		// walls(data,a);
		// double ca = fabs(i);
		// data->player.ray[a] = data->player.ray[a] * cos(ca);
	// 	a++;
	// 	// printf("---------------------\n");

	// }

    // mlx_put_image_to_window(data->mlx, data->win,
    //                         data->img.img, 0, 0);
	// draw3Dstart(data);
	
}





//walls color 0X4C1130
//space  0XFFFFFF
void create_elemntry(t_parsing_result *data, int wall_x, int wall_y, int color)
{
	int x = wall_x * 50;
	int y = wall_y * 50;
	

	while (x < (wall_x * 50) + 49)
	{
		y = wall_y * 50;
		while (y < (wall_y * 50) + 49 )
		{
			mlx_put_pixel(data->img, x, y, color);
			y++;
		}
		x++;
	}
}
