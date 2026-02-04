/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:57:15 by segunes           #+#    #+#             */
/*   Updated: 2026/02/04 22:08:36 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*list;

	list = (t_game *)malloc(sizeof(t_game));
	if (!list)
		return (write(1, "Error: Malloc failed\n", 21), 0);
	game_edit(list);
	if (argc == 2 && argv[1] && argv[1][0] != '.')
	{
		name_control(argv[1]);
		open_map(argv[1], list);
		game_start(list);
	}
	return (0);
}
