/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlamber <arlamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:41:24 by arlamber          #+#    #+#             */
/*   Updated: 2023/03/10 16:56:43 by arlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_parsing1(char **str)
{
	int	i;
	int	p;
	int	j;
	int	e;
	int	c;

	c = 0;
	e = 0;
	j = -1;
	p = 0;
	while (str[++j])
	{
		i = -1;
		while (str[j][++i])
		{
			if (str[j][i] != '1' && str[j][i] != '0' && str[j][i] != 'C'
				&& str[j][i] != 'E' && str[j][i] != 'P' && str[j][i] != '\n')
			{
				return (99);
			}
			if ((pars_4(str, p, e, c)) == 98)
				return (98);
		}
	}
	return (1);
}

int	ft_square(char **str)
{
	int	i;
	int	len;
	int	h;

	i = 0;
	h = 0;
	len = ft_strlen(str[0]);
	while (str[i])
	{
		if (ft_strlen(str[i]) != len)
			return (0);
		i++;
	}
	while (str[h])
		h++;
	if (len <= h)
		return (0);
	return (1);
}

int	ft_wall(char **str)
{
	int	i;
	int	x;
	int	j;

	i = 0;
	x = 0;
	j = 0;
	while (str[x])
		x++;
	while (str[0][i])
	{
		if (str[0][i] != '1')
			return (0);
		if (str[x - 1][i] != '1')
			return (0);
		i++;
	}
	while (str[j])
	{
		if (str[j][0] != '1' || str[j][ft_strlen(str[j]) - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	map_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == 'r' && str[i - 2] == 'e' && str[i - 3] == 'b'
		&& str[i - 4] == '.')
		return (1);
	else
		return (0);
}

int	space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{	
		if (str[0] == '\n')
		{
			write(1, "Error\nLigne vide", 17);
			return (0);
		}
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			write(1, "Error\ntrop despaces", 20);
			return (0);
		}
		i++;
	}
	return (1);
}
