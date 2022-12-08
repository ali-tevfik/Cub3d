/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw3D.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydemura <ydemura@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/08 18:11:35 by ydemura       #+#    #+#                 */
/*   Updated: 2022/12/08 21:21:33 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "includes/textures.h"

static int	get_rgba(mlx_texture_t *texture, int x, int y)
{
	int	r;
	int	g;
	int	b;
	int	a;
	r = texture->pixels[y * texture->width * 4 + (x * 4)];
	g = texture->pixels[y * texture->width * 4 + (x * 4) + 1];
	b = texture->pixels[y * texture->width * 4 + (x * 4) + 2];
	a = texture->pixels[y * texture->width * 4 + (x * 4) + 3];
    return (r << 24 | g << 16 | b << 8 | a);
}

// unsigned int	create_colour(unsigned char r, unsigned char g, unsigned char b
// 		, unsigned char a)
// {
// 	return ((unsigned int)(a << 24 | b << 16 | g << 8 | r));
// }

void	walls(t_parsing_result *data, int i)
{
	int	y;

	double height;
	// int start_wall= 0;
	int start = 0;
	int finish = SCREENHEIGHT;
	int half = (finish - start) / 2;
	int top, bottom;
	int x;
	unsigned int color = 0;

	height = SCREENHEIGHT / data->player.ray;
	
	x = 0;
	double text_start;
	mlx_texture_t *tex = data->texture[data->player.side];
	if (height >= data->img->height)
	{
		top = 0;
		bottom = data->img->height - 1;
		text_start = (((1 - (1.0 * data->img->height / height)) / 2.0)
				* tex->height);
	}
	else
	{
		top = (data->img->height - height) / 2;
		bottom = (data->img->height + height) / 2;
		text_start = 0.0;
	}
	double step = 1.0 * tex->height/ height;
	
	y = start;
	while (y < finish)
	{
		// up
		if (y < half)
			mlx_put_pixel(data->img, i, y, data->rgb_floor);
		else // down
			mlx_put_pixel(data->img, i, y, data->rgb_ceiling);
		y++;

	}
	

	// up walls
	while (x < bottom - top)
	{
	
		if (data->player.side == EAST || data->player.side == NORTH)
			color = get_rgba(tex,
					((unsigned int)((1.0 - data->player.wall_x) * tex->width)),
					((unsigned int)(text_start + x * step)));
		else
			color = get_rgba(tex,
					((unsigned int)((data->player.wall_x) * tex->width)),
					((unsigned int)(text_start + x * step)));
		mlx_put_pixel(data->img, i, x + top, color);
		x++;
	}
    i++;
}
