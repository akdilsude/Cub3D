/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:36:17 by sakdil            #+#    #+#             */
/*   Updated: 2026/02/04 21:58:31 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray(t_game *game, int x)
{
	game->ray.camera_x = 2 * x / (double)game->win_x - 1;
	game->ray.dir_x = game->vec_x + game->plane_x * game->ray.camera_x;
	game->ray.dir_y = game->vec_y + game->plane_y * game->ray.camera_x;
	game->ray.map_x = (int)game->player_x;
	game->ray.map_y = (int)game->player_y;
	game->ray.delta_dist_x = fabs(1 / game->ray.dir_x);
	game->ray.delta_dist_y = fabs(1 / game->ray.dir_y);
}

static void	calculate_step(t_game *game)
{
	if (game->ray.dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x = (game->player_x - game->ray.map_x)
			* game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = (game->ray.map_x + 1.0 - game->player_x)
			* game->ray.delta_dist_x;
	}
	if (game->ray.dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = (game->player_y - game->ray.map_y)
			* game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = (game->ray.map_y + 1.0 - game->player_y)
			* game->ray.delta_dist_y;
	}
}

static void	search_for_wall(t_game *game)
{
	game->ray.has_hit = 0;
	while (game->ray.has_hit == 0)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->ray.map_y < 0 || game->ray.map_y >= game->y
			|| game->ray.map_x < 0 || game->ray.map_x
			>= (int)ft_strlen(game->map[game->ray.map_y]))
			break ;
		if (game->map[game->ray.map_y][game->ray.map_x] == '1')
			game->ray.has_hit = 1;
	}
}

static void	calc_wall_height(t_game *game)
{
	if (game->ray.side == 0)
		game->ray.wall_distance = (game->ray.map_x - game->player_x
				+ (1 - game->ray.step_x) / 2) / game->ray.dir_x;
	else
		game->ray.wall_distance = (game->ray.map_y - game->player_y
				+ (1 - game->ray.step_y) / 2) / game->ray.dir_y;
	if (game->ray.wall_distance <= 0)
		game->ray.wall_distance = 0.1;
	game->ray.line_height = (int)(game->win_y / game->ray.wall_distance);
	game->ray.draw_start = -game->ray.line_height / 2 + game->win_y / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = game->ray.line_height / 2 + game->win_y / 2;
	if (game->ray.draw_end >= game->win_y)
		game->ray.draw_end = game->win_y - 1;
}

int	raycasting(t_game *game)
{
	int	x;

	x = -1;
	while (++x < game->win_x)
	{
		init_ray(game, x);
		calculate_step(game);
		search_for_wall(game);
		calc_wall_height(game);
		draw_vertical_line(game, x);
	}
	return (0);
}
