/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_gamestate.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemura <ydemura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:50:46 by yuliia            #+#    #+#             */
/*   Updated: 2022/12/02 13:25:00 by ydemura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_GAMESTATE_H
# define FORM_GAMESTATE_H

# include "error_handling.h"
# include "initiate_data.h"
# include "initiate_map_size.h"
#include "../minilibx_opengl/include/MLX42/MLX42.h"

typedef union u_rgba
{
	unsigned int	rgba;
	struct {
		unsigned char	r;
		unsigned char	g;
		unsigned char	b;
		unsigned char	a;
	};
}				t_rgba;

typedef struct  s_plr
{
	double x;
	double y;
	int x_view_direction;
	int y_view_direction;
	double game_speed;
	double x_camera;
	double y_camera;
	double ray;
	int hitX;
	int hitY;
	int side;
	double wallX;
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
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct  s_parsing_result
{
	char	**map;
	int len_rows;
	int len_cols;
	unsigned int rgb_floor;
	unsigned int rgb_ceiling;
	char *no;
	char *so;
	char *ea;
	char *we;
	mlx_texture_t *texture[4];
	mlx_image_t	*img;
	mlx_t	*mlx;
	void	*win;	
	t_plr player;
}               t_parsing_result;

t_parsing_result parsing(const char **argv, int argc);

# endif /* form_gamestate_h */
