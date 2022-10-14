#include "cub3d.h"



int	check_position(t_vars *vars, int a, int b)
{
	int	x;
	int	y;

	x = vars->player.x / 64;
	y = vars->player.y / 64;
	if (vars->map_info.maps[y - a][x - b] == '1')
		return (-1);
	else if (vars->map_info.maps[y - a][x - b] == 'E')
		return (-2);
	else if (vars->map_info.maps[y - a][x - b] == 'C')
		return (1);
	else
		return (0);
}

void clean_old_image(t_vars *vars)
{
	int x = 0;
	int y = 0;
	
	while (x < 50)
	{
		y = 0;
		while (y < 50)
		{
			my_mlx_pixel_put(&vars->player, x, y, 0XADD8E6);
			y++;
		}
		x++;
	}
	printf("x %d y %d\n",vars->player.x, vars->player.y);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->player.img_ptr, vars->player.x, vars->player.y);
}

void	change_position(t_vars *vars, int keycode)
{
	clean_old_image(vars);
	if (keycode == LEFT || keycode == A)
		vars->player.x = vars->player.x - vars->image_len;
	if (keycode == RIGHT || keycode == D)
		vars->player.x = vars->player.x + vars->image_len;
	if (keycode == DOWN || keycode == S)
		vars->player.y = vars->player.y + vars->image_len;
	if (keycode == UP || keycode == W)
		vars->player.y = vars->player.y - vars->image_len;
	create_player(vars, vars->player.x, vars->player.y);
}

int	click_button(int keycode, t_vars *vars)
{

	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
	}
	change_position(vars, keycode);
	return (0);
}

int	close_clik(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}