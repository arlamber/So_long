/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlamber <arlamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:16:07 by arlamber          #+#    #+#             */
/*   Updated: 2023/03/08 11:42:47 by arlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free_all(t_data *data)
{
	if (data->coin)
		mlx_destroy_image(data->mlx, data->coin);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->floor)
		mlx_destroy_image(data->mlx, data->floor);
	if (data->shotgun)
		mlx_destroy_image(data->mlx, data->shotgun);
	if (data->mlx_win)
	{
		mlx_clear_window(data->mlx, data->mlx_win);
		mlx_destroy_window(data->mlx, data->mlx_win);
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
	}
	free(data->mlx);
	ft_free_map(data);
	return (0);
}

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data);
}

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
