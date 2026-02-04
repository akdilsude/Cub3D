/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:23:55 by sakdil            #+#    #+#             */
/*   Updated: 2026/02/04 21:50:17 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_error_exit(t_game *game)
{
	(void)game;
	exit(1);
}

void	game_edit(t_game *game)
{
	game->line_count = 0;
	game->player_direc = 0;
	game->map_start = 0;
}

int	close_window(t_game *game)
{
	printf("Existing the game....\n");
	free_error_exit(game);
	return (0);
}
