/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlamber <arlamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:17:44 by arlamber          #+#    #+#             */
/*   Updated: 2023/03/13 11:24:56 by arlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	good_open(char **av)
{
	int		fd;
	char	c;

	fd = open (av[1], O_RDONLY);
	if (fd <= 0)
	{
		close(fd);
		write (2, "Error\nFichier inexistant", 25);
		return (0);
	}
	if ((read (fd, &c, 1)) < 1)
	{
		close(fd);
		write (2, "Error\nMAP vide", 15);
		return (0);
	}
	close (fd);
	return (1);
}

int	verif_arg(int ac, char **av)
{
	if (ac < 2 || ac > 2)
	{
		write (2, "Error\narg non valide", 21);
		return (0);
	}
	if (map_ber (av[1]) == 0)
	{
		write (2, "Error\nno .BER", 14);
		return (0);
	}
	return (1);
}

char	**f_fill(char **map, t_size size, int row, int col)
{
	if (row <= 0 || col <= 0 || row > size.height || col > size.width)
		return (NULL);
	if (map[row][col] == 'X' || map[row][col] == '1' || map[row][col] == 'E')
		return (NULL);
	map[row][col] = 'X';
	f_fill(map, size, row - 1, col);
	f_fill(map, size, row + 1, col);
	f_fill(map, size, row, col - 1);
	f_fill(map, size, row, col + 1);
	return (map);
}

int	flood_fill(char **map, t_size *size, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map = f_fill(map, *size, x, y);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			if (map[i][j] == 'E' && (map[i + 1][j] != 'X' && map[i
					- 1][j] != 'X' && map[i][j + 1] != 'X' && map[i][j
					- 1] != 'X'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
