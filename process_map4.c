/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:00:44 by sakdil            #+#    #+#             */
/*   Updated: 2026/02/22 16:02:08 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	name_control(char *str, t_game *list)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.')
			i++;
		else
			break ;
	}
	if ((str[i] == '.' && str[i - 1] == '/')
		|| (ft_strcmp(str + i, ".cub") != 0))
	{
		printf("Error\nInvalid map file extension.\n");
		cleanup(list);
		exit(1);
	}
}
