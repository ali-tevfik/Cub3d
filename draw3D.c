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
                    mlx_put_pixel(data->img, i ,y, 0XF08080);
                else //down
                    mlx_put_pixel(data->img, i ,y, 0XF08080);
                y++;
            }
            x = 0;
          
            //up walls
            while (half_height > x && half - x < finish && half - x > start)
            {
                mlx_put_pixel(data->img, i ,half - x, RED);
                x++;
            }
            x = 0;
            //down walls
            while (height > half_height && half + x < finish && half + x > start)
            {
                mlx_put_pixel(data->img, i ,half + x, RED);
                half_height++;
                x++;
            }
            
            i++;
        
    }



