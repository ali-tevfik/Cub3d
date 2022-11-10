#include "cub3d.h"



void up(t_vars *data )
{
    int x = 0;
    int y = 450;
    while (x < 1000)
    {
        y = 450;
        while (y < 550)
        {
            my_mlx_pixel_put(&data->two_D, x, y, 0X00FFFF);
            y++;
        }
        
        x++;
    }
    
}

void down(t_vars *data )
{
    int x = 0;
    int y ;
    while (x < 1000)
    {
        y = 900;
        while (y < 1000)
        {
            my_mlx_pixel_put(&data->two_D, x, y, 0X00FF00);
            y++;
        }
        
        x++;
    }
    
}
//450-10000
void walls(t_vars *data)
{
    int y;

    int height;
    int start = 400;
    int finish = 1000;
    int half = 700;
    int ray_stuk = 750;
    int i = 0;
    int half_height;
    int x;
    while(i < ray_stuk)
    {
        height = ray_stuk/ data->player.ray[i]  *10;
        // printf("heigh %d\n",height);
        half_height = height / 2;
       
            y = start;
            // printf("heigh %d\n",height);
            while (y < finish)
            {
                if (y < half)
                    my_mlx_pixel_put(&data->two_D, i ,y, 0X00FFFF);
                else
                    my_mlx_pixel_put(&data->two_D, i ,y, 0X00FF00);
                y++;
            }
            x = 0;
          
            while (half_height > x)
            {
                my_mlx_pixel_put(&data->two_D, i ,half- x, 0XFFFF00);
                x++;
            }
            x = 0;
            while (height > half_height)
            {
                my_mlx_pixel_put(&data->two_D, i ,half + x, 0XFFE599);
                half_height++;
                x++;
            }
            
            i++;
        
    }

}


void draw3Dstart(t_vars *data)
{
    // int start = 450;
    // int max = 100;
    // up(data);
    // down(data);
    walls(data);
    // for (int i = 0; i < data->player.ray[i]; i++)
    // {
    //     printf("data %d\n",data->player.ray[i]);
    // }
    // printf("-------------------\n");
    
    // data->map_info.collection = 0;
}