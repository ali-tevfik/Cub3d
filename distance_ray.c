/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemura <ydemura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:56:24 by ydemura           #+#    #+#             */
/*   Updated: 2022/12/08 18:24:45 by ydemura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initiate_side(t_parsing_result *data, t_calculation *c)
{
	if (c->ray_x < 0)
	{
		c->side_x = -1;
		c->side_x = (data->player.x - c->map_x) * c->delta_x;
	}
	else
	{
		c->side_x = 1;
		c->side_x = (c->map_x + 1.0 - data->player.x) * c->delta_x;
	}
	if (c->ray_y < 0)
	{
		c->side_y = -1;
		c->side_y = (data->player.y - c->map_y) * c->delta_y;
	}
	else
	{
		c->side_y = 1;
		c->side_y = (c->map_y + 1.0 - data->player.y) * c->delta_y;
	}
}

void	initiate_calculation(double angle, t_parsing_result *data,
		t_calculation *c)
{
	c->map_x = (int)data->player.x;
	c->map_y = (int)data->player.y;
	c->ray_x = cos(angle);
	c->ray_y = sin(angle);
	c->delta_x = fabs(1 / c->ray_x);
	c->delta_y = fabs(1 / c->ray_y);
	initiate_side(data, c);
	c->hit = 0;
}

double	distance(double angle, t_parsing_result *data, t_calculation *c)
{
	double	distance;
	double	ca;
	double	perp_dist;

	if (data->player.side == 0 || data->player.side == 2)
		distance = c->side_x - c->delta_x;
	else
		distance = c->side_y - c->delta_y;
	ca = data->player.pa - angle;
	perp_dist = distance * cos(ca);
	if (ca < 0)
		ca += 2 * M_PI;
	else if (ca > 2 * M_PI)
		ca -= 2 * M_PI;
	perp_dist = fabs(perp_dist);
	if (data->player.side == EAST || data->player.side == WEST)
		data->player.wall_x = data->player.y + c->ray_y * perp_dist;
	else
		data->player.wall_x = data->player.x + c->ray_x * perp_dist;
	data->player.wall_x -= floorf(data->player.wall_x);
	return (perp_dist);
}

double	len_find(t_parsing_result *data, double angle)
{
	t_calculation	c;

	initiate_calculation(angle, data, &c);
	while (c.hit == 0)
	{
		if (c.side_x < c.side_y)
		{
			c.side_x += c.delta_x;
			c.map_x += c.side_x;
			data->player.side = 0 + (c.side_x + 1);
		}
		else
		{
			c.side_y += c.delta_y;
			c.map_y += c.side_y;
			data->player.side = 1 + (1 + c.side_y);
		}
		if (data->map[c.map_y][c.map_x] == '1')
			c.hit = 1;
	}
	return (distance(angle, data, &c));
}

void	draw_3d(t_parsing_result *data)
{
	int		a;
	double	i;

	a = 0;
	i = -0.3;
	while (i < 0.3)
	{
		data->player.ray = len_find(data, data->player.pa + i);
		walls(data, a);
		i += 0.0006;
		a++;
	}
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
