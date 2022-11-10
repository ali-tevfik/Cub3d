#include "cub3d.h"


void clean_maps(t_vars *vars)
{
	
    if (vars->two_D.img_ptr)
	{
	mlx_destroy_image(vars->mlx, vars->two_D.img_ptr);
	}
			vars->two_D.img_ptr = mlx_new_image(vars->mlx, 1000,1000);
	vars->two_D.address = mlx_get_data_addr(vars->two_D.img_ptr,
			&vars->two_D.bits_per_pixel,
			&vars->two_D.line_size, &vars->two_D.endian);
}