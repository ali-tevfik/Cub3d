#include "cub3d.h"

double len_find(t_parsing_result *data, double angle)
{

    // for(int y = 0; y <data->len_rows; y++)
    // {
    //     for(int x = 0; x <data->len_cols; x++)
    //     {
    //         printf("%c", data->map[y][x]);
    //     }
    //     printf("\n");
    // }




    int mapX = (int)roundf(data->player.x);
    int mapY = (int)roundf(data->player.y);

    double rayX = fabs(cos(angle));
    double rayY = fabs(sin(angle));

    double deltaX = fabs(1 / rayX);
    double deltaY = fabs(1 / rayY);
    double sideX;
    double sideY;

    int stepX;
    int stepY;

    int hit = 0;
    int side;
    // printf("deltaX %f deltaY %f\n ", deltaX, deltaY);
    if (rayX < 0)
    {
        stepX = -1;
        sideX = (data->player.x - mapX) * deltaX;
    }
    else
    {
        stepX = 1;
        sideX = (mapX + 1.0 - data->player.x) * deltaX;
    }
    if (rayY < 0)
    {
        stepY = -1;
        sideY = (data->player.y - mapY) * deltaY;
    }
    else
    {
        stepY = 1;
        sideY = (mapY + 1.0 - data->player.y) * deltaY;
    }
    // printf("sides X %f Y %f %d %d\n", sideX, sideY, stepX, stepY);
    // perform DDA
    while (hit == 0)
    {
        // jump to next map square, either in x-direction, or in y-direction
        if (sideX < sideY)
        {
           // printf("entering x\n");
            sideX += deltaX;
            mapX += stepX;
            side = 0;
        }
        else
        {
            //printf("entering y\n");
            sideY += deltaY;
            mapY += stepY;
            side = 1;
        }
       
            if (data->map[mapY][mapX] == '1')
                hit = 1;
        
            // printf("walls y %d x %d col %d row %d\n", mapY, mapX, data->len_cols, data->len_rows);
    }

    double distance;
    if (side == 0)
        distance = sideX - deltaX;
    else
        distance = sideY - deltaY;
    // printf("delta %f %f mapx %d mapy %d %f\n", deltaX, deltaY, mapX, mapY, distance);
    double ca = data->player.pa - angle;
    if (ca < 0)
			ca += 2 * PI;
	else if ( ca > 2 * PI)
			ca -= 2 * PI;
    double perp_dist = distance * cos(ca) ;
    printf("distance %f\n",perp_dist);
    return (perp_dist);
}

void draw_3d(t_parsing_result *data)
{
    int a = 0;
    double i = -0.3;
    while (i < 0.3)
    {
    data->player.ray = len_find(data, data->player.pa + i);
   
    walls(data, a);
    i += 0.0006;
     a++;
    }
     mlx_put_image_to_window(data->mlx, data->win,
                            data->two_D.img_ptr, 0, 0);

}
