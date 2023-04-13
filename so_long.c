/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlamber <arlamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:07:00 by arlamber          #+#    #+#             */
/*   Updated: 2023/03/08 12:05:43 by arlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	*data;
	char	**tmp;

	data = NULL;
	if (verif_arg(ac, av) == 0 || good_open (av) == 0)
		return (1);
	data = malloc ((sizeof(t_data)));
	if (!data)
		return (0);
	data->map = get_map(data, av);
	if (data->map == NULL)
		return ((free(data)), 1);
	tmp = copy_map(data);
	if (parse (data->map) == 0)
	{
		ft_free(tmp);
		return ((ft_free_map(data)), 1);
	}
	if (!flopfill(tmp))
		return ((ft_free_map (data)), (ft_free(tmp)), 1);
	ft_free(tmp);
	display_window(data, av);
	ft_free_all (data);
}
