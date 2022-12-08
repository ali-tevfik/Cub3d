/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemura <ydemura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:51:15 by yuliia            #+#    #+#             */
/*   Updated: 2022/12/08 17:43:11 by ydemura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "initiate_data.h"

typedef struct s_textures
{
	unsigned int	top;
	unsigned int	bottom;
	double			step;
	double			wall_height_perc;
	double			tex_start;
    // mlx_texture_t *wall;
}	t_textures;


int			textures_collect(char *s, t_data *data);
const char	*collect_path(const char *str, const char *extention);

#endif /* textures_h */
