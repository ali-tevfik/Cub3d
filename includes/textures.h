/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliia <yuliia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:51:15 by yuliia            #+#    #+#             */
/*   Updated: 2022/11/23 18:04:10 by yuliia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "initiate_data.h"

int	textures_collect(char *s, t_data *data);
const char	*collect_path(const char *str, const char *extention);

# endif /* textures_h */
