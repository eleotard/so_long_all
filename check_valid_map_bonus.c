/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 00:52:45 by eleotard          #+#    #+#             */
/*   Updated: 2022/05/11 13:00:33 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_ber(char *map_name)
{
	int		i;
	int		j;
	char	*extension;

	i = 0;
	j = 0;
	while (map_name[i])
		i++;
	if (i <= 4)
	{
		ft_putstr_fd("Error\nWrong map file format\n", 2);
		return (ERROR);
	}
	j = i - 4;
	extension = ft_substr(map_name, j, 4);
	if (ft_strcmp(extension, ".ber") != 0)
	{
		free(extension);
		ft_putstr_fd("Error\nWrong map file format\n", 2);
		return (ERROR);
	}
	free(extension);
	return (0);
}

int	check_edges_char(char **map, char c)
{
	if (c != '1')
	{
		ft_destroy_map(map);
		ft_putstr_fd("Error\nMap not closed\n", 2);
		return (ERROR);
	}	
	return (0);
}

int	ft_check_map_edges(char **map)
{
	t_data	co;

	ft_check_edges_init(&co, map);
	while (map[++co.i])
	{
		if (co.i == 0 || co.i == (co.y - 1))
		{
			while (map[co.i][++co.j])
			{
				if (check_edges_char(map, map[co.i][co.j]) == ERROR)
					return (ERROR);
			}
		}
		else
		{
			if (check_edges_char(map, map[co.i][0]) == ERROR
				|| check_edges_char(map, map[co.i][co.x - 1]) == ERROR)
				return (ERROR);
		}
		co.j = -1;
	}
	return (0);
}

int	ft_check_rectangular_map(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_map_wide(map);
	while (map[i])
	{
		while (map[i][j])
			j++;
		if (j != len)
		{
			ft_destroy_map(map);
			ft_putstr_fd("Error\nNon-rectangular map\n", 2);
			return (ERROR);
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_check_valid_map(char **map)
{
	if (ft_map_height(map) <= 3 && ft_map_height(map) <= 3)
	{
		ft_destroy_map(map);
		ft_putstr_fd("Error\nMap too small or bad .ber file\n", 2);
		return (ERROR);
	}
	return (0);
}
