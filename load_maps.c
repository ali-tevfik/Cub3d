#include "cub3d.h"

t_parsing_result	*maps_load(t_parsing_result *data)
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
			else if (data->map[x][a] == '1' || data->map[x][a] == 'P')
			{
				create_elemntry(data, a, x, 0X4C1130);
			}
			a++;
		}
		x++;
	}
	create_player(data, (int) data->player.x, (int) data->player.y);

	return (data);
}

