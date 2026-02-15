/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segunes <segunes@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 20:00:10 by sakdil            #+#    #+#             */
/*   Updated: 2026/02/16 01:30:13 by segunes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	read_file(int fd, t_game *game, char ***lines)
{
	char	*line;
	int		count;

	count = 0;
	*lines = malloc(sizeof(char *) * 10000);
	if (!(*lines))
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		(*lines)[count] = line;
		count++;
	}
	(*lines)[count] = NULL;
	close(fd);
	game->line_count = count;
	if (count == 0)
	{
		printf("Error\nEmpty file.\n");
		return (-1);
	}
	return (0);
}

static void	error_msg_player(int count, t_game *game)
{
	if (count != 1)
	{
		if (count == 0)
		{
			printf("Error\nNo player start (N/S/W/E) found.\n");
			cleanup(game);
			exit(1);
		}
		else
		{
			printf("Error\nMultiple player starts (N/S/W/E) found.\n");
			cleanup(game);
			exit(1);
		}
	}
}

static void	player_is_one(char **line, t_game *game)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = game->map_start;
	while (y < game->line_count)
	{
		x = 0;
		while (line[y][x])
		{
			if (line[y][x] == 'N' || line[y][x] == 'S'
					|| line[y][x] == 'W' || line[y][x] == 'E')
			{
				count++;
				game->player_x = x;
				game->player_y = y - game->map_start;
				game->player_direc = line[y][x];
			}
			x++;
		}
		y++;
	}
	error_msg_player(count,game);
	find_vector(game);
}

static void	process_map(char **lines, t_game *game)
{
	game->map_start = control_identifier(lines, game);
	if (game->map_start < 0)
	{
		cleanup(game);
		exit(1);
	}
	check_map_end(lines, game);
	tabs_in_map(lines, game);
	empty_line_inside_map(lines, game);
	player_is_one(lines, game);
	check_top_walls(lines, game);
	check_bottom_walls(lines, game);
	check_side_walls(lines, game);
	check_zero(lines, game);
	check_map(lines, game);
	game->map = build_map(lines, game);
}

void	open_map(char *argv, t_game *game)
{
	int		fd;
	char	**lines;

	name_control(argv,game);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCannot open map file.\n");
		cleanup(game);
		exit(1);
	}
	if (read_file(fd, game, &lines) == -1)
	{
		if (game->line_count == 0)
		{
			cleanup(game);
			exit(1);
		}
		return ;
	}
	game->tmp_lines = lines;
	process_map(lines, game);
	free_array(game->tmp_lines);
	// double free olmasına sebebiyet veriyor free_lines(lines);
	game->tmp_lines = NULL;
}
