/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:13:21 by sakdil            #+#    #+#             */
/*   Updated: 2026/02/28 14:44:40 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_flood(char **map, int x, int y, int max_y)
{
	if (x < 0 || y < 0 || y >= max_y || x >= line_len(map[y]))
		return ;
	if (map[y][x] == ' ')
		return ;
	if (map[y][x] == 'F' || map[y][x] == 'A')
		return ;
	if (map[y][x] == '1')
		map[y][x] = 'A';
	else if (map[y][x] == '0' || check_nsew(map[y][x]))
		map[y][x] = 'F';
	else
		return ;
	fill_flood(map, x + 1, y, max_y);
	fill_flood(map, x - 1, y, max_y);
	fill_flood(map, x, y + 1, max_y);
	fill_flood(map, x, y - 1, max_y);
}

void	check_mult_maps(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	fill_flood(game->map, (int)game->player_x, (int)game->player_y, game->y);
	while (++y < game->y)
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '0' || check_nsew(game->map[y][x]))
			{
				printf("Error\nMultiple maps.\n");
				cleanup(game);
				exit(1);
			}
			if (game->map[y][x] == 'F')
				game->map[y][x] = '0';
			else if (game->map[y][x] == 'A')
				game->map[y][x] = '1';
		}
	}
	game->map[(int)game->player_y][(int)game->player_x] = game->player_direc;
}
