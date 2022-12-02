#include "cub3d.h"


unsigned int	grading_colour(unsigned int colour, double percentage)
{
	t_rgba	color;

	color.rgba = colour;
	if (percentage < 1.0)
	{
		color.r = (unsigned char)((percentage) * color.r);
		color.g = (unsigned char)((percentage) * color.g);
		color.b = (unsigned char)((percentage) * color.b);
	}
	return (color.rgba);
}

//will get the colour on a specific point on the texture
unsigned int	get_colour_png(mlx_texture_t *png, unsigned int x
					, unsigned int y)
{
	unsigned int	offset;
	unsigned char	*dst;

	if (x < png->width && y < png->height)
	{
		offset = y * (png->width * 4) + x * 4;
		dst = png->pixels + offset;
		return (*(unsigned int *) dst);
	}
	return (0X00000000);
}


unsigned int	get_color(mlx_texture_t* texture, int x, int y, t_parsing_result *data, double wall_height)
{
    unsigned int colour;

    // colour = get_colour_png(vars->wall,
					// (unsigned int)((1.0 - result->hitpos) * vars->wall->width),
					// (unsigned int)(vars->tex_start + y * vars->step));
    colour = get_colour_png(texture,
					(unsigned int) (x + 2),
					(unsigned int)(y + 2));
    colour = grading_colour(colour, 1.0  * wall_height / data->img->height);
    return colour;
}

// 450-10000
void walls(t_parsing_result *data, int i)
{
    int y;

    double height;
    int start = 0;
    int finish = 1000;
    int half = (finish - start) / 2;
    double half_height;
    int x;

    unsigned int color = 0;
//    ("info for textured height %d pixel %s witdh %u byte %d\n",data->texture[0]->height,data->texture[0]->pixels,data->texture[0]->width, data->texture[0]->bytes_per_pixel);
    height = 1000 / data->player.ray;
    if (height > 1000)
        height = 999;
    if (height < 0)
        height = 0;
    half_height = height / 2;
    y = start;
    while (y < finish)
    {
        // up
        if (y < half)
            mlx_put_pixel(data->img, i, y, 0x00A0522D);
        else // down
            mlx_put_pixel(data->img, i, y, 0x00A0522D);
        y++;
    }
    x = 0;

    // up walls
    while (half_height > x && half - x < finish && half - x > start)
    {
        color = get_color(data->texture[0], i, half-x, data, height);
        mlx_put_pixel(data->img, i, half - x, color);
        x++;
    }
    x = 0;
    // down walls
    while (height > half_height && half + x < finish && half + x > start)
    {
        color = get_color(data->texture[0], i, half+x, data, height);
        mlx_put_pixel(data->img, i, half + x, color);
        half_height++;
        x++;
    }

    i++;
}
