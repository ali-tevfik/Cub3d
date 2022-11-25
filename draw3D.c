#include "cub3d.h"

//450-10000
void walls(t_parsing_result *data, int i)
{
    int y;

    double height;
    int start = 0;
    int finish = 1000;
    int half = (finish - start) /2;
    // int ray_stuk = 750;
    
    double half_height;
    int x;

        height = 1000 / data->player.ray; 
        // height = ((double)750 / ( 50 * data->player.ray));
        // height = 750 * data->player.ray[0];
        // printf("data %f\n",data->player.ray[0]);
        // printf("heih %f %f %f %f\n",height, data->player.ray,data->player.x, data->player.y);
        // printf("heighy %f\n",height);
        if (height > 1000)
            height = 999;
        if (height < 0)
            height = 0;
        half_height = height / 2;

            y = start;
            while (y < finish)
            {
                //up
                if (y < half)
                    my_mlx_pixel_put(&data->two_D, i ,y, 0XF08080);
                else //down
                    my_mlx_pixel_put(&data->two_D, i ,y, 0XF08080);
                y++;
            }
            x = 0;
          
            //up walls
            while (half_height > x && half - x < finish && half - x > start)
            {
                my_mlx_pixel_put(&data->two_D, i ,half - x, RED);
                x++;
            }
            x = 0;
            //down walls
            while (height > half_height && half + x < finish && half + x > start)
            {
                my_mlx_pixel_put(&data->two_D, i ,half + x, RED);
                half_height++;
                x++;
            }
            
            i++;
        
    }



