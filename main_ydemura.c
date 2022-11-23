/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ydemura.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliia <yuliia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:52:41 by yuliia            #+#    #+#             */
/*   Updated: 2022/11/23 17:59:50 by yuliia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_gamestate.h"
#include <stdlib.h>
#include <unistd.h>

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
	}
	free(array);
}


int	main(int argc, const char *argv[])
{
	t_parsing_result	parsing_result;

	parsing_result = parsing(argv, argc);
	
	//do your tghing here :)
	return (0);
}
