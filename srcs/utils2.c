/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:33:20 by sakdil            #+#    #+#             */
/*   Updated: 2026/02/22 15:54:56 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	line_len(char *str)
{
	int	n;

	n = ft_strlen(str);
	if (n > 0 && str[n - 1] == '\n')
		n--;
	return (n);
}

void	free_lines(char **lines)
{
	int	i;

	i = 0;
	if (!lines)
		return ;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

void	continue_init_mlx(t_game *game)
{
	game->image.img = mlx_new_image(game->mlx, game->win_x, game->win_y);
	if (!game->image.img)
	{
		printf("Error\nFailed to create image.\n");
		cleanup(game);
		exit(1);
	}
	game->image.pixels = mlx_get_data_addr(game->image.img,
			&game->image.bits_per_pixel, &game->image.line_len,
			&game->image.byte_order);
}

void	validate_wall(t_game *game, int y, char c, char *side)
{
	if (c != '1')
	{
		printf("Error\n%s edge not closed at y=%d\n", side, y + 1);
		cleanup(game);
		exit(1);
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
