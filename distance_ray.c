/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   distance_ray.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 11:48:32 by adoner        #+#    #+#                 */
/*   Updated: 2022/12/09 11:51:56 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	dda_alg(t_parsing_result *data, t_calculation *ca)
{
	while (ca->hit == 0)
	{
		if (ca->sideX < ca->sideY)
		{
			ca->sideX += ca->deltaX;
			ca->mapX += ca->stepX;
			data->player.side = 0 + (ca->stepX + 1);
		}
		else
		{
			ca->sideY += ca->deltaY;
			ca->mapY += ca->stepY;
			data->player.side = 1 + (1 + ca->stepY);
		}
		if (data->map[ca->mapY][ca->mapX] == '1')
			ca->hit = 1;
	}
}

void	find_ray(t_calculation *cal, t_parsing_result *data)
{
	if (cal->rayX < 0)
	{
		cal->stepX = -1;
		cal->sideX = (data->player.x - cal->mapX) * cal->deltaX;
	}
	else
	{
		cal->stepX = 1;
		cal->sideX = (cal->mapX + 1.0 - data->player.x) * cal->deltaX;
	}
	if (cal->rayY < 0)
	{
		cal->stepY = -1;
		cal->sideY = (data->player.y - cal->mapY) * cal->deltaY;
	}
	else
	{
		cal->stepY = 1;
		cal->sideY = (cal->mapY + 1.0 - data->player.y) * cal->deltaY;
	}
}

double	find_distance(t_parsing_result *data, t_calculation *cal, double angle)
{
	double	distance;
	double	ca;
	double	perp_dist;

	if (data->player.side == 0 || data->player.side == 2)
		distance = cal->sideX - cal->deltaX;
	else
		distance = cal->sideY - cal->deltaY;
	ca = data->player.pa - angle;
	if (ca < 0)
		ca += 2 * M_PI;
	else if (ca > 2 * M_PI)
		ca -= 2 * M_PI;
	perp_dist = distance * cos(ca);
	perp_dist = fabs(perp_dist);
	if (data->player.side == EAST || data->player.side == WEST)
		data->player.wall_x = data->player.y + cal->rayY * perp_dist;
	else
		data->player.wall_x = data->player.x + cal->rayX * perp_dist;
	data->player.wall_x -= floorf(data->player.wall_x);
	return (perp_dist);
}

double	len_find(t_parsing_result *data, double angle)
{
	t_calculation	cal;

	cal.mapY = (int)data->player.y;
	cal.mapX = (int)data->player.x;
	cal.rayX = cos(angle);
	cal.rayY = sin(angle);
	cal.deltaX = fabs(1 / cal.rayX);
	cal.hit = 0;
	cal.deltaY = fabs(1 / cal.rayY);
	find_ray(&cal, data);
	dda_alg(data, &cal);
	return (find_distance(data, &cal, angle));
}

void	draw_3d(t_parsing_result *data)
{
	int		a;
	double	i;

	i = -0.3;
	a = 0;
	while (i < 0.3)
	{
		data->player.ray = len_find(data, data->player.pa + i);
		walls(data, a);
		i += 0.0006;
		a++;
	}
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
