/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_and_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:44:25 by sakdil            #+#    #+#             */
/*   Updated: 2025/12/02 12:55:49 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	draw_pixel_to_image(int x, int y, int color, t_game *game)
{

}
