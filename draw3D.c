#include "cub3d.h"

int	get_color(mlx_texture_t* texture, int x, int y)
{
	// unsigned long color;
	// int red;
	// int green;
	// int blue;
	return (texture->pixels[x * texture->width * 4 + (y * 4)]);
	// blue = texture->pixels[x * texture->width * 4+ (y * 4) + 1];
	// green = texture->pixels[x * texture->width * 4 + (y * 4) + 2];
	// red = texture->pixels[x * texture->width *4 + (y * 4) + 3];
	// color = (256 * 256 * 256 * 256) + (blue * 256 * 256) + (green * 256) + red;
	// return (color);
}

//450-10000
void walls(t_parsing_result *data, int i)
{
    int y;

    double height;
    int start = 0;
    double texture_step_y, tx = 125, ty = 75;
    int finish = 1000;
    int half = (finish - start) /2;
    // int ray_stuk = 750;
    long	color2;
    double half_height;
    int x;
    
        height = 1000 / data->player.ray; 
        if (height > 1000)
            height = 999;
        if (height < 0)
            height = 0;
        half_height = height / 2;
        texture_step_y = data->texture[0]->height/(float)height;
            y = start;
            while (y < finish)
            {
                //up
                if (y < half)
                    mlx_put_pixel(data->img, i ,y, BLAUW);
                else //down
                    mlx_put_pixel(data->img, i ,y, BLAUW);
                y++;
            }
            x = 0;
          
            //up walls
            while (half_height > x && half - x < finish && half - x > start)
            {
                color2 = get_color(data->texture[0], tx, ty);
                // printf("return %ld \n",color2);
                // tx++;
                ty++;
                mlx_put_pixel(data->img, i ,half - x, RED);
                x++;
            }
            x = 0;
            //down walls
            while (height > half_height && half + x < finish && half + x > start)
            {
                color2 = get_color(data->texture[0], tx, ty);
                //  tx++;
                ty++;
                mlx_put_pixel(data->img, i ,half + x, RED);
                half_height++;
                x++;
            }
            
            i++;
        
    }



