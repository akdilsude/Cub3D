/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:31:48 by sakdil            #+#    #+#             */
/*   Updated: 2025/10/21 14:05:24 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		printf("Error\nMLX build failed.\n");
		free_error_exit(game);
	}
	game->win_x = WINDOW_WIDTH;
	game->win_y = WINDOW_HEIGHT;
	game->win = mlx_new_window(game->mlx, game->win_x, game->win_y, "Cub3d");
	if (!game->win)
	{
		printf("Error\nFailed to create window.\n");
		free_error_exit(game);
	}
	game->img = mlx_new_image(game->mlx, game->win_x, game->win_y);
	if (!game->img)
	{
		printf("Error\nFailed to create image.\n");
		free_error_exit(game);
	}
	
}
