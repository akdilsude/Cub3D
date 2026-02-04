/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:46:26 by sakdil            #+#    #+#             */
/*   Updated: 2026/02/04 23:42:55 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	continue_side_walls(char **lines, t_game *game, int y)
{
	int		len;
	int		i;
	char	*row;

	i = 0;
	row = lines[game->map_start + y];
	len = line_len(row);
	while (i < len && row[i] == ' ')
		i++;
	while (len > 0 && row[len - 1] == ' ')
		len--;
	if (i < len)
	{
		if (i < len)
		{
			validate_wall(game, y, row[i], "Left");
			validate_wall(game, y, row[len - 1], "Right");
		}
	}
}

void	check_side_walls(char **lines, t_game *game)
{
	int	y;

	y = 1;
	while (y < game->y - 1)
	{
		continue_side_walls(lines, game, y);
		y++;
	}
}

static void	error_check_map(char c, t_game *game)
{
	if (c == '\t')
	{
		printf("Error\nFound tab on the map\n");
		cleanup(game);
		exit(1);
	}
	if (!is_map_char(c))
	{
		printf("Error\nInvalid character '%c'.\n", c);
		cleanup(game);
		exit(1);
	}
}

void	check_map(char **lines, t_game *game)
{
	int		y;
	int		x;
	int		len;
	char	c;

	y = 0;
	while (y < game->y)
	{
		x = 0;
		len = line_len(lines[game->map_start + y]);
		while (x < len)
		{
			c = lines[game->map_start + y][x];
			error_check_map(c, game);
			x++;
		}
		y++;
	}
}

char	**build_map(char **line, t_game *game)
{
	int	y;

	y = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->y + 1));
	if (!game->map)
	{
		printf("Error\nMalloc failed for map array.\n");
		cleanup(game);
		exit(1);
	}
	while (y < game->y)
	{
		game->map[y] = ft_strdup(line[game->map_start + y]);
		if (!game->map[y])
		{
			printf("Error\nMalloc failed for map line.\n");
			cleanup(game);
			exit(1);
		}
		y++;
	}
	game->map[y] = NULL;
	return (game->map);
}
