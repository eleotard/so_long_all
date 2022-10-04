/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:39:07 by lcalvie           #+#    #+#             */
/*   Updated: 2022/09/05 14:51:28 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill_tab_valid_path(char **map, int **tab, int i, int j)
{
	if (map[i][j] == '1')
		return ;
	if (map[i][j] == 'E')
	{
		tab[i][j] = 0;
		return ;
	}
	else if (map[i][j] == 'P')
		tab[i][j] = 0;
	else if (tab[i][j] != -1)
		return ;
	else
		tab[i][j] = 0;
	fill_tab_valid_path(map, tab, i + 1, j);
	fill_tab_valid_path(map, tab, i - 1, j);
	fill_tab_valid_path(map, tab, i, j + 1);
	fill_tab_valid_path(map, tab, i, j - 1);
}

static int	**init_tab_valid_path(int **tab, int w, int h)
{
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			tab[i][j] = -1;
			j++;
		}
		i++;
	}
	return (tab);
}

static int	**malloc_tab_valid_path(int w, int h)
{
	int	i;
	int	j;
	int	**tab;

	tab = malloc(sizeof(int *) * h);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < h)
	{
		tab[i] = malloc(sizeof(int) * w);
		if (tab[i] == NULL)
		{
			j = -1;
			while (j < i)
				free(tab[++j]);
			free(tab);
			return (NULL);
		}
		i++;
	}
	return (init_tab_valid_path(tab, w, h));
}

static int	valid_tab_and_free(char **map, int **tab)
{
	int	i;
	int	j;
	int	ret;

	ret = 0;
	i = -1;
	while (map[++i] && ret != ERROR)
	{
		j = -1;
		while (map[i][++j])
		{
			if ((map[i][j] == 'C' || map[i][j] == 'E') && tab[i][j] == -1)
			{
				ret = ERROR;
				ft_putstr_fd("Error\nNo valid path found on this map\n", 2);
				break ;
			}
		}
	}
	i = -1;
	while (map[++i])
		free(tab[i]);
	if (ret == ERROR)
		ft_destroy_map(map);
	return (free(tab), ret);
}

int	ft_check_valid_path(char **map)
{
	int	i;
	int	j;
	int	**tab;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != 'P')
			j++;
		if (map[i][j] == 'P')
			break ;
		i++;
	}
	tab = malloc_tab_valid_path(ft_map_wide(map), ft_map_height(map));
	if (tab == NULL)
		return (ERROR);
	fill_tab_valid_path(map, tab, i, j);
	return (valid_tab_and_free(map, tab));
}
