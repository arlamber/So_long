/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlamber <arlamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:52:02 by arlamber          #+#    #+#             */
/*   Updated: 2023/03/14 18:44:01 by arlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	lenx(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
			j++;
		i++;
	}
	return (i);
}

void	display_window(t_data *data, char **av)
{
	int	x;
	int	y;

	(void)av;
	x = 0;
	y = 0;
	y = lenx(data);
	x = ft_strlen(data->map[0]);
	data->mvt = 0;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		(ft_free_map(data), write(1, "Error\nPath", 11), exit(1));
	data->mlx_win = mlx_new_window(data->mlx, 32 * x, 32 * y, "solong");
	if (data->mlx_win == NULL)
		(ft_free_map(data), exit(1));
	ft_texture(data);
	aff_map2(data);
	aff_map3(data);
	mlx_key_hook(data->mlx_win, key_hook, data);
	mlx_hook(data->mlx_win, 1, 1L << 0, key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, mlx_loop_end, data->mlx);
	mlx_loop(data->mlx);
}

int	ft_texture(t_data *data)
{
	int	img_width;
	int	img_height;

	data->wall = mlx_xpm_file_to_image(data->mlx,
			"./textures/wall.xpm", &img_width, &img_height);
	data->coin = mlx_xpm_file_to_image(data->mlx,
			"./textures/coin.xpm", &img_width, &img_height);
	data->player = mlx_xpm_file_to_image(data->mlx,
			"./textures/player.xpm", &img_width, &img_height);
	data->shotgun = mlx_xpm_file_to_image(data->mlx,
			"./textures/shotgun.xpm", &img_width, &img_height);
	data->floor = mlx_xpm_file_to_image(data->mlx,
			"./textures/floor.xpm", &img_width, &img_height);
	if (!data->wall || !data->coin || !data->player
		|| !data->floor || !data->shotgun)
	{
		ft_free_all(data);
		(write (2, "Error\nSprite", 12), exit(1));
	}
	return (1);
}

void	aff_map2(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx,
					data->mlx_win, data->wall, j * 32, i * 32);
			else if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx,
					data->mlx_win, data->floor, j * 32, i * 32);
			else if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx,
					data->mlx_win, data->player, j * 32, i * 32);
		}
	}
}

void	aff_map3(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx,
					data->mlx_win, data->shotgun, j * 32, i * 32);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx,
					data->mlx_win, data->coin, j * 32, i * 32);
		}
	}
}
