#include "cub3d.h"

void	create_win(t_parsing_result *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx,1000, 1000, "CUB3D");
	data->two_D.img_ptr = mlx_new_image(data->mlx,1000, 1000);
	data->two_D.address = mlx_get_data_addr(data->two_D.img_ptr,
			&data->two_D.bits_per_pixel,
			&data->two_D.line_size, &data->two_D.endian);
}


// -7 up +7 down, 
void create_player(t_parsing_result *data, int player_x, int player_y)
{

	int x = player_x;
	int y = player_y;
	printf("player x %d y %d\n",player_x,player_y);
	
	while (player_x > x - 3)
	{
		y = player_y;
		while (y - 3 < player_y)
		{
			my_mlx_pixel_put(&data->two_D, x, y, 0X000000);
			y++;
		}
		x++;
	}
	draw_angle(data, data->player.pa , 8, 0X000000);
    
	// int a = 0;
	// for (double i = -0.3; i < 0.3; i+=0.0008)
	// {
	// 	data->player.ray[a] = draw_ray(data, data->player.pa + i, 0XFF0000);
	// 	// double ca = fabs(i);
	// 	// data->player.ray[a] = data->player.ray[a] * cos(ca);
	// 	a++;
	// 	// printf("---------------------\n");

	// }

    mlx_put_image_to_window(data->mlx, data->win,
                            data->two_D.img_ptr, 0, 0);
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
			my_mlx_pixel_put(&data->two_D, x, y, color);
			y++;
		}
		x++;
	}
}
