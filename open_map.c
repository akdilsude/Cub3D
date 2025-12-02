/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 20:00:10 by sakdil            #+#    #+#             */
/*   Updated: 2025/12/02 11:59:04 by sakdil           ###   ########.fr       */
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
		free(*lines);
		printf("Error\nEmpty file\n");
		return (-1);
	}
	return (0);
}

static void error_msg_player(int count, t_game *game)
{
	if (count != 1)
	{
		if (count == 0)
		{
			printf("Error\nNo player start (N/S/W/E) found.\n");
			free_error_exit(game);
		}
		else
		{
			printf("Error\nMultiple player starts (N/S/W/E) found.\n");
			free_error_exit(game);
		}
	}
}

static void	find_vector(t_game *game)
{
	if (game->player_direc == 'N')
	{
		game->vec_x = 0;
		game->vec_y = -1;
	}
	else if (game->player_direc == 'S')
	{
		game->vec_x = 0;
		game->vec_y = 1;
	}
	else if (game->player_direc == 'W')
	{
		game->vec_x = -1;
		game->vec_y = 0;
	}
	else if (game->player_direc == 'E')
	{
		game->vec_x = 1;
		game->vec_y = 0;
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
			if (line[y][x] == 'N' || line[y][x] == 'S' || line[y][x] == 'W' || line[y][x] == 'E')
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
	error_msg_player(count, game);
	find_vector(game); //zaten error_msg'de exit le çıkıyor ancak yine de kontrol et en son!
}

static void	process_map(char **lines, t_game *game)
{
	game->map_start = control_identifier(lines, game);
	if (game->map_start < 0)
	{
		return;
		// double_free(lines);
		// free_exit(list);
	}
	tabs_in_map(lines, game); 
	check_map_end(lines, game);
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

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCannot open map file.\n");
		free_error_exit(game);
	}
	if (read_file(fd, game, &lines) == -1)
	{
		if (game->line_count == 0)
			free_error_exit(game);
		return ;
	}
	process_map(lines, game);
}
