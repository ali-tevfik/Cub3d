# include "minilibx_opengl/mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
#include <math.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*address;
	int		bits_per_pixel;
	int		line_size;
	int		len_height;
	int		img_width;
	int		endian;
	int		x;
	float		d_x;
	float		d_y;
	float		pa;
	int		y;
}			t_img;

typedef struct s_map
{
	int		player;
	int		collection;
	int		exit;
	int		line;
	int		len;
	char	**maps;
}			t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		image_len;
	t_img	player;
	t_img	spaces;
	t_img	background;
	t_img	walls;
	t_img	exit;
	t_img	angel;
	t_img	remove_old_chr;
	t_img	open_exit;
	int		game_speed;
	int		total_eat;
	int		counter;
	int		ate;
	t_map	map_info;
}			t_vars;







int	click_button(int keycode, t_vars *vars)
{
	vars->player.x = 0;
	return (keycode);
}
int	close_clik(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, unsigned int colour)
{
	char	*dst;
	int		offset;

	offset = y * img->line_size + x * (img->bits_per_pixel / 8);
	dst = img->address + offset;
	*(unsigned int *)dst = colour;
}
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
			my_mlx_pixel_put(&data->angel, x1, y1, color);
    		printf("draw line x value = %d, y value = %d\n", x1, y1);
		}
    }
	mlx_put_image_to_window(data->mlx, data->win,
		data->angel.img_ptr, data->player.x, data->player.y);
}



void	create_win(t_vars *vars, int x, int y)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, x * 50, y * 50, "CUB3D");
	vars->background.img_ptr = mlx_new_image(vars->mlx, x * 50, y * 50);
	vars->background.address = mlx_get_data_addr(vars->background.img_ptr,
			&vars->background.bits_per_pixel,
			&vars->background.line_size, &vars->background.endian);
}

void create_player(t_vars *vars)
{
    vars->player.img_ptr = mlx_new_image(vars->mlx, 5, 5);
    vars->player.address = mlx_get_data_addr(vars->player.img_ptr, &vars->player.bits_per_pixel, &vars->player.line_size, &vars->player.endian);
	
	vars->player.y = 250;
	vars->player.x = 250;		


    int x = 0;
	int y = 0;

	
	while (x < 5)
	{
		y = 0;
		while (y < 5)
		{
		my_mlx_pixel_put(&vars->player, x, y, 0XE6ADD8);

			y++;
		}
		x++;
	}


	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->player.img_ptr, 250, 250);		
}

void	start_draw(char **data, t_map *maps_info)
{
	t_vars	vars;

	vars.game_speed = 10;
	vars.map_info.maps = data;
	vars.map_info.len = maps_info->len;
	vars.map_info.line = maps_info->line;
	vars.image_len = 50;
	create_win(&vars, maps_info->len , maps_info->line);
	create_player(&vars);
    
    mlx_hook(vars.win, 2, 0, click_button, &vars);
	mlx_hook(vars.win, 17, 0, close_clik, &vars);
	mlx_loop(vars.mlx);
}





int main()
{
      char  **map;
	t_map maps_info;

	map = malloc(sizeof(char**) * 6);

	maps_info.len = 15;
	maps_info.line = 5;
	start_draw(map, &maps_info);
}