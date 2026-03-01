/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:18:20 by sakdil            #+#    #+#             */
/*   Updated: 2026/03/01 10:52:16 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*clean_color_line(char *line)
{
	char	*trimmed;
	char	*clean;
	int		i;
	int		j;

	trimmed = ft_strtrim(line + 1, " \t\n");
	if (!trimmed)
		return (NULL);
	clean = malloc(ft_strlen(trimmed) + 1);
	if (!clean)
		return (free(trimmed), NULL);
	i = 0;
	j = 0;
	while (trimmed[i])
	{
		if (trimmed[i] != ' ' && trimmed[i] != '\t')
			clean[j++] = trimmed[i++];
		else
			i++;
	}
	clean[j] = '\0';
	free(trimmed);
	return (clean);
}

static void	assign_colors(t_game *game, char **rgb, char type)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (type == 'F')
	{
		game->floor_r = r;
		game->floor_g = g;
		game->floor_b = b;
	}
	else if (type == 'C')
	{
		game->ceiling_r = r;
		game->ceiling_g = g;
		game->ceiling_b = b;
	}
}

static int	check_color_number(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i] != NULL)
	{
		j = 0;
		while (rgb[i][j] != '\0')
		{
			if (!ft_isdigit(rgb[i][j]))
			{
				printf("Error\nRGB values must contain only digit.\n");
				return (-1);
			}
			j++;
		}
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			printf("Error\nRGB color value out of range (0-255).\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	continue_check_color(t_game *game, char *clean_str, char *line)
{
	int		count;
	char	**rgb;

	count = 0;
	rgb = ft_split(clean_str, ',');
	free(clean_str);
	if (!rgb)
		return (printf("Error\nSplit failed.\n"), -1);
	while (rgb[count])
		count++;
	if (count != 3)
	{
		printf("Error\nInvalid color format (must be 3 values).\n");
		free_tab(rgb);
		return (-1);
	}
	if (check_color_number(rgb) == -1)
		return (free_tab(rgb), -1);
	assign_colors(game, rgb, line[0]);
	free_tab(rgb);
	return (0);
}

int	check_color(char *line, t_game *game)
{
	char	*clean_str;
	int		i;
	int		count_comma;

	i = 0;
	count_comma = 0;
	clean_str = clean_color_line(line);
	if (!clean_str)
		return (printf("Error\nMalloc failed.\n"), -1);
	while (clean_str[i] != '\0')
	{
		if (clean_str[i] == ',')
			count_comma += 1;
		i++;
	}
	if (count_comma != 2)
	{
		printf("Error\nInvalid comma count in RGB.\n");
		free(clean_str);
		cleanup(game);
		exit(1);
	}
	return (continue_check_color(game, clean_str, line));
}
