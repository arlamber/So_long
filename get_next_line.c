/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlamber <arlamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:58:59 by arlamber          #+#    #+#             */
/*   Updated: 2022/12/15 16:20:55 by arlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*newline(char *stash, int byte)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	while (stash[j] != '\n' && stash[j])
		j++;
	if (byte == 0)
		return (free(stash), NULL);
	str = malloc(sizeof(char) * (ft_strlen(stash) - j + 1));
	if (!str)
		return (NULL);
	j++;
	i = 0;
	while (stash[j])
		str[i++] = stash[j++];
	str[i] = '\0';
	free(stash);
	return (str);
}

char	*get_line(char *stash)
{
	int		i;
	char	*res;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		res[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	int			byte;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	byte = 1;
	while (!(ft_strchr(stash)) && byte != 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte <= 0 && !stash)
			return (free(buffer), NULL);
		buffer[byte] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	buffer = get_line(stash);
	stash = newline(stash, byte);
	return (buffer);
}
