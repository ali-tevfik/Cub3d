#include "cub3d.h"

void	free_all(t_parsing_result *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data->no);
	free(data->so);
	free(data->ea);
	free(data->we);
	mlx_delete_texture(data->texture[0]);
	mlx_delete_texture(data->texture[1]);
	mlx_delete_texture(data->texture[2]);
	mlx_delete_texture(data->texture[3]);
	mlx_delete_image(data->mlx, data->img);

	//leaks -> not sure where they are 
}

void	create_win(t_parsing_result *data)
{
	data->mlx = mlx_init((const uint32_t)screenWidth, (const uint32_t)screenHeight, "Cub3d", false);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->img = mlx_new_image(data->mlx, screenWidth, screenHeight);
}


void	start_draw(t_parsing_result *data)
{

	create_win(data);

	draw_3d(data);
	mlx_key_hook(data->mlx, &click_button, data);
	mlx_loop(data->mlx);
	free_all(data);
	mlx_terminate(data->mlx);
}

void	leaks(void){
	system("leaks -q cub3d");
}

void fill_text(t_parsing_result *data)
{
	data->texture[0] = mlx_load_png(data->ea);

	data->texture[1] = mlx_load_png(data->so);
	
	data->texture[2] = mlx_load_png(data->we);

	data->texture[3] = mlx_load_png(data->no);
	if (!data->texture[0] || !data->texture[1] ||!data->texture[2] || !data->texture[3] )
	{
		printf("0 failed to load texture\n");
		exit(1);
	}
	
}

int main(int argc, const char **argv)
{
	t_parsing_result data;
	atexit(leaks);
	data = parsing(argv, argc);
	fill_text(&data);
	start_draw(&data);
}	
