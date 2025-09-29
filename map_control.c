/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segunes <segunes@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:24:14 by sakdil            #+#    #+#             */
/*   Updated: 2025/09/29 17:24:42 by segunes          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
	if ((str[i] == '.' && str[i - 1] == '/') || (ft_strcmp(str + i, ".cub") == 1))
	{
		write(1, "Error\nInvalid map file extension.\n", 34);
		//free_exit(list);
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
	if (!game->control.is_no || !game->control.is_so || !game->control.is_we || !game->control.is_ea || !game->control.is_floor || !game->control.is_ceiling)
		return (1);
	return (0);
}

static int control_identifier(char **lines, int line_count, t_game *game)
{
	int i;

	i = 0;
	start_control_value(game);
	while (i < line_count)
	{
		if (is_only_spaces(lines[i]))
			i++;
		else if (!ft_strncmp(lines[i], "NO", 3))
		{
			if (handle_no(lines[i], game) == false)
				return (-1);
			i++;
		}
		else if (!ft_strncmp(lines[i], "SO ", 3))
		{
			if (handle_so(lines[i], game) == false)
				return (-1);
			i++;
		}
		else if (!ft_strncmp(lines[i], "WE ", 3))
		{
			if (handle_we(lines[i], game) == false)
				return (-1);
			i++;
		}
		else if (!ft_strncmp(lines[i], "EA ", 3))
		{
			if (handle_ea(lines[i], game) == false)
				return (-1);
			i++;
		}
		else if (lines[i][0] == 'F' && (lines[i][1] == ' ' || lines[i][1] == '\t'))
		{
			if (handle_floor(game) == false)
				return (-1);
			i++;
		}
		else if (lines[i][0] == 'C' && (lines[i][1] == ' ' || lines[i][1] == '\t'))
		{
			if (handle_ceiling(game) == false)
				return (-1);
			i++;
		}
		else
			break;
	}
	if (is_all_set(game))
		return (printf("Error\nIdentifiers are missing.\n"), -1);
	if (i >= line_count)
		return (printf("Error\nMap not found.\n"), -1);
	return (i); // mapin başladığı satır = map_start
}

static void empty_line_control(char **line, int start, int line_count)
{
	while (start < line_count)
	{
		if (line[start] == NULL || is_only_spaces(line[start]))
		{
			printf("Error\nThere is empty space on the map.");
			//free_exit(game);
		}
		start++;
	}
}

static void error_msg_player(int count)
{
	if (count != 1)
	{
		if (count == 0)
			printf("Error\nNo player start (N/S/W/E) found.\n");
		else
			printf("Error\nMultiple player starts (N/S/W/E) found.\n");
		//free_exit(game);
	}
}

static void player_is_one(char **line, t_game *game)
{
	int y;
	int x;
	int len;
	int count;

	count = 0;
	y = game->map_start;
	while (y < game->line_count)
	{
		x = 0;
		len = (int)ft_strlen(line[y]);
		while (x < len)
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
	error_msg_player(count);
}
// YAPILIYOR
static void check_map(char **line, t_game *game)
{
	int x;
	int y;
	int len;

	y = 0;
	while (y < game->y)
	{
		x = 0;
		len = (int)ft_strlen(line[game->map_start + y]);
		while (x < len)
		{
			if (!(line[game->map_start + y][x] == '0' ||
				  line[game->map_start + y][x] == '1' ||
				  line[game->map_start + y][x] == ' ' ||
				  line[game->map_start + y][x] == 'N' ||
				  line[game->map_start + y][x] == 'S' ||
				  line[game->map_start + y][x] == 'W' ||
				  line[game->map_start + y][x] == 'E'))
			{
				printf("Error\nMap contains invalid characters.\n");
				//free_exit(game);
			}
			if (line[game->map_start + y][x] == '0' ||
				line[game->map_start + y][x] == 'N' ||
				line[game->map_start + y][x] == 'S' ||
				line[game->map_start + y][x] == 'W' ||
				line[game->map_start + y][x] == 'E')
			{
				if ((line[game->map_start + y - 1][x] == ' ' ||
					 line[game->map_start + y + 1][x] == ' ' ||
					 line[game->map_start + y][x + 1] == ' ' ||
					 line[game->map_start + y][x - 1] == ' '))

				{
					printf("Error\n");
					
					//free_exit(game);
				}
				if (y == 0 || y == game->y - 1 || x == 0 || x == len - 1)
				{
					printf("Error\n");
					//free_exit(game);
				}
				if (y > 0 && x < (int)ft_strlen(line[game->map_start + y - 1])
					&& line[game->map_start + y - 1][x] == ' ')
					//Eğer ilk satırdaysak (y == 0) yukarıya bakamayız çünkü yukarısı yok O yüzden y > 0 mı diye kontrol ediyoruz.
					//bir yerde y deki karakter uzunlğu daha fazla olabilir ve diyelim ki x ile yukarıya baktık birinde var birinde yok
					// 11111111
					// 111             mesela böyle bir durum için
					//ayrıca satır arasında space varsa sorun değil oyüzden onunda kontrolünü yapıyoruz
				{
					printf("Error\nMap not closed (space above).\n");
					//free_exit(game);
				}
				// alt satır kontrolü
				if (y + 1 < game->y
					&& x < (int)ft_strlen(line[game->map_start + y + 1])
					&& line[game->map_start + y + 1][x] == ' ')
					//bu da aynı şekilde alt satır kontrolü alt satırda karakter varmı yokmu
				{
					printf("Error\nMap not closed (space below).\n");
					//free_exit(game);
				}
				if (x + 1 < len && line[game->map_start + y][x + 1] == ' ')//her yeri kendi içinde kıyaslıyacak 
				{
					printf("Error\n");
					//free_exit(game);
				}
				if (x - 1 >= 0 && line[game->map_start + y][x - 1] == ' ')
				{
					printf("Error\n");
					//free_exit(game);
				}
			}
			x++;
		}
		y++;
	}
}

void open_map(char *argv, t_game *list)
{
	char **lines;
	char *line;
    int fd;
    int count;

    fd = open(argv, O_RDONLY);
    if (fd < 0)
	{
		write(1, "Error\nCannot open map file.\n", 28) /* free_exit(list) */;
		 return ;
	}

    // Önce lines dizisini ayarlıyoruz
    lines = malloc(sizeof(char *) * 1000); // MAX_LINES yeterince büyük olmalı
    if (!lines)
        return; // malloc hatası
    count = 0;

    // Dosyayı satır satır oku
    while ((line = get_next_line(fd)) != NULL)
    {
        lines[count++] = line;
    }
    close(fd);

    list->line_count = count;

	// list->fd = open(argv, O_RDONLY);
	// if (list->fd < 0)
	// {
	// 	write(1, "Error\nCannot open map file.\n", 28);
	// 	// free_exit(list);
	// }
	// list->line_map = ft_get_read(list->fd); //????????????????????
	// close(list->fd);
	// if (!list->line_map)
	// {
	// 	write(1, "Error\nFailed to read map file.\n", 31);
	// 	// free_exit(list);
	// }
	// lines = ft_split(list->line_map, '\n');
	// if (!lines || !lines[0])
	// {
	// 	write(1, "Error\nEmpty file.\n", 18);
	// 	// double_free(lines);
	// 	// free_exit(list);
	// }
	// while (lines[list->line_count])
	// 	list->line_count++;
	list->map_start = control_identifier(lines, list->line_count, list);
	if (list->map_start < 0)
	{
		return;
		// double_free(lines);
		// free_exit(list);
	}
	empty_line_control(lines, list->map_start, list->line_count);
	player_is_one(lines, list);
	list->y = list->line_count - list->map_start;
	if (list->y <= 0)
	{
		printf("Error\nNo map found (bak).\n");
		//free_exit(list);
	}
	// CHECK_MAP YAPILIYOR
	check_map(lines, list);
	list->map = build_map(lines, list);
	// double_free(lines);
}
