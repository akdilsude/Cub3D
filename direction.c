/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:23:45 by sakdil            #+#    #+#             */
/*   Updated: 2025/09/22 16:49:37 by sakdil           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

bool	handle_no(t_game *game, char *line)
{
	if (game->control.is_no)
		return (printf("error: Duplicate NO identifier.\n"), false);
	game->north = //parse_path(line);
	if (!game->north)
		return (printf("error: Invalid NO texture path.\n"), false);
	game->control.is_no = 1;
	return (true);
}

bool	handle_so(t_game *game, char *line)
{
	if (game->control.is_so)
		return (printf("error: Duplicate NO identifier.\n"), false);
	game->south = //parse_path(line);
	if (!game->south)
		return (printf("error: Invalid NO texture path.\n"), false);
	game->control.is_no = 1;
	return (true);
}
bool	handle_we(t_game *game, char *line)
{
	if (game->control.is_we)
		return (printf("error: Duplicate NO identifier.\n"), false);
	game->west = //parse_path(line);
	if (!game->west)
		return (printf("error: Invalid NO texture path.\n"), false);
	game->control.is_we = 1;
	return (true);
}

bool	handle_ea(t_game *game, char *line)
{
	if (game->control.is_ea)
		return (printf("error: Duplicate NO identifier.\n"), false);
	game->east = //parse_path(line);
	if (!game->east)
		return (printf("error: Invalid NO texture path.\n"), false);
	game->control.is_ea = 1;
	return (true);
}

bool	handle_floor(t_game *g, char *line)
{
	if (g->control.is_floor)
		return (printf("error: Duplicate F identifier.\n"), false);
	g->control.is_floor = 1;
	return (true);
}

bool	handle_ceiling(t_game *g, char *line)
{
	if (g->control.is_ceiling)
		return (printf("error: Duplicate C identifier.\n"), false);
	g->control.is_ceiling = 1;
	return (true);
}
