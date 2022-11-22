#include "cub3d.h"

t_parsing_result	*maps_load(t_parsing_result *data, int where)
{
	int	a;
	int	x;

	x = 0;
	while (data->map[x])
	{
		a = 0;
		while (data->map[x][a])
		{
			if (data->map[x][a] == '0')
				create_elemntry(data, a, x, 0XFFFFFF);
			else if (data->map[x][a] == '1')
			{
				create_elemntry(data, a, x, 0X4C1130);
			}
			
			else if (data->map[x][a] == 'P' )
			{
				create_elemntry(data, a, x, 0XFFFFFF);
				if (where == 0)
				{				
					data->player.y = x * 50;
					data->player.x  = a * 50; ;
					data->player.pa = 2 * M_PI;
					data->player.x_camera = cos(data->player.pa) * 5;
					data->player.y_camera = sin(data->player.pa) * 5;
				}

			}
			a++;
		}
		x++;
	}
	create_player(data, (int) data->player.x, (int) data->player.y);

	return (data);
}

