#include "cub3d.h"

//450-10000
void walls(t_parsing_result *data)
{
    int y;

    double height;
    int start = 0;
    int finish = 1000;
    int half = (finish - start) /2;
    // int ray_stuk = 750;
    int i = 0;
    double half_height;
    int x;
    // while(i < ray_stuk)
    // {
        // height = ((double)750 / ( 50 * data->player.ray[i]));
        height = 750 * data->player.ray[0];
        printf("data %f\n",data->player.ray[0]);
        // printf("heih %f %f %f %f\n",height, data->player.ray[i],data->player.x, data->player.y);
        if (height > 750)
            height = 750;
        if (height < 0)
            height = 0;
        half_height = height / 2;

            y = start;
            while (y < finish)
            {
                //up
                if (y < half)
                    my_mlx_pixel_put(&data->two_D, i ,y, BLACK);
                else //down
                    my_mlx_pixel_put(&data->two_D, i ,y, BLACK);
                y++;
            }
            x = 0;
          
            //up walls
            while (half_height > x && half - x < finish && half - x > start)
            {
                if (data->player.ray[i] > 100)
                    my_mlx_pixel_put(&data->two_D, i ,half - x, RED / 2);
                else
                    my_mlx_pixel_put(&data->two_D, i ,half - x, RED);
                x++;
            }
            x = 0;
            //down walls
            while (height > half_height && half + x < finish && half + x > start)
            {
                if (data->player.ray[i] > 100)
                    my_mlx_pixel_put(&data->two_D, i ,half + x, RED / 2);
                else
                    my_mlx_pixel_put(&data->two_D, i ,half + x, RED);
                    

                half_height++;
                x++;
            }
            
            i++;
        
    }

// }


void draw3Dstart(t_parsing_result *data)
{
  
    walls(data);

    mlx_put_image_to_window(data->mlx, data->win,
                            data->two_D.img_ptr, 0, 0);
}