/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_gamestate.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: yuliia <yuliia@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 19:50:46 by yuliia        #+#    #+#                 */
/*   Updated: 2022/11/21 12:59:41 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_GAMESTATE_H
# define FORM_GAMESTATE_H

# include "error_handling.h"
# include "initiate_data.h"
# include "initiate_map_size.h"

typedef struct  s_plr
{
	double x;
	double y;
	int x_view_direction;
	int y_view_direction;
	double x_camera;
	double y_camera;
	double ray[750];
	double pa;
}               t_plr;

typedef struct  s_game_state
{
	t_map_size	map_size;
	t_data		data;
	t_plr		player;
	char		**map;
}               t_game_state;

typedef struct s_img
{
	void	*img_ptr;
	char	*address;
	int		bits_per_pixel;
	int		line_size;
	int		len_height;
	int		img_width;
	int		endian;
}			t_img;



typedef struct  s_parsing_result
{
	//map
	char	**map;
	
	
	//map sizes
	int len_rows; // - total rows number
	int len_cols; // - longest column size
	
	//floor and seiling collors
	unsigned int rgb_floor;
	unsigned int rgb_ceiling;
	
	//texture opened file descriptors
	int fd_no;
	int fd_so;
	int fd_ea;
	int fd_we;

	//ali added screen data
	t_img	two_D;
	t_img	game;
	void	*mlx;
	void	*win;	
	
	//player section, also can be in player structure
	t_plr player;// - struct
	// int player_x;
	// int player_y;
	// int x_view_direction;
	// int y_view_direction;
	// double x_camera;
	// double y_camera;
	// int pa; // not initialized
}               t_parsing_result;

t_parsing_result parsing(const char **argv, int argc);

# endif /* form_gamestate_h */
