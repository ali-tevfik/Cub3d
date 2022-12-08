/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_moves.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydemura <ydemura@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/08 16:43:28 by ydemura       #+#    #+#                 */
/*   Updated: 2022/12/08 20:21:03 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "key_moves.h"
#include <math.h>

void	key_left(t_parsing_result *data)
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

void	key_right(t_parsing_result *data)
{
	printf("\n RIGHT\n--------------------\n");
	printf("angle before %f\n", data->player.pa  / (M_PI));
	data->player.pa += 0.05 * M_PI;
	if (data->player.pa > 2 * M_PI)
		data->player.pa -= 2 * M_PI;
	data->player.x_camera = cos(data->player.pa) * 5.0;
	data->player.y_camera = sin(data->player.pa) * 5.0;
	printf("after angle = %f\n", data->player.pa / (M_PI));
	printf("camerea x %f %f\n",data->player.x_camera, data->player.y_camera);
	printf("position %f %f\n",data->player.x, data->player.y);
}

void	key_a(t_parsing_result *data)
{
	double	move_x;
	double	move_y;

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

void	key_d(t_parsing_result *data)
{
	double	move_x;
	double	move_y;

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

void	key_s(t_parsing_result *data)
{
	double	move_x;
	double	move_y;

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
