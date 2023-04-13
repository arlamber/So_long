/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlamber <arlamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:29:16 by arlamber          #+#    #+#             */
/*   Updated: 2023/03/06 15:37:12 by arlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_S)
		ft_move_s(data);
	if (keycode == KEY_W)
		ft_move_w(data);
	if (keycode == KEY_A)
		ft_move_a(data);
	if (keycode == KEY_D)
		ft_move_d(data);
	if (keycode == KEY_ESC)
	{
		ft_free_all(data);
		exit(0);
	}
	return (0);
}

void	ft_move_s(t_data *data)
{
	player_pos(data);
	if ((data->map[data->x + 1][data->y]) == 'E' && (!max_collec(data)))
	{
		data->mvt += 1;
		write (1, "nb mouvements = ", 16);
		ft_putnbr_fd(data->mvt, 1);
		write (1, "\n", 1);
		ft_free_all(data);
		exit(0);
	}
	if (data->map[data->x + 1][data->y] != '1'
			&& (data->map[data->x + 1][data->y]) != 'E')
	{
		data->map[data->x][data->y] = '0';
		data->x += 1;
		data->map[data->x][data->y] = 'P';
		aff_map2(data);
		aff_map3(data);
		data->mvt += 1;
		write (1, "nb mouvements = ", 16);
		ft_putnbr_fd(data->mvt, 1);
		write (1, "\n", 1);
	}
}

void	ft_move_w(t_data *data)
{
	player_pos(data);
	if ((data->map[data->x - 1][data->y]) == 'E' && (!max_collec(data)))
	{
		data->mvt += 1;
		write (1, "nb mouvements = ", 16);
		ft_putnbr_fd(data->mvt, 1);
		write (1, "\n", 1);
		ft_free_all(data);
		exit(0);
	}	
	if (data->map[data->x - 1][data->y] != '1'
			&& (data->map[data->x - 1][data->y]) != 'E')
	{
		data->map[data->x][data->y] = '0';
		data->x -= 1;
		data->map[data->x][data->y] = 'P';
		aff_map2(data);
		aff_map3(data);
		data->mvt += 1;
		write (1, "nb mouvements = ", 16);
		ft_putnbr_fd(data->mvt, 1);
		write (1, "\n", 1);
	}
}

void	ft_move_a(t_data *data)
{	
	player_pos(data);
	if ((data->map[data->x][data->y - 1]) == 'E' && (!max_collec(data)))
	{
		data->mvt += 1;
		write (1, "nb mouvements = ", 16);
		ft_putnbr_fd(data->mvt, 1);
		write (1, "\n", 1);
		ft_free_all(data);
		exit(0);
	}		
	if (data->map[data->x][data->y - 1] != '1'
			&& (data->map[data->x][data->y - 1]) != 'E')
	{
		data->map[data->x][data->y] = '0';
		data->y -= 1;
		data->map[data->x][data->y] = 'P';
		aff_map2(data);
		aff_map3(data);
		data->mvt += 1;
		write (1, "nb mouvements = ", 16);
		ft_putnbr_fd(data->mvt, 1);
		write (1, "\n", 1);
	}
}

void	ft_move_d(t_data *data)
{
	player_pos(data);
	if ((data->map[data->x][data->y + 1]) == 'E' && (!max_collec(data)))
	{
		data->mvt += 1;
		write (1, "nb mouvements = ", 16);
		ft_putnbr_fd(data->mvt, 1);
		write (1, "\n", 1);
		ft_free_all(data);
		exit(0);
	}	
	if (data->map[data->x][data->y + 1] != '1'
			&& (data->map[data->x][data->y + 1]) != 'E')
	{
		data->map[data->x][data->y] = '0';
		data->y += 1;
		data->map[data->x][data->y] = 'P';
		aff_map2(data);
		aff_map3(data);
		data->mvt += 1;
		write (1, "nb mouvements = ", 16);
		ft_putnbr_fd(data->mvt, 1);
		write (1, "\n", 1);
	}
}
