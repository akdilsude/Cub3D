/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segunes <segunes@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:24:14 by sakdil            #+#    #+#             */
/*   Updated: 2025/10/10 16:45:32 by segunes          ###   ########.fr       */
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

int check_nsew(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (1);
	return (0);
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

void	check_walls(char **lines, t_game *game)
{
	int		x;
	int		y;
	int		len;
	int		i;
	char	c;
	char *row;

	y = 0;
	x = 0;
	len = line_len(lines[game->map_start + y]);
	while (x < len)
	{
		c = lines[game->map_start + y][x];
		if (c == '0' || check_nsew(c))
		{
			printf("Error\nTop edge not closed at x=%d\n", x + 1);
			free_error_exit(game);
		}
		x++;
	}
	y = game->y - 1;
	x = 0;
	len = line_len(lines[game->map_start + y]);
	while (x < len)
	{
		c = lines[game->map_start + y][x];
		if (c == '0' || check_nsew(c))
		{
			printf("Error\nBottom edge not closed at x=%d\n", x + 1);
			free_error_exit(game);
		}
		x++;
	}
	y = 1;
	while (y < game->y - 1)
	{
		row = lines[game->map_start + y];
		len = line_len(row);
		i = 0;
		while (i < len && row[i] == ' ')
			i++;
		while (len > 0 && row[len - 1] == ' ')
			len--;
		if (i < len)
		{
			if (row[i] != '1')
			{
				printf("Error\nLeft edge not closed at y=%d\n", y + 1);
				free_error_exit(game);
			}
			if (row[len - 1] != '1')
			{
				printf("Error\nRight edge not closed at y=%d\n", y + 1);
				free_error_exit(game);
			}
		}
		y++;
	}
}


static int	is_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || c == '\n'
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
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
			if (c == '\t')
			{
				printf("Error\nTab var\n");
				free_error_exit(game);
			}
			if (!is_map_char(c))
			{
				printf("Error\nInvalid character '%c' at (row=%d, col=%d).\n",
					c, y + 1, x + 1);
				free_error_exit(game);
			}
			x++;
		}
		y++;
	}
}
