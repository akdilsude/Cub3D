/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segunes <segunes@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:24:19 by sakdil            #+#    #+#             */
/*   Updated: 2025/10/05 07:57:41 by segunes          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

int is_only_spaces(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
			return (0);
		str++;
	}
	return (1);
}

// void	tabs_to_spaces(char *s)
// {
// 	int i;

// 	if (!s)
// 		return ;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == '\t')
// 			s[i] = ' ';
// 		i++;
// 	}
// }

//tab olunca malloc açıcaz tab yerine space koyucaz 