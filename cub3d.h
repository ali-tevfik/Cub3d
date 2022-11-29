/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 16:00:13 by adoner        #+#    #+#                 */
/*   Updated: 2022/11/25 17:06:17 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_HPP
# define CUB3D_HPP
# include "minilibx_opengl/include/MLX42/MLX42.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
#include <math.h>
# include "libft/libft.h"
#include "includes/parsing_gamestate.h"

#define screenWidth 1000
#define screenHeight 1000


# define TRUE 1
# define FALSE 0
# define PI 3.14159265359
# define BLACK 0X000000
# define BLAUW 0X0000FF
# define RED 0X00FF00


int check_up(t_parsing_result *data); 	
void    click_button(mlx_key_data_t keydata,void *info);
int check_right(t_parsing_result *data);
void create_angel(t_parsing_result *data, int wall_x, int wall_y);
int check_left(t_parsing_result *data);
int check_down(t_parsing_result *data);
t_parsing_result	*maps_load(t_parsing_result *data);
int	close_clik(t_parsing_result *data);
// void	mlx_put_pixel(t_img *data, int x, int y, int color);
void create_player(t_parsing_result *data, int player_x, int player_y);
void draw_angle(t_parsing_result *data, double angle, int line_lenght, long color);
void	check_position(t_parsing_result *data);
// void clean_maps(t_parsing_result *data);
double draw_ray(t_parsing_result *data, double angle, long color);
int check_walls(double ray_x, double ray_y, t_parsing_result *data);
void	create_win(t_parsing_result *data);
void create_elemntry(t_parsing_result *data, int wall_x, int wall_y, int color);
double find_ray_len(double x, double y);
void draw3Dstart(t_parsing_result *data);
void walls(t_parsing_result *data, int i);
void	start_draw(t_parsing_result *data);
double len_find(t_parsing_result *data, double angle);
void	move(t_parsing_result *data);
void draw_3d(t_parsing_result *data);
# endif