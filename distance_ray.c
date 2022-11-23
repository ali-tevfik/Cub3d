#include "cub3d.h"

// // double next_y(t_parsing_result *data, double angel)
// // {
// //     double rand, nextX, nextY, deltaX, deltaY, len = 10000;
// //     int a = 0;
// //     while (a < data->len_cols)
// //     {
// //         if (angel == 2 * PI || angel == 0)
// //             break;
// //         else if (angel > PI)
// //         {
// //             //-0.001
// //             nextY = ((int)((data->player.y / 50) - 0.001)) * 50;
            
// //             rand = angel - PI;
// //             nextX = data->player.x - tan(rand) * fabs(data->player.y - nextY);
// //         }
// //         else
// //         {
// //             //+1
// //             nextY = ((int)(data->player.y / 50) + 1) * 50;
// //             rand = angel;
// //             nextX = data->player.x - tan(rand) * fabs(data->player.y - nextY);
// //         }
// //         if (nextX > 750 || nextX < 0 || nextY < 0 || nextY > 750)
// //             break;
// //         deltaX = fabs(data->player.x - nextX);
// //         deltaY = fabs(data->player.y - nextY);
// //         len = sqrt((deltaX * deltaX) + (deltaY * deltaY));
// //         data->player.hitX = nextX;
// //         if (((int) nextY /50) < data->len_rows && ((int) nextX /50) < data->len_cols)
// //         {
// //             if (data->map[(int)nextY / 50][(int)nextX / 50] != 0)
// //                 break;
// //         }
// //         a++;
// //     }

// //     return (len);
// // }

// // double next_x(t_parsing_result *data, double angel)
// // {
// //     double rand, nextX, nextY, deltaX, deltaY, len = 10000;
// //     int a = 0;
// //     while (a < data->len_rows)
// //     {
    
// //         //-0.001 //left
// //         if (0.5 * PI < angel && angel < 1.5 * PI)
// //         {
// //             nextX = ((int)((data->player.x / 50) - 0.001)) * 50;
// //             // printf("nextX %f\n",nextX);
// //             rand = 2 * M_PI - angel;
// //             nextY = data->player.y + fabs(data->player.x - nextX) / tan(rand);
// //         }
// //         //+1
// //         else
// //         {
// //             nextX = ((int)(data->player.x / 50) + 1) * 50;
// //             rand = angel;
// //             nextY = data->player.y + fabs(data->player.x - nextX) / tan(rand);
// //         }
// //         printf("nextX %f nextY %f  player x %f y %f\n",nextX, nextY, data->player.x, data->player.y);
// //         if (nextX > 750 || nextX < 0 || nextY < 0 || nextY > 750)
// //             break;
// //         deltaX = fabs(data->player.x - nextX);
// //         deltaY = fabs(data->player.y - nextY);
// //         len = sqrt((deltaX * deltaX) + (deltaY * deltaY));
// //         data->player.hitY = nextY;
// //         if (((int) nextY /50) < data->len_rows && ((int) nextX /50) < data->len_cols)
// //         {
// //             if (data->map[((int)nextY / 50)][((int)nextX / 50)] != 0)
// //                 break;
// //         }
// //         else
// //             break;
// //         a++;
// //     }
// //     // printf("len %f\n",len);
// //     return (len);
// // }

// // double len_find(t_parsing_result *data, double angle)
// // {
   
// //     double find_next_x;
// //     find_next_x = next_x(data,angle);
// //     double shourtes;
// //     double find_next_y;
// //     find_next_y = next_y(data, angle);
// //     if (find_next_x < find_next_y)
// //     {
// //         shourtes = find_next_x;
// //         data->player.hitX = -1;
// //     }
// //     else
// //     {
// //         shourtes = find_next_y;
// //         data->player.hitY = -1;
// //     }
// //     double ca = data->player.pa - angle;
// //     if (ca < 0)
// //         ca += 2 * M_PI;
// //     else if (ca > 2 * M_PI)
// //         ca -= 2 * M_PI;
// //     shourtes = shourtes * cos(ca);
// //     // printf("%f x %f y %f\n", shourtes, find_next_x, find_next_y);

// //     return shourtes;
// // }

double len_find(t_parsing_result *data, double angle)
{

    int mapX = (int)roundf(data->player.x);
    int mapY = (int) roundf(data->player.y);
    
    double rayX = fabs(cos(angle));
    double rayY = fabs(sin(angle));

    // double deltaX = sqrtf(1 + (rayY * rayY)/(rayX * rayX));
    // double deltaY = sqrtf(1 + (rayX * rayX)/(rayY * rayY));
    double deltaX = fabs(1/rayX);
    double deltaY = fabs(1/rayY);
    double sideX;
    double sideY;

    int stepX;
    int stepY;

    int hit = 0;
    int side;
printf("deltaX %f deltaY %f\n ", deltaX, deltaY);
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
printf("sides X %f Y %f %d %d\n",sideX, sideY, stepX, stepY);
   //perform DDA
      while (hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if (sideX < sideY)
        {
printf("entering x\n");
          sideX += deltaX;
          mapX += stepX;
          side = 0;
        }
        else
        {
printf("entering y\n");
          sideY += deltaY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        //if (mapX < data->len_rows && mapY < data->len_cols)
        //{
            if (data->map[mapY][mapX] > 0)
                hit = 1;
        //}
      }
    
    double distance;
    if(side ==0)
        distance = sideX - deltaX;
    else
        distance = sideY - deltaY;
printf("delta %f %f mapx %d mapy %d %f\n", deltaX, deltaY,mapX, mapY, distance);
    return(fabs(distance));
}


void draw_3d(t_parsing_result *data)
{
    int a = 0;
    double i = 0;
    //double i = -0.3;
    //while (i < 0.3)
    //{
        data->player.ray[a] = len_find(data, data->player.pa + i);
        // printf("distance %f angel %f\n",data->player.ray[a], data->player.pa);
       // i += 0.0008;
      //  a++;
    //}
    draw3Dstart(data);
}

