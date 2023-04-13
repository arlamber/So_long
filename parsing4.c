/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlamber <arlamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:52:46 by arlamber          #+#    #+#             */
/*   Updated: 2023/03/08 11:44:22 by arlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pars_4(char **str, int e, int p, int c)
{
	int	i;
	int	j;

	j = -1;
	while (str[++j])
	{
		i = -1;
		while (str[j][++i])
		{
			if (str[j][i] == 'E')
				e++;
			if (str[j][i] == 'P')
				p++;
			if (str[j][i] == 'C')
				c++;
		}
	}
	if (p != 1 || e != 1 || c < 1)
		return (98);
	return (1);
}
