/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemura <ydemura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:25:19 by ydemura           #+#    #+#             */
/*   Updated: 2022/12/08 16:36:31 by ydemura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_move(int x, int y, t_parsing_result *data)
{
	if (data->len_cols > x && data->len_rows > y && x > 0 && y > 0)
	{
		if (data->map[y][x] == '1')
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}

void	key_left(t_parsing_result *data)
{
	printf("\n LEFT\n--------------------\n");
	data->player.pa -= 0.08 * M_PI;
	printf("angle = %f\n", data->player.pa / (M_PI));
	if (data->player.pa < 0)
		data->player.pa += 2 * M_PI;
	printf("after angle   = %f\n", data->player.pa / (M_PI));
		data->player.x_camera = cos(data->player.pa) * 5.0;
		data->player.y_camera = sin(data->player.pa) * 5.0;
	printf("camera x %f %f\n",data->player.x_camera, data->player.y_camera);
	printf("position x %f y %f\n",data->player.x, data->player.y);
}

void	key_a(double move_x, double move_y, t_parsing_result *data)
{
	move_x = data->player.x + data->player.game_speed
		* cos(data->player.pa - 0.5 * M_PI);
	move_y = data->player.y + data->player.game_speed
		* sin(data->player.pa - 0.5 * M_PI);
	if (check_move(move_x, move_y, data))
	{
		data->player.y = move_y;
		data->player.x = move_x;
	}
}

void	key_d(double move_x, double move_y, t_parsing_result *data)
{
	move_x = data->player.x + data->player.game_speed
		* cos(data->player.pa + 0.5 * M_PI);
	move_y = data->player.y + data->player.game_speed
		* sin(data->player.pa + 0.5 * M_PI);
	if (check_move(move_x, move_y, data))
	{
		data->player.y = move_y;
		data->player.x = move_x;
	}
}

void	key_right(double move_x, double move_y, t_parsing_result *data)
{
	printf("\n RIGHT\n--------------------\n");
	printf("angle before %f\n", data->player.pa  / (M_PI));
	data->player.pa += 0.08 * M_PI;
	if (data->player.pa > 2 * M_PI)
		data->player.pa -= 2 * M_PI;
	data->player.x_camera = cos(data->player.pa) * 5.0;
	data->player.y_camera = sin(data->player.pa) * 5.0;
	printf("after angle = %f\n", data->player.pa / (M_PI));
	printf("camerea x %f %f\n",data->player.x_camera, data->player.y_camera);
	printf("position %f %f\n",data->player.x, data->player.y);
}

void	key_s(double move_x, double move_y, t_parsing_result *data)
{
	printf("\n DOWN\n--------------------\n");
	printf("angle  = %f\n", data->player.pa / (M_PI));
	// data->player.x -= data->player.x_camera;
	// data->player.y -= data->player.y_camera;
	printf("before position %f %f\n",data->player.x, data->player.y);
	move_x = data->player.x - data->player.game_speed * cos(data->player.pa);
	move_y = data->player.y - data->player.game_speed * sin(data->player.pa);
	if (check_move(move_x, move_y, data))
	{
		data->player.x = move_x;
		// hit = 1;
		data->player.y = move_y;
	}
	printf("player pos after %f %f\n",data->player.x, data->player.y);
	printf("camera %f %f\n",data->player.x_camera, data->player.y_camera);
}

void key_w(double move_x, double move_y, t_parsing_result *data)
{
	printf("\n UP\n--------------------\n");
	printf(" before angle = %f\n", data->player.pa / (M_PI));
	// data->player.x += data->player.x_camera;
	// data->player.y += data->player.y_camera;
	printf("pos player beforeup %f %f max x %d max y %d\n",data->player.x, data->player.y, data->len_cols, data->len_rows);
	move_x = data->player.x + data->player.game_speed * cos(data->player.pa);
	move_y = data->player.y + data->player.game_speed * sin(data->player.pa);
	if (check_move(move_x, move_y, data))
	{
		data->player.x = move_x;
		data->player.y = move_y;
		// hit = 1;
	}
}

	// int hit = 0;
void	move(t_parsing_result *data)
{
	double	move_x;
	double	move_y;

	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		key_left(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		key_a(move_x, move_y, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		key_d(move_x, move_y, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		key_right(move_x, move_y, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		key_s(move_x, move_y, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		key_w(move_x, move_y, data);
	draw_3d(data);
}

void	click_button(mlx_key_data_t keydata, void *info)
{
	int					result;
	t_parsing_result	*data;

	data = (t_parsing_result *) info;
	result = -1;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(data->mlx);
		exit(0);
	}
	move(data);
}

int	close_clik(t_parsing_result *data)
{
	mlx_close_window(data->mlx);
	exit (0);
}
