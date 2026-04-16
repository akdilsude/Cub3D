/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:23:55 by sakdil            #+#    #+#             */
/*   Updated: 2026/02/04 23:57:24 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_edit(t_game *game)
{
	game->line_count = 0;
	game->player_direc = 0;
	game->map_start = 0;
	game->map = NULL;
	game->north = NULL;
	game->south = NULL;
	game->west = NULL;
	game->east = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->image.img = NULL;
	game->textures[0].img = NULL;
	game->textures[1].img = NULL;
	game->textures[2].img = NULL;
	game->textures[3].img = NULL;
	game->tmp_lines = NULL;
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	clean_map_data(t_game *game)
{
	if (game->north)
		free(game->north);
	if (game->south)
		free(game->south);
	if (game->west)
		free(game->west);
	if (game->east)
		free(game->east);
	if (game->map)
		free_array(game->map);
	if (game->tmp_lines)
		free_array(game->tmp_lines);
}

static void	clean_mlx(t_game *game)
{
	int	i;

	if (!game->mlx)
		return ;
	i = -1;
	while (++i < 4)
	{
		if (game->textures[i].img)
			mlx_destroy_image(game->mlx, game->textures[i].img);
	}
	if (game->image.img)
		mlx_destroy_image(game->mlx, game->image.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

int	cleanup(t_game *game)
{
	if (!game)
		return (1);
	clean_map_data(game);
	clean_mlx(game);
	free(game);
	return (1);
}
