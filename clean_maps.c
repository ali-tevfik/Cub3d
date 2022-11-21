#include "cub3d.h"


void clean_maps(t_parsing_result *data)
{
	
    if (data->two_D.img_ptr)
	{
	mlx_destroy_image(data->mlx, data->two_D.img_ptr);
	}
			data->two_D.img_ptr = mlx_new_image(data->mlx, 1000,1000);
	data->two_D.address = mlx_get_data_addr(data->two_D.img_ptr,
			&data->two_D.bits_per_pixel,
			&data->two_D.line_size, &data->two_D.endian);
}