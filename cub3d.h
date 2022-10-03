/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 16:00:13 by adoner        #+#    #+#                 */
/*   Updated: 2022/10/03 16:54:26 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_HPP
# define CUB3D_HPP
# include "minilibx_opengl/mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

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

typedef struct s_direction
{
    char	*NO;
    char	*SO;
    char	*WE;
    char	*EA;
}			t_direction;

typedef struct s_color
{
    char	*F;
    char 	*C;
}				t_color;

typedef struct s_maps
{
    char		**maps;
    int			len;
    int			line;
    t_color		color;
    t_direction	direction;
}               t_map;


# endif