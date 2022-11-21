#include "cub3d.h"

// int check_up(t_parsing_result *data)
// {
//     return(50 < data->player.y);
// }

// int check_down(t_parsing_result *data)
// {
//     int down = data->map_info.len_cols - 1;
//     return ((down * 50) > data->player.y + data->game_speed);
// }

// int check_left(t_parsing_result *data)
// {
//     return (data->player.x > 50);
// }

// //result = check_position(data, 0, -1);
// int check_right(t_parsing_result *data)
// {
//     int x = data->player.x /50;
//     int y = data->player.y /50;
//     int len_rows= data->map_info.len_rows- 1;
    
//     if (data->map_info.maps[y][x -1] == '1')
//     {
//         printf("duvar konumu [%d][%d]\n", y , x - 1);
//         printf("duvar %d player %f\n",(x-1) * 50, data->player.x);
//         return ((x - 1) * 50 > data->player.x);
//     }
//     return (data->player.x + data->game_speed < len_rows* 50);
// }


int check_walls(double ray_x, double ray_y, t_parsing_result *data)
{
    double wall_x;
    double wall_y;

    wall_x = (ray_x) / 50;
    wall_y = (ray_y)/50;
    if (data->map[(int)wall_y][(int)wall_x] == '1')
        return (FALSE);
    return (TRUE);  
}

double find_ray_len(double x, double y)
{
    double result = (x * x) + (y * y);
    return (sqrt(result));
}