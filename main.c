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

void	create_win(t_vars *vars, int x, int y)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, x * 50, y * 50, "CUB3D");
	vars->background.img_ptr = mlx_new_image(vars->mlx, x * 50, y * 50);
	vars->background.address = mlx_get_data_addr(vars->background.img_ptr,
			&vars->background.bits_per_pixel,
			&vars->background.line_size, &vars->background.endian);
}

void create_space(t_vars *vars, int a, int b)
{
	int x = 0;
	int y = 0;
	
	

	while (x < 49)
	{
		y = 0;
		while (y < 49)
		{
			my_mlx_pixel_put(&vars->background, x, y, 0XFFFFFF);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->background.img_ptr, a * 50 , b * 50 );
}


void create_angel(t_vars *vars, int wall_x, int wall_y)
{
	int x = 0;
	int y = 0;
	
	
	while (x < 1)
	{
		y = 0;
		while (y < 7)
		{
			my_mlx_pixel_put(&vars->background, 0, 0, 0XE6ADD8);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->background.img_ptr, wall_x + 2 , wall_y - 7 );
		
}
// -7 up +7 down, 
void create_player(t_vars *vars, int player_x, int player_y)
{

	int x = 0;
	int y = 0;

	
	while (x < 5)
	{
		y = 0;
		while (y < 5)
		{
			my_mlx_pixel_put(&vars->background, x, y, 0XE6ADD8);
			y++;
		}
		x++;
	}


	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->background.img_ptr, player_x, player_y);
	float a = (float)30 /180;
	draw_line(vars, a * PI , 10, 0XE6ADD8);
	// create_angel(vars, vars->player.d_x, vars->player.d_y);



}

void create_walls(t_vars *vars, int wall_x, int wall_y)
{
	int x = 0;
	int y = 0;
	

	while (x < 49)
	{
		y = 0;
		while (y < 49)
		{
			my_mlx_pixel_put(&vars->background, x, y, 0X4C1130);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->background.img_ptr, wall_x * 50 , wall_y * 50 );
}
t_vars	*maps_load(t_vars *vars, int where)
{
	int	a;
	int	x;

	where = 0;
	x = 0;
	while (vars->map_info.maps[x])
	{
		a = 0;
		while (vars->map_info.maps[x][a])
		{
			if (vars->map_info.maps[x][a] == '0')
				create_space(vars, a, x);
			else if (vars->map_info.maps[x][a] == '1')
			{
				create_walls(vars, a, x);
			}
			else if (vars->map_info.maps[x][a] == 'P' )
			{
				create_space(vars, a, x);
				if (where == 0)
				{
					vars->player.y = vars->image_len * x;
					vars->player.x = vars->image_len * a;
					create_player(vars, vars->player.x, vars->player.y);
				}
			}
			a++;
		}
		x++;
	}
	return (vars);
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
	maps_load(&vars, 0);
	mlx_hook(vars.win, 2, 0, click_button, &vars);
	mlx_hook(vars.win, 17, 0, close_clik, &vars);
	mlx_loop(vars.mlx);
}

int main()
{
    char  **map;
	t_map maps_info;

	maps_info.len = 15;
	maps_info.line = 5;
	map = malloc(sizeof(char**) * 6);
	map[0] = malloc(sizeof(char *) * 13);
	map[1] = malloc(sizeof(char *) * 13);
	map[2] = malloc(sizeof(char *) * 13);
	map[3] = malloc(sizeof(char *) * 13);
	map[0] = malloc(sizeof(char *) * 13);
    map[0] = "111111111111111";
	map[1] = "100000000001001";
	map[2] = "10000P000001001";
    map[3] = "100000000001001";
	map[4] = "111111111111111";
	map[5] = NULL;
	start_draw(map, &maps_info);
	
	
}