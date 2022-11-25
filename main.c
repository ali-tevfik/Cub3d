#include <stdio.h>
#include "cub3d.h"


void	my_mlx_pixel_put(t_img *img, int x, int y, unsigned int colour)
{
	char	*dst;
	int		offset;

	offset = y * img->line_size + x * (img->bits_per_pixel / 8);
	dst = img->address + offset;
	*(unsigned int *)dst = colour;
}



void	start_draw( t_parsing_result *data)
{

	create_win(data);
	//2d and 3d
	// maps_load(data);
	//just 3d
	draw_3d(data);

	mlx_hook(data->win, 2, 0, click_button, data);
	mlx_hook(data->win, 17, 0, close_clik, data);
	mlx_loop(data->mlx);


}

int main(int argc, const char **argv)
{
	t_parsing_result data;

	data = parsing(argv, argc);
	data.player.x += 0.5;
	data.player.y += 0.5;

	printf("player x %f y %f\n",data.player.x, data.player.y);
	start_draw(&data);

	
	
}	
