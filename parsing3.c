/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlamber <arlamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:57:25 by arlamber          #+#    #+#             */
/*   Updated: 2023/03/10 17:17:06 by arlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse(char **str)
{
	if (!str)
		return (0);
	if (ft_parsing1(str) == 98)
	{
		write (2, "Error\nTrop ou pas assez de PEC", 31);
		return (0);
	}
	if (!ft_square(str))
	{
		write (2, "Error\nMap pas rectangle", 24);
		return (0);
	}
	if (!ft_wall(str))
	{
		write (2, "Error\nWall", 11);
		return (0);
	}
	if (ft_parsing1(str) == 99)
	{
		write (2, "Error\nCaracter invalide", 24);
		return (0);
	}
	return (1);
}

int	flopfill(char **str)
{
	t_size	*size;

	size = NULL;
	size = malloc(sizeof(t_size));
	if (!size)
		return (0);
	player_pos2(str, size);
	if (!flood_fill(str, size, size->x, size->y))
	{
		write (2, "Error\nPas de chemin", 20);
		free(size);
		return (0);
	}
	free(size);
	return (1);
}
