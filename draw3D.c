#include "cub3d.h"

//450-10000
void walls(t_parsing_result *data)
{
    int y;

    double height;
    int start = 400;
    int finish = 1000;
    int half = 700;
    int ray_stuk = 750;
    int i = 0;
    double half_height;
    int x;
    while(i < ray_stuk)
    {
        height = (double)50/ data->player.ray[i]  *377;
        // printf("ray %f\n",data->player.ray[i]);
        half_height = height / 2;
       
            y = start;
            // printf("heigh %d\n",height);
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

}


void draw3Dstart(t_parsing_result *data)
{
  
    walls(data);
}