#include <stdio.h>
#include "cub3d.h"


// void	mlx_put_pixel(t_img *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->address + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }



void	start_draw(t_parsing_result *data)
{

	create_win(data);
	//2d and 3d
	// maps_load(data);
	//just 3d
	draw_3d(data);
	mlx_key_hook(data->mlx, &click_button, data);
	// mlx_loop_hook(data->win, close_clik, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);


}

int main(int argc, const char **argv)
{
	t_parsing_result data;

	data = parsing(argv, argc);
	data.player.x += 0.5;
	data.player.y += 0.5;
	printf("%s\n",data.ea);
	data.texture[0] = mlx_load_png("./example.png");
	if (!data.texture[0])
		{
			printf("0 failed to load texture\n");
			exit(1);
		}
	
	printf("player x %f y %f\n",data.player.x, data.player.y);
	start_draw(&data);

	
	
}	
