/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil < sakdil@student.42istanbul.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:23:45 by sakdil            #+#    #+#             */
/*   Updated: 2025/09/23 13:13:58 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	handle_no(char *line, t_game *game)
{
	if (game->control.is_no)
		return (printf("Error\nDuplicate NO identifier.\n"), false);
	game->north = find_path(line);
	if (!game->north)
		return (printf("Error\nInvalid NO texture path.\n"), false);
	game->control.is_no = 1;
	return (true);
}

bool	handle_so(char *line, t_game *game)
{
	if (game->control.is_so)
		return (printf("Error\nDuplicate NO identifier.\n"), false);
	game->south = find_path(line);
	if (!game->south)
		return (printf("Error\nInvalid NO texture path.\n"), false);
	game->control.is_no = 1;
	return (true);
}
bool	handle_we(char *line, t_game *game)
{
	if (game->control.is_we)
		return (printf("Error\nDuplicate NO identifier.\n"), false);
	game->west = find_path(line);
	if (!game->west)
		return (printf("Error\nInvalid NO texture path.\n"), false);
	game->control.is_we = 1;
	return (true);
}

bool	handle_ea(char *line, t_game *game)
{
	if (game->control.is_ea)
		return (printf("Error\nDuplicate NO identifier.\n"), false);
	game->east = find_path(line);
	if (!game->east)
		return (printf("Error\nInvalid NO texture path.\n"), false);
	game->control.is_ea = 1;
	return (true);
}

bool	handle_floor(t_game *g)
{
	if (g->control.is_floor)
		return (printf("Error\nDuplicate F identifier.\n"), false);
	g->control.is_floor = 1;
	return (true);
}

bool	handle_ceiling(t_game *g)
{
	if (g->control.is_ceiling)
		return (printf("Error\nDuplicate C identifier.\n"), false);
	g->control.is_ceiling = 1;
	return (true);
}

//Mapteki N,S,E,W oyuncunun başladığı yer olacak ve nereden baktığını belirtecek.