/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 21:14:41 by sakdil            #+#    #+#             */
/*   Updated: 2026/02/28 14:54:23 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_tex_x(t_game *game, int tex_idx)
{
	double	wall_x;
	int		tex_x;

	if (game->ray.side == 0)
		wall_x = game->player_y + game->ray.wall_distance * game->ray.dir_y;
	else
		wall_x = game->player_x + game->ray.wall_distance * game->ray.dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)game->textures[tex_idx].width);
	if ((game->ray.side == 0 && game->ray.dir_x > 0)
		|| (game->ray.side == 1 && game->ray.dir_y < 0))
		tex_x = game->textures[tex_idx].width - tex_x - 1;
	return (tex_x);
}

static int	get_tex_color(t_game *game, int tex_i, int tex_x, double tex_pos)
{
	int		tex_y;
	char	*pixel;

	tex_y = (int)tex_pos % game->textures[tex_i].height;
	pixel = game->textures[tex_i].pixels
		+ (tex_y * game->textures[tex_i].line_len
			+ tex_x * (game->textures[tex_i].bits_per_pixel / 8));
	return (*(int *)pixel);
}

static void	pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= game->win_x || y >= game->win_y)
		return ;
	dst = game->image.pixels + (y * game->image.line_len + x
			* (game->image.bits_per_pixel / 8));
	*(int *)dst = color;
}

static void	draw_wall_texture(t_game *game, int x, int tex_i, int tex_x)
{
	int		y;
	double	step;
	double	tex_pos;
	int		color;

	step = 1.0 * game->textures[tex_i].height / game->ray.line_height;
	tex_pos = (game->ray.draw_start - game->win_y / 2
			+ game->ray.line_height / 2) * step;
	y = game->ray.draw_start;
	while (y <= game->ray.draw_end)
	{
		color = get_tex_color(game, tex_i, tex_x, tex_pos);
		pixel_put(game, x, y, color);
		tex_pos += step;
		y++;
	}
}

void	draw_vertical_line(t_game *game, int x)
{
	int	y;
	int	tex_i;
	int	tex_x;

	y = 0;
	while (y < game->ray.draw_start)
	{
		pixel_put(game, x, y, create_color(game->ceiling_r,
				game->ceiling_g, game->ceiling_b));
		y++;
	}
	tex_i = texture_index(game);
	tex_x = get_tex_x(game, tex_i);
	draw_wall_texture(game, x, tex_i, tex_x);
	y = game->ray.draw_end + 1;
	while (y < game->win_y)
	{
		pixel_put(game, x, y, create_color(game->floor_r,
				game->floor_g, game->floor_b));
		y++;
	}
}
