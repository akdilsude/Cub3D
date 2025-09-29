/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segunes <segunes@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:36:45 by segunes           #+#    #+#             */
/*   Updated: 2025/09/29 17:28:48 by segunes          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

char	*join(char *str, char *buffer)
{
	int		i;
	int		j;
	char	*res;

	if (!str)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	i = 0;
	j = 0;
	res = malloc(ft_strlen(str) + ft_strlen(buffer) + 1);
	if (res == NULL)
		return (NULL);
	while (str[j])
	{
		res[j] = str[j];
		j++;
	}
	while (buffer[i])
		res[j++] = buffer[i++];
	res[ft_strlen(str) + ft_strlen(buffer)] = '\0';
	free(str);
	return (res);
}

char	*line(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	ptr = malloc(i + 2);
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*new(char *str)
{
	int		j;
	int		i;
	char	*res;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	res = malloc((ft_strlen(str) - i) + 1);
	if (!res)
		return (NULL);
	i++;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}
