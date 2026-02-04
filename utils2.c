/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:33:20 by sakdil            #+#    #+#             */
/*   Updated: 2026/02/04 22:21:01 by sakdil           ###   ########.fr       */
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

bool	handle_floor(t_game *game)
{
	if (game->control.is_floor)
		return (printf("Error\nDuplicate F identifier.\n"), false);
	game->control.is_floor = 1;
	return (true);
}
