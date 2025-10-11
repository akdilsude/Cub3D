/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil < sakdil@student.42istanbul.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:24:14 by sakdil            #+#    #+#             */
/*   Updated: 2025/10/11 14:54:22 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void name_control(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.')
			i++;
		else
			break;
	}
	if ((str[i] == '.' && str[i - 1] == '/') || (ft_strcmp(str + i, ".cub") != 0))
	{
		printf("Error\nInvalid map file extension.\n");
		// free_exit(list);
	}
}

int	line_len(char *str)
{
	int	n;

	n = ft_strlen(str);
	if (n > 0 && str[n - 1] == '\n')
		n--;
	return (n);
}

void	check_zero(char **lines, t_game *game)
{
	int		y;
	int		x;
	int		cy_len;
	char	c;

	y = 0;
	while (y < game->y)
	{
		cy_len = line_len(lines[game->map_start + y]);
		x = 0;
		while (x < cy_len)
		{
			c = lines[game->map_start + y][x];
			if (c == '0' || check_nsew(c))
			{
		/* ÜST KONTROLÜ */
				if (y == 0
					|| x >= line_len(lines[game->map_start + y - 1])
					|| lines[game->map_start + y - 1][x] == ' ' )
				{
					printf("Error\nMap not closed (above).\n");
					free_error_exit(game);
				}

		/* ALT KONTROLÜ */
				if (y == game->y - 1
					|| x >= line_len(lines[game->map_start + y + 1])
					|| lines[game->map_start + y + 1][x] == ' ')
				{
					printf("Error\nMap not closed (below).\n");
					free_error_exit(game);
				}

		/* SOL KONTROLÜ */
				if (x == 0 || lines[game->map_start + y][x - 1] == ' ')
				{
					printf("Error\nMap not closed (left).\n");
					free_error_exit(game);
				}

		/* SAĞ KONTROLÜ */
				if (x + 1 >= cy_len || lines[game->map_start + y][x + 1] == ' ')
				{
					printf("Error\nMap not closed (right).\n");
					free_error_exit(game);
				}
			}
			x++;
		}
		y++;
	}
}

