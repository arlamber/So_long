/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlamber <arlamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:54:11 by arlamber          #+#    #+#             */
/*   Updated: 2023/03/08 11:41:12 by arlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_wordcount(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static int	ft_wordlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static void	ft_addword(char **tab, char *str, int i, char c)
{
	int	j;
	int	k;

	j = 0;
	while (str[i])
	{
		k = 0;
		while (str[i] == c)
			i++;
		if (str[i])
		{
			tab[j] = malloc((sizeof(char)) * (ft_wordlen(str + i, c) + 1));
			if (!tab[j])
				ft_malloc_error(tab);
			while (str[i] && str[i] != c)
			{
				tab[j][k] = str[i];
				i++;
				k++;
			}
			tab[j][k] = '\0';
			j++;
		}
	}
	tab[j] = (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**tab;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)s;
	tab = malloc((ft_wordcount(str, c) + 1) * (sizeof(char *)));
	if (!tab)
		return (NULL);
	ft_addword(tab, str, i, c);
	return (tab);
}
