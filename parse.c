/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segunes <segunes@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:53:07 by segunes           #+#    #+#             */
/*   Updated: 2025/09/22 18:47:29 by segunes          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

char *validate_path(char *path)
{
	int fd;
	int len;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	close(fd);
	if (access(path, F_OK | R_OK) != 0)
		return (NULL);
	if (ft_strlen(path) < 5)
		return (NULL);
	len = ft_strlen(path);
	if (!(path[len - 4] == '.' &&
		  path[len - 3] == 'x' &&
		  path[len - 2] == 'p' &&
		  path[len - 1] == 'm'))
		return (NULL);
	//sadece uzantısı .xpm olursa ve mapte de aynısı sadece  .cub olmamalı ev açmamalı unutma
	return path;
}

char *find_path(char *input)
{
	int i;
	char *path;

	i = 0;
	if (!input)
		return (NULL);
	if (input[2] != ' ')
		return (NULL); // hata
	while (input[i] != ' ')
		i++;
	if (input[i + 1] == '.')
	{
		path = ft_strdup(&input[i + 1]);
		//free unutma
		validate_path(path);
	}
	else
		return (1); // hata
}