#include "cub3d.h"

int finy_camera(double y1, double angel)
{
    int next_y;

    if (angel > 0.5 * M_PI && angel < 1.5 * M_PI)
        next_y = (double)(y1 /50 - 0.001) * 50;
    else
        next_y = (double)(y1 /50 + 1) * 50;
    return (next_y);
}

int finx_camera(double x1, double angel)
{
    int next_x;

    if (angel > M_PI)
        next_x = ((int)x1 /50 - 0.001) * 50;
    else
        next_x = ((int)x1 /50 + 1) * 50;
    return (next_x + 1);
}


double draw_ray(t_parsing_result *data, double angle, long color)
{
    double x1;
    double y1;
    double i = 0;
    double len;
    double oldx;
    double oldy;
    int map_x;
    int map_y;
    oldx = (i * cos(angle)) + data->player.x;
    oldy = (i * sin(angle)) + data->player.y;
    // printf("angel %f\n",angle);
    while (1)
    {
        
        x1 = (i * cos(angle)) + data->player.x + 1;
        y1 = (i * sin(angle)) + data->player.y + 1;
        if (x1 < data->len_rows* 50.0 && x1 > 0 && y1 < data->len_cols * 50.0 && y1 > 0)
        {
                map_x = finx_camera(x1, angle);
                map_y = finy_camera(y1, angle);
            if (check_walls(map_x, map_y, data))
            {
                while (map_x > map_y && map_x > x1)
                {
                    my_mlx_pixel_put(&data->two_D, map_x,  map_y, color);
                    x1 = (i * cos(angle)) + data->player.x;
                    y1 = (i * sin(angle)) + data->player.y;
                    // printf("ustteki while\n");
                    i += 0.01;
                }
               
                
                
            }
            else
                break;
                // else
                // {
                //     unsigned int a = ((int)(x1 / 50) + 1) * 50;
                //     unsigned int b = ((int)(y1 / 50) + 1) * 50;

                //     if (a > b)
                //     {
                //         while (a > x1)
                //         {
                //         // printf("x1 %f a %d y1 %f b %d\n",x1,a,y1,b);
                //             x1 = (i * cos(angle)) + data->player.x + 1;
                //             y1 = (i * sin(angle)) + data->player.y + 1;
                //             my_mlx_pixel_put(&data->two_D, x1, y1, color);
                //             i += 0.01;
                //         }
                //     }
                //     else
                //     {
                //         while (b > y1)
                //         {
                //             x1 = (i * cos(angle)) + data->player.x + 1;
                //             y1 = (i * sin(angle)) + data->player.y + 1;
                //             my_mlx_pixel_put(&data->two_D, x1, y1, color);
                //             i += 0.01;
                //         }
                //     }
                // }
            }
            else
            {
                break;
            }
            i += 0.01;
        }
    // printf("new x %d - old x %d = %d. and new y %d - old y %d = %d\n",x1,oldx, x1-oldx, y1,oldy, y1-oldy);
    len= find_ray_len(x1 - oldx, y1 - oldy);
    // printf("len_rows%f\n",len);
    return (len);
}

void draw_angle(t_parsing_result *data, double angle, int line_lenght, long color)
{
    double x1;
    double y1;

    for (int i = 0; i < line_lenght; i += 1)
    {
        x1 = (i * cos(angle)) + data->player.x + 1;
        y1 = (i * sin(angle)) + data->player.y + 1;
        // printf("x %d y %d ,angel value = %f, y value = %f\n",data->player.x, data->player.y ,data->player.x_camera, data->player.y_camera);
        if (x1 < data->len_rows* 50 && x1 > 0 && y1 < data->len_cols * 50 && y1 > 0)
            my_mlx_pixel_put(&data->two_D, x1, y1, color);
    }
    // printf("x value = %d, y value = %d\n", x1, y1);
}