/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 18:01:46 by segunes           #+#    #+#             */
/*   Updated: 2025/09/22 19:48:51 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h> 
# include <stdbool.h>

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
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	int		map_start;
	int		line_count;
	char	*line_map;
	char	**map;

	char	*north;
	char	*south;
	char	*west;
	char	*east;
	t_control	control;

}	t_game;


void	name_control(char *str, t_game *list);
void	game_edit(t_game *list);
int		is_only_spaces(char *str);
char	*find_path(char *input);
void	**build_map(char **line, t_game * game);




#endif