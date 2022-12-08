/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemura <ydemura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:43:25 by ydemura           #+#    #+#             */
/*   Updated: 2022/12/08 17:35:42 by ydemura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_MOVES_H
# define KEY_MOVES_H

# include "includes/parsing_gamestate.h"

void	key_left(t_parsing_result *data);
void	key_right(t_parsing_result *data);
void	key_a(t_parsing_result *data);
void	key_s(t_parsing_result *data);
void	key_d(t_parsing_result *data);

#endif