#include "cub3d.h"

int check_move(int x, int y, t_parsing_result *data)
{
	if (data->len_cols > x && data->len_rows > y && x > 0 && y > 0)
	{
		if (data->map[y][x] == '1')
			return FALSE;
		return (TRUE);
	}
	return (FALSE);
}
void	move(t_parsing_result *data, int keycode)
{
	double moveX;
	double moveY;
	int hit = 0;

	if (keycode == LEFT || keycode == A)
	{
		printf("\n LEFT\n--------------------\n");
		data->player.pa -= 0.05 * M_PI; 
		printf("angle = %f\n", data->player.pa / (M_PI));
		if (data->player.pa < 0)
			data->player.pa += 2 * M_PI;
		printf("after angle   = %f\n", data->player.pa / (M_PI));
			data->player.x_camera = cos(data->player.pa) * 5.0;
			data->player.y_camera = sin(data->player.pa) * 5.0;
		printf("camera x %f %f\n",data->player.x_camera, data->player.y_camera);
		printf("position x %f y %f\n",data->player.x, data->player.y);
	}

	if (keycode == RIGHT || keycode == D)
	{
		printf("\n RIGHT\n--------------------\n");
		printf("angle before %f\n",data->player.pa  / (M_PI));
		data->player.pa+= 0.05 *  M_PI; 
		if (data->player.pa > 2 * M_PI )
			data->player.pa -= 2 * M_PI;
		data->player.x_camera =  cos(data->player.pa) * 5.0;
		data->player.y_camera = sin(data->player.pa) * 5.0;
		printf("after angle = %f\n", data->player.pa / (M_PI));
		printf("camerea x %f %f\n",data->player.x_camera, data->player.y_camera);
		printf("position %f %f\n",data->player.x, data->player.y);
		
	}
	if (keycode == DOWN || keycode == S)
	{
		printf("\n DOWN\n--------------------\n");
		printf("angle  = %f\n", data->player.pa / (M_PI));
		// data->player.x -= data->player.x_camera;
		// data->player.y -= data->player.y_camera;
		printf("before position %f %f\n",data->player.x, data->player.y);
		moveX = data->player.x - data->player.game_speed * cos(data->player.pa);
		moveY = data->player.y - data->player.game_speed * sin(data->player.pa);
		if (check_move(moveX, moveY, data))
		{
			data->player.x = moveX;
			hit = 1;
			data->player.y = moveY;
		}
		printf("player pos after %f %f\n",data->player.x, data->player.y);
		printf("camera %f %f\n",data->player.x_camera, data->player.y_camera);

	} 
	if (keycode == UP || keycode == W)
	{
		printf("\n UP\n--------------------\n");

		printf(" before angle = %f\n", data->player.pa / (M_PI));
		// data->player.x += data->player.x_camera;
		// data->player.y += data->player.y_camera;
		printf("pos player beforeup %f %f max x %d max y %d\n",data->player.x, data->player.y, data->len_cols, data->len_rows);
		moveX = data->player.x + data->player.game_speed * cos(data->player.pa);
		moveY = data->player.y + data->player.game_speed * sin(data->player.pa);
		if (check_move(moveX, moveY, data))
		{
			data->player.x = moveX;
			data->player.y = moveY;
			hit = 1;
		}
		printf("pos player after x %f %f\n",data->player.x, data->player.y);

		printf("camera %f %f\n",data->player.x_camera, data->player.y_camera);

	}

	// if (hit == 1)
	// {
		clean_maps(data);
		// maps_load(data);
		draw_3d(data);
	// }

}

int	click_button(int keycode, t_parsing_result *data)
{
	int result;

	result = -1;
	
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
        exit(0);
	}
	move(data, keycode);
	return (0);
}

int	close_clik(t_parsing_result *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
}