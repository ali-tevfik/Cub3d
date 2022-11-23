/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 16:00:13 by adoner        #+#    #+#                 */
/*   Updated: 2022/11/23 16:43:09 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_HPP
# define CUB3D_HPP
# include "minilibx_opengl/mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
#include <math.h>
# include "libft/libft.h"
#include "includes/parsing_gamestate.h"

# define ESC 53
# define UP 126
# define RIGHT 124
# define DOWN 125
# define LEFT 123
# define W 13
# define D 2
# define S 1
# define A 0
# define TRUE 1
# define FALSE 0
# define PI 3.14159265359
# define BLACK 0X000000
# define BLAUW 0X0000FF
# define RED 0X00FF00
// typedef struct s_img
// {
// 	void	*img_ptr;
// 	char	*address;
// 	int		bits_per_pixel;
// 	int		line_size;
// 	int		len_height;
// 	int		img_width;
// 	int		endian;
// }			t_img;



// typedef struct s_plr
// {
// 	double x;
// 	double y;
// 	double ray[750];
// 	double x_camera;
// 	double y_camera;
// 	double pa;
// }				t_plr;

// typedef struct s_data
// {
// 	void	*mlx;
// 	void	*win;
// 	t_img	two_D;
// 	t_img	game;
// 	t_plr	player;
// 	int		len_cols;
// 	int		len_rows;
// 	char	**maps;
// }			t_parsing_result;


int check_up(t_parsing_result *data);
int	click_button(int keycode, t_parsing_result *data);
int check_right(t_parsing_result *data);
void create_angel(t_parsing_result *data, int wall_x, int wall_y);
int check_left(t_parsing_result *data);
int check_down(t_parsing_result *data);
t_parsing_result	*maps_load(t_parsing_result *data, int where);
int	close_clik(t_parsing_result *data);
void	my_mlx_pixel_put(t_img *img, int x, int y, unsigned int colour);
void create_player(t_parsing_result *data, int player_x, int player_y);
void draw_angle(t_parsing_result *data, double angle, int line_lenght, long color);
void	check_position(t_parsing_result *data);
void clean_maps(t_parsing_result *data);
double draw_ray(t_parsing_result *data, double angle, long color);
int check_walls(double ray_x, double ray_y, t_parsing_result *data);
void	create_win(t_parsing_result *data);
void create_elemntry(t_parsing_result *data, int wall_x, int wall_y, int color);
double find_ray_len(double x, double y);
int	my_mlx_pixel_get(t_img *img, int x, int y);
void draw3Dstart(t_parsing_result *data);
void walls(t_parsing_result *data, int i);
void	start_draw( t_parsing_result *data);
double len_find(t_parsing_result *data, double angle);
void	move(t_parsing_result *data, int keycode);
void draw_3d(t_parsing_result *data);
# endif