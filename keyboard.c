#include "cub3d.h"


void	move(t_parsing_result *data, int keycode)
{
	clean_maps(data);
	if (keycode == LEFT || keycode == A)
	{
		printf("\n LEFT\n--------------------\n");
		data->player.pa -= 0.05 * M_PI; 
		printf("angle = %f\n", data->player.pa / (M_PI));
		if (data->player.pa < 0)
			data->player.pa += 2 * M_PI;
		printf("angle after  = %f\n", data->player.pa / (M_PI));
			data->player.x_camera = cos(data->player.pa) * 5;
			data->player.y_camera = sin(data->player.pa) * 5;
		printf("_d %f %f\n",data->player.x_camera, data->player.y_camera);
		printf("left x %f y %f\n",data->player.x, data->player.y);
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
		printf("angle = %f\n", data->player.pa / (M_PI));
		printf("_d %f %f\n",data->player.x_camera, data->player.y_camera);
		printf("right %f %f\n",data->player.x, data->player.y);
		
	}
	if (keycode == DOWN || keycode == S)
	{
		printf("\n DOWN\n--------------------\n");
		printf("angle befor = %f\n", data->player.pa / (M_PI));
		data->player.x -= data->player.x_camera;
		data->player.y -= data->player.y_camera;
		printf("angel %f\n",data->player.pa  / (M_PI));
		printf("down_d %f %f\n",data->player.x_camera, data->player.y_camera);
		printf("down %f %f\n",data->player.x, data->player.y);

	} 
	if (keycode == UP || keycode == W)
	{
		printf("\n UP\n--------------------\n");

		printf(" before angle = %f\n", data->player.pa / (M_PI));
		data->player.x += data->player.x_camera;
		data->player.y += data->player.y_camera;
		printf("angle = %f\n", data->player.pa / (M_PI));

		printf("up_d %f %f\n",data->player.x_camera, data->player.y_camera);
		printf("up %f %f\n",data->player.x, data->player.y);

	}

	// maps_load(data, 1);
	draw_3d(data);
	

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