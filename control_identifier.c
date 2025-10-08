/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_identifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil < sakdil@student.42istanbul.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:44:09 by sakdil            #+#    #+#             */
/*   Updated: 2025/10/08 19:58:09 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	handle_direct(char *line, t_game *game)
{
	if (!ft_strncmp(line, "NO", 2) && (line[2] == ' ' || line[2] == '\t'))
	{
		if (handle_no(line, game) == false)
			return (-1);
	}
	else if (!ft_strncmp(line, "SO", 2) && (line[2] == ' ' || line[2] == '\t'))
	{
		if (handle_so(line, game) == false)
			return (-1);
	}
	else if (!ft_strncmp(line, "WE", 2) && (line[2] == ' ' || line[2] == '\t'))
	{
		if (handle_we(line, game) == false)
			return (-1);
	}
	else if (!ft_strncmp(line, "EA", 2) && (line[2] == ' ' || line[2] == '\t'))
	{
		if (handle_ea(line, game) == false)
			return (-1);
	}
	else
		return (-1); //Geçersiz format
	return (1);
}

static int	handle_color(char *line, t_game *game)
{
	if (line[0] == 'F' && (line[1] == ' ' || line[1] == '\t'))
	{
		if (handle_floor(game) == false)
			return (-1);
		if (check_color(line, game) == -1)
			return (-1);
	}
	else if (line[0] == 'C' && (line[1] == ' ' || line[1] == '\t'))
	{
		if (handle_ceiling(game) == false)
			return (-1);
		if (check_color(line, game) == -1)
			return (-1);
	}
	else
		return (-1); //Geçersiz format
	return (1);
}

static int	line_identifier(char **lines, int *i, t_game *game)
{
	int	result;

	if (!ft_strncmp(lines[*i], "NO", 2) || !ft_strncmp(lines[*i], "SO", 2)
		|| !ft_strncmp(lines[*i], "WE", 2) || !ft_strncmp(lines[*i], "EA", 2))
		result = handle_direct(lines[*i], game);
	else if (lines[*i][0] == 'F' || lines[*i][0] == 'C')
		result = handle_color(lines[*i], game);
	else
		return (0);
	if (result == -1)
		return (-1); //hata
	(*i)++;
	return (1);
}

static int	validate_map(char **lines, int i, t_game *game)
{
	if (!is_all_set(game))
	{
		//free,
		printf("Error\nConfiguration identifiers (NO, SO, WE, EA, F, C) are missing.\n");
		return (-1);
	}
	while (i < game->line_count && is_only_spaces(lines[i]))
		i++;
	if (i >= game->line_count)
	{
		//free
		printf("Error\nMap not found after setup.\n");
		return (-1);
	}
	return (i);
}

int control_identifier(char **lines, t_game *game)
{
	int	i;
	int	result;

	i = 0;
	start_control_value(game);
	while (i < game->line_count)
	{
		result = line_identifier(lines, i, game);
		if (result == -1)
			return (-1);
		else if (result == 0)
			break ; //identiefer olmayan bir satır var demek
	}
	return (validate_map(lines, i, game));
}
