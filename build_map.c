/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segunes <segunes@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:59:12 by sakdil            #+#    #+#             */
/*   Updated: 2025/09/29 14:07:57 by segunes          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

char	**build_map(char **line, t_game * game)
{
	int	y;

	y = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->y + 1));
	if (!game->map)
	{
		printf("Error\nFailed map.\n");
		//free_exit(game);
	}
	while (y < game->y)
	{
		game->map[y] = ft_strdup(line[game->map_start + y]);
		if (!game->map[y])
		{
			printf("Error\nFailed map.\n");
			//double_free(game->map);
			//free_exit(game);
		}
		y++;
	}
	game->map[y] = NULL;
	return (game->map);
}
