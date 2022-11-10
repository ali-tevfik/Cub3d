#include "cub3d.h"

int check_up(t_vars *vars)
{
    return(50 < vars->player.y);
}

int check_down(t_vars *vars)
{
    int down = vars->map_info.line - 1;
    return ((down * 50) > vars->player.y + vars->game_speed);
}

int check_left(t_vars *vars)
{
    return (vars->player.x > 50);
}

//result = check_position(vars, 0, -1);
int check_right(t_vars *vars)
{
    int x = vars->player.x /50;
    int y = vars->player.y /50;
    int len = vars->map_info.len - 1;
    
    if (vars->map_info.maps[y][x -1] == '1')
    {
        printf("duvar konumu [%d][%d]\n", y , x - 1);
        printf("duvar %d player %f\n",(x-1) * 50, vars->player.x);
        return ((x - 1) * 50 > vars->player.x);
    }
    return (vars->player.x + vars->game_speed < len * 50);
}


int check_walls(double ray_x, double ray_y, t_vars *vars)
{
    int wall_x;
    int wall_y;

    wall_x = (ray_x) / 50;
    wall_y = (ray_y)/50;
        
    // // Bram
    // // if (vars->map_info.maps[wall_y - 1][wall_x - 1])
    // if (vars->map_info.len > wall_y -1 && wall_x-1 < vars->map_info.line)
    //     if (vars->map_info.maps[wall_y - 1][wall_x - 1] != '1')
    //         return (TRUE);
    // if (vars->map_info.len > wall_y -1 && wall_x+1 < vars->map_info.line)
    //     if (vars->map_info.maps[wall_y - 1][wall_x + 1] != '1')
    //         return (TRUE);
    // if (vars->map_info.len > wall_y +1 && wall_x-1 < vars->map_info.line)
    //     if (vars->map_info.maps[wall_y + 1][wall_x - 1] != '1')
    //         return (TRUE);
    // if (vars->map_info.len > wall_y +1 && wall_x+1 < vars->map_info.line)
    //     if (vars->map_info.maps[wall_y + 1][wall_x + 1] != '1')
    //         return (TRUE);
    // // end Bram

    // printf("x = %d y %d\n",wall_y,wall_x);
    if (vars->map_info.maps[wall_y][wall_x] == '1')
        return (FALSE);

    return (TRUE);  

    // return TRUE;
}

int find_ray_len(int x, int y)
{
    if (x == 0)
        return (abs(y));
    else if (y == 0)
        return (abs(x));
    int result = (x * x) + (y * y);
    return (sqrt(result));
}