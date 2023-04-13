/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlamber <arlamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:58:37 by arlamber          #+#    #+#             */
/*   Updated: 2023/03/07 12:07:34 by arlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	max_collec(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->collect = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
			{
				data->collect += 1;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->x = i;
				data->y = j;
			}
			j++;
		}
		i++;
	}
	return (0);
}

t_size	*player_pos2(char **str, t_size *size)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			{
				size->x = i;
				size->y = j;
			}
			j++;
		}
		i++;
	}
	size->width = j;
	size->height = i;
	return (size);
}
