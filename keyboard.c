#include "cub3d.h"



void clean_old_image(t_vars *vars)
{
	int x = 0;
	int y = 0;
	
	while (x < 5)
	{
		y = 0;
		while (y < 5)
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
		vars->player.x = vars->player.x - vars->game_speed;
	if (keycode == RIGHT || keycode == D)
		vars->player.x = vars->player.x + vars->game_speed;
	if (keycode == DOWN || keycode == S)
		vars->player.y = vars->player.y + vars->game_speed;
	if (keycode == UP || keycode == W)
		vars->player.y = vars->player.y - vars->game_speed;
	create_player(vars, vars->player.x, vars->player.y);
}

void	check_position(t_vars *vars)
{
	int x = vars->player.x /50;
	int y = vars->player.y / 50;
	printf("konum x = %d y %d\n", x , y);
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
		printf("burda\n");
		if (check_up(vars) && result != 0){
			printf("girdi\n\n");
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