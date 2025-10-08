/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil < sakdil@student.42istanbul.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:13:45 by sakdil            #+#    #+#             */
/*   Updated: 2025/10/08 10:14:26 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	handle_floor(t_game *game)
{
	if (game->control.is_floor)
		return (printf("Error\nDuplicate F identifier.\n"), false);
	game->control.is_floor = 1;
	return (true);
}

bool	handle_ceiling(t_game *game)
{
	if (game->control.is_ceiling)
		return (printf("Error\nDuplicate C identifier.\n"), false);
	game->control.is_ceiling = 1;
	return (true);
}
