/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:18:20 by sakdil            #+#    #+#             */
/*   Updated: 2026/02/04 22:19:46 by sakdil           ###   ########.fr       */
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

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
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
				printf("invalid character");
				return (-1);
			}
			j++;
		}
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			printf("invalid number");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	check_color(char *line, t_game *game)
{
	char	*clean_str;
	char	**rgb;
	int		count;

	clean_str = clean_color_line(line);
	if (!clean_str)
		return (printf("Error\nMalloc failed\n"), -1);
	rgb = ft_split(clean_str, ',');
	free(clean_str);
	if (!rgb)
		return (printf("Error\nSplit failed\n"), -1);
	count = 0;
	while (rgb[count])
		count++;
	if (count != 3 || check_color_number(rgb) == -1)
	{
		printf("Error\nInvalid color format\n");
		free_tab(rgb);
		return (-1);
	}
	assign_colors(game, rgb, line[0]);
	free_tab(rgb);
	return (0);
}
