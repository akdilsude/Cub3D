/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil < sakdil@student.42istanbul.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 18:01:46 by segunes           #+#    #+#             */
/*   Updated: 2025/10/08 20:37:35 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h> 
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

typedef struct s_control
{
	int	is_no;
	int	is_so;
	int	is_we;
	int	is_ea;
	int	is_floor;
	int	is_ceiling;
}	t_control;

typedef struct s_game
{
	int		fd;
	int		x; //kullanmıyorum şimdilik
	int		y;
	int		player_x;
	int		player_y;
	char	player_direc;
	int		map_start;
	int		line_count;
	char	*line_map;
	char	**map;

	char	*north;
	char	*south;
	char	*west;
	char	*east;

	int floor_r;
    int floor_g;
    int floor_b;

    int ceiling_r;
    int ceiling_g;
    int ceiling_b;
	t_control	control;

}	t_game;

char	*find_path(char *input);
bool	handle_no(char *line, t_game *game);
bool	handle_so(char *line, t_game *game);
bool	handle_we(char *line, t_game *game);
bool	handle_ea(char *line, t_game *game);
int		is_all_set(t_game *game);
int		control_identifier(char **lines, t_game *game);
void	start_control_value(t_game *game);
void	open_map(char **argv, t_game *game);
void	tabs_in_map(char **lines, t_game *game);
void	check_map_end(char **lines, t_game *game);
void	empty_line_inside_map(char **lines, t_game *game);




void	name_control(char *str);
void	game_edit(t_game *list);
int		is_only_spaces(char *str);
char	**build_map(char **line, t_game * game);
bool	handle_floor(t_game *game);
bool	handle_ceiling(t_game *game);
char	*new(char *str);
char	*line(char *str);
char	*get_next_line(int fd);
char	*join(char *s1, char *s2);
void free_error_exit(t_game *game);
int	line_len(char *str);


#endif