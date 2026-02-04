/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_and_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:44:25 by sakdil            #+#    #+#             */
/*   Updated: 2026/02/04 21:36:44 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_texture(t_game *game, char *path, int i)
{
	t_image	*tex;

	if (!path)
	{
		printf("Error\nTexture path is NULL for index %d\n", i);
		exit(1);
	}
	tex = &game->textures[i];
	tex->img = mlx_xpm_file_to_image(game->mlx, path,
			&tex->width, &tex->height);
	if (!tex->img)
	{
		printf("Error\nCould not load texture: %s\n", path);
		free_error_exit(game);
	}
	tex->pixels = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_len, &tex->byte_order);
}

void	load_textures(t_game *game)
{
	char	*paths[4];
	int		i;

	paths[0] = game->north;
	paths[1] = game->south;
	paths[2] = game->east;
	paths[3] = game->west;
	i = 0;
	while (i < 4)
	{
		load_texture(game, paths[i], i);
		i++;
	}
}

int	create_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	texture_index(t_game *game)
{
	if (game->ray.side == 0)
	{
		if (game->ray.dir_x > 0)
			return (3);
		return (2);
	}
	else
	{
		if (game->ray.dir_y > 0)
			return (1);
		return (0);
	}
}
