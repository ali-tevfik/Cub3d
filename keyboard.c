#include "cub3d.h"

void draw_line(t_vars *data, double angle, int line_lenght, long color)
{
    int x1;
    int y1;

    for(int i = 0; i < line_lenght; i += 1)
    {
        x1 = i * sin(angle) + data->player.x;
        y1 = i * cos(angle) + data->player.y;
        if (x1 < 15 * 50 && x1 > 0  && y1 < 6 * 50 && y1 > 0)
        {
			my_mlx_pixel_put(&data->player, x1, y1, color);
    		printf("draw line x value = %d, y value = %d\n", x1, y1);
		}
    }
	// mlx_put_image_to_window(data->mlx, data->win,
	// 	data->player.img_ptr, x1, y1);
}



void	change_position(t_vars *vars, int keycode)
{
	maps_load(vars, 1);
	if (keycode == LEFT || keycode == A)
	{
		//vars->player.x = vars->player.x - vars->game_speed;
		vars->player.x = vars->player.x - 15;
		vars->player.y = vars->player.y - 15;
	}
	if (keycode == RIGHT || keycode == D)
		vars->player.x = vars->player.x + vars->game_speed;
	if (keycode == DOWN || keycode == S)
		vars->player.y = vars->player.y + vars->game_speed;
	if (keycode == UP || keycode == W)
		vars->player.y = vars->player.y - vars->game_speed;

	// float a = (float)(30 /180) * 3.14159265359 ;
	// draw_line(vars, a, 10, 0XFFFF00);
	create_player(vars, vars->player.x, vars->player.y);
}

void	check_position(t_vars *vars)
{
	int x = vars->player.x /50;
	int y = vars->player.y / 50;
	printf("konum x = %d y %d\n", x * 50 , y * 50);
}


int	click_button(int keycode, t_vars *vars)
{
	int result;

	result = -1;
	
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
	}
	check_position(vars);
	if (keycode == RIGHT || keycode == D)
		{
			if (check_right(vars))
				result = 0;
		}
	else if (keycode == LEFT || keycode == A)
	{
		if (check_left(vars))
			result = 0;
	}

	else if (keycode == DOWN || keycode == S){
		if (check_down(vars))
			result = 0;
		}
	else if (keycode == UP || keycode == W)
	{
		//printf("burda\n");
		if (check_up(vars) && result != 0){
			//printf("girdi\n\n");
			result = 0;
		}
	}
	else
		return (0);
	if (result == 0)
	change_position(vars, keycode);
	return (0);
}

int	close_clik(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}