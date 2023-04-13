/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlamber <arlamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:12:04 by arlamber          #+#    #+#             */
/*   Updated: 2023/03/08 11:29:31 by arlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(t_data *data, char **argv)
{
	int		fd;
	char	*line;
	char	*tmp;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
		{
			free(tmp);
			break ;
		}
		line = ft_strjoin(line, tmp);
		free(tmp);
	}
	close(fd);
	if ((space(line)) == 0)
		return (free(line), (NULL));
	data->map = ft_split(line, '\n');
	free(line);
	return (data->map);
}

char	**copy_map(t_data *data)
{
	char	**copy;
	int		i;

	i = 0;
	while (data->map[i])
			i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (data->map[i])
	{
		copy[i] = ft_strdup(data->map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
