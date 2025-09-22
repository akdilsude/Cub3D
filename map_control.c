/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:24:14 by sakdil            #+#    #+#             */
/*   Updated: 2025/09/22 19:39:11 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	name_control(char *str, t_game *list)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.')
			i++;
		else
			break ;
	}
	if ((str[i] == '.' && str[i - 1] == '/')
		|| (ft_strcmp(str + i, ".cub") == 1))
	{
		write(1, "Error\nInvalid map file extension.\n", 34);
		free_exit(list);
	}
}

static void start_control_value(t_game *game)
{
	game->control.is_no = 0;
	game->control.is_so = 0;
	game->control.is_we = 0;
	game->control.is_ea = 0;
	game->control.is_floor = 0;
	game->control.is_ceiling = 0;
}

static int is_all_set(t_game *game)
{
	if (!game->control.is_no || !game->control.is_so
		|| !game->control.is_we || !game->control.is_ea
		|| !game->control.is_floor || !game->control.is_ceiling)
		return (1);
	return (0);

}

static int control_identifier(char **lines, int line_count, t_game *game)
{
	int	i;

	i = 0;
	start_control_value(game);
	while (i < line_count)
	{
		if (is_only_spaces(lines[i]))
			i++;
		else if(!ft_strncmp(lines[i], "NO", 3))
		{
			if (handle_no(game, lines[i]) == false)
				return (-1);
			i++;
		}
		else if (!ft_strncmp(lines[i], "SO ", 3))
		{
			if (handle_so(game, lines[i]) == false)
				return (-1);
			i++;
		}
		else if (!ft_strncmp(lines[i], "WE ", 3))
		{
			if (handle_we(game, lines[i]) == false)
				return (-1);
			i++;
		}
		else if (!ft_strncmp(lines[i], "EA ", 3))
		{
			if (handle_ea(game, lines[i]) == false)
				return (-1);
			i++;
		}
		else if (lines[i][0] == 'F' && (lines[i][1] == ' ' || lines[i][1] == '\t'))
		{
			if (handle_floor(game, lines[i]) == false)
				return (-1);
			i++;
		}
		else if (lines[i][0] == 'C' && (lines[i][1] == ' ' || lines[i][1] == '\t'))
		{
			if (handle_ceiling(game, lines[i]) == false)
				return (-1);
			i++;
		}
		else
			break ;
	}
	if (is_all_set(game))
		return (printf("Error\nIdentifiers are missing.\n"), -1);
	if (i >= line_count)
		return (printf("Error\nMap not found.\n"), -1);
	return (i); //mapin başladığı satır = map_start
}

static void	empty_line_control(char **line, int start, int line_count, t_game *game)
{
	while(start < line_count)
	{
		if (line[start] == NULL || is_only_spaces(line[start]))
		{
			printf("Error\nThere is empty space on the map.");
			free_exit(game);
		}
		start++;
	}
}

void	open_map(char *argv, t_game *list)
{
	char	**lines;


	list->fd = open(argv, O_RDONLY);
	if (list->fd < 0)
	{
		write(1, "Error\nCannot open map file.\n", 28);
		free_exit(list);
	}
	list->line_map = ft_get_read(list->fd);
	close(list->fd);
	if (!list->line_map)
	{
		write(1, "Error\nFailed to read map file.\n", 31);
		free_exit(list);
	}
	lines = ft_split(list->line_map, '\n');
	if (!lines || !lines[0])
	{
		write(1, "Error\nEmpty file.\n", 18);
		double_free(lines);
		free_exit(list);
	}
	while (lines[list->line_count])
		list->line_count;
	list->map_start = control_identifier(lines, list->line_count, list);
 	if (list->map_start < 0)
	{
		double_free(lines);
		free_exit(list);
	}
	empty_line_control(lines, list->map_start, list->line_count, list);
	list->y = list->line_count - list->map_start;
	if (list->y <= 0)
	{
		printf("Error\nNo map found (bak).\n");
		free_exit(list);
	}
	list->map = build_map(lines, list);
	if (!list->map)
	{
		printf("Error\nMap data failed.\n");
		double_free(lines);
		free_exit(list);
	}
	//MAP 1 lerle mi çevrili?
	// mapte boşluk tab var mı? olmayan karakter
	
	// map_controller(list);
	// empty_line_control(list);
	// list->map = ft_split(list->line_map, '\n');
	// list->temp = ft_split(list->line_map, '\n');
	// if (!list->map || !list->temp)
	// {
	// 	write(1, "Error\nFailed map data.\n", 23);
	// 	free_exit(list);
	// }
	// continue_open_map(list);
	//Map dosyada en sonda olmalı; map’ten sonra header elemanı yok.
}
