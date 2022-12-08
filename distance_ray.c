#include "cub3d.h"
#include <stdio.h>
double len_find(t_parsing_result *data, double angle)
{
    int mapX = (int)data->player.x;
    int mapY = (int)data->player.y;
    double rayX = cos(angle);
    double rayY = sin(angle);
    double deltaX = fabs(1 / rayX);
    double deltaY = fabs(1 / rayY);
    double sideX;
    double sideY;
    int stepX;
    int stepY;
    int hit = 0;

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

    while (hit == 0)
    {
        if (sideX < sideY)
        {
            sideX += deltaX;
            mapX += stepX;
            data->player.side =0 + (stepX + 1);
        }
        else
        {
            sideY += deltaY;
            mapY += stepY;
            data->player.side = 1 + (1+ stepY);
        }
        if (data->map[mapY][mapX] == '1')
            hit = 1;
    }

    double distance;
    if (data->player.side == 0 || data->player.side == 2)
        distance = sideX - deltaX;
    else
        distance = sideY - deltaY;
    double ca = data->player.pa - angle;
    if (ca < 0)
			ca += 2 * M_PI;
	else if ( ca > 2 * M_PI)
			ca -= 2 * M_PI;
    double perp_dist = distance * cos(ca) ;
    perp_dist = fabs(perp_dist);
    if (data->player.side == EAST || data->player.side == WEST)
        data->player.wall_x = data->player.y + rayY * perp_dist;
    else
        data->player.wall_x = data->player.x + rayX * perp_dist;
    data->player.wall_x -= floorf(data->player.wall_x);


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
    mlx_image_to_window(data->mlx, data->img, 0, 0);
}
