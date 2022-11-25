#include "cub3d.h"

double draw_ray(t_parsing_result *data, double angle, long color)
{
    double x1;
    double y1;
	double  i = 0;
	double len;
	double oldx;
	double oldy;
	oldx = (i * cos(angle)) + data->player.x * 50 ;
    oldy = (i * sin(angle)) + data->player.y * 50 ;
	// printf("angel %f\n",angle);
    while(1)
    {
        x1 = (i * cos(angle)) + data->player.x  * 50 + 1;
        y1 = (i * sin(angle)) + data->player.y  * 50 + 1;
		// printf("x %d y %d ,angel value = %f, y value = %f\n",data->player.x, data->player.y ,data->player.d_x, data->player.d_y);	
        // printf("x1 %d y1 %d\n",x1,y1);
        if (x1 < data->len_cols * 50 && x1 > 0  && y1 < data->len_rows * 50 && y1 > 0)
		{
			if (check_walls(x1, y1, data))
			{
            	my_mlx_pixel_put(&data->two_D, x1, y1, color);
				// printf("ray x %d y %d\n",x1,y1);
			}
			else
				break;
		}
		else
		{
			break;
		}
		i += 0.01;
    }
	// printf("new x %d - old x %d = %d. and new y %d - old y %d = %d\n",x1,oldx, x1-oldx, y1,oldy, y1-oldy);
	len = find_ray_len(x1-oldx, y1-oldy);
	// printf("len %f\n",len);
	return (len);
}

void draw_angle(t_parsing_result *data, double angle, int line_lenght, long color)
{
    double x1;
    double y1;

    for(int i = 0; i < line_lenght; i += 1)
    {
        x1 = (i * cos(angle)) + data->player.x * 50 + 1;
        y1 = (i * sin(angle)) + data->player.y * 50 + 1;
		// printf("x %d y %d ,angel value = %f, y value = %f\n", data->len_rows * 50,  data->len_cols * 50 ,x1,y1);	
        if (x1 < data->len_cols * 50 && x1 > 0  && y1 < data->len_rows * 50 && y1 > 0)
            my_mlx_pixel_put(&data->two_D, x1, y1, color);
	}
    // printf("x value = %d, y value = %d\n", x1, y1);
}