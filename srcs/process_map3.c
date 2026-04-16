/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:35:26 by sakdil            #+#    #+#             */
/*   Updated: 2026/02/22 16:08:42 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	continue_check_surround(char **lines, int x, int y, t_game *game)
{
	if (x == 0 || lines[game->map_start + y][x - 1] == ' ')
	{
		printf("Error\nMap not closed (left).\n");
		cleanup(game);
		exit(1);
	}
	if (x + 1 >= game->curr_len || lines[game->map_start + y][x + 1] == ' ')
	{
		printf("Error\nMap not closed (right).\n");
		cleanup(game);
		exit(1);
	}
}

static void	check_surround(char **lines, int x, int y, t_game *game)
{
	game->curr_len = line_len(lines[game->map_start + y]);
	if (y == 0 || x >= line_len(lines[game->map_start + y - 1])
		|| lines[game->map_start + y - 1][x] == ' ' )
	{
		printf("Error\nMap not closed (above).\n");
		cleanup(game);
		exit(1);
	}
	if (y == game->y - 1 || x >= line_len(lines[game->map_start + y + 1])
		|| lines[game->map_start + y + 1][x] == ' ')
	{
		printf("Error\nMap not closed (below).\n");
		cleanup(game);
		exit(1);
	}
	continue_check_surround(lines, x, y, game);
}

void	check_zero(char **lines, t_game *game)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < game->y)
	{
		x = 0;
		game->curr_len = line_len(lines[game->map_start + y]);
		while (x < game->curr_len)
		{
			c = lines[game->map_start + y][x];
			if (c == '0' || check_nsew(c))
				check_surround(lines, x, y, game);
			x++;
		}
		y++;
	}
}

static void	continue_find_vector(t_game *game)
{
	if (game->player_direc == 'W')
	{
		game->vec_x = -1;
		game->vec_y = 0;
		game->plane_x = 0;
		game->plane_y = 0.66;
	}
	else if (game->player_direc == 'E')
	{
		game->vec_x = 1;
		game->vec_y = 0;
		game->plane_x = 0;
		game->plane_y = -0.66;
	}
}

void	find_vector(t_game *game)
{
	if (game->player_direc == 'N')
	{
		game->vec_x = 0;
		game->vec_y = -1;
		game->plane_x = 0.66;
		game->plane_y = 0;
	}
	else if (game->player_direc == 'S')
	{
		game->vec_x = 0;
		game->vec_y = 1;
		game->plane_x = -0.66;
		game->plane_y = 0;
	}
	else
		continue_find_vector(game);
}
