/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segunes <segunes@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:53:07 by segunes           #+#    #+#             */
/*   Updated: 2025/09/30 16:08:16 by segunes          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

char *validate_path(char *path)
{
	int len;

	if (access(path, F_OK | R_OK) != 0)
	{
		// printf("%s", path);
		printf("jjj");
		return (NULL);
	}
	if (ft_strlen(path) < 5)
		return (NULL);
	len = ft_strlen(path);
	if (!(path[len - 4] == '.' &&
		  path[len - 3] == 'x' &&
		  path[len - 2] == 'p' &&
		  path[len - 1] == 'm'))
		return (NULL);
	// sadece uzantısı .xpm olursa ve mapte de aynısı sadece  .cub olmamalı ev açmamalı unutma
	return path;
}

char *find_path(char *input)
{
	int i;
	int len;
//	char *path;

	i = 0;
	if (!input)
		return (NULL);
	if (input[2] != ' ')	
		return (NULL); // hata
	while (input[i] != ' ')
		i++;
	if (input[i + 1] == '.' || input[i + 1] == '/')
	{
		i++;
        char *path = &input[i]; // Yolun başlangıcı
		//path = ft_strdup(&input[i + 3]);
		// free unutma
		len = ft_strlen(path);
		while (len > 0 && (path[len - 1] == ' ' || path[len - 1] == '\n' || path[len - 1] == '\r'))
        {
            path[len - 1] = '\0'; // Karakteri NULL ile değiştir
            len--;
        }
		if (validate_path(path) == NULL) // validate_path boolean döndürüyorsa
		{
			printf("burascdsfı");

			free(input);
			return NULL;
		}
		return input;
	}
	else
		return (NULL); // hata
}

