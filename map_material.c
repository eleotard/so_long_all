/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 00:49:30 by eleotard          #+#    #+#             */
/*   Updated: 2022/05/10 19:26:39 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*create_map_str(char *map_name)
{
	char	*map_str;
	char	*tmp;
	int		fd;

	map_str = malloc(sizeof(char) * 1);
	if (!map_str)
		return (NULL);
	map_str[0] = '\0';
	tmp = malloc(sizeof(char) * 1);
	if (!tmp)
		return (NULL);
	tmp[0] = '1';
	fd = open(map_name, O_RDONLY);
	while (ft_strcmp(tmp, map_str) != 0)
	{
		tmp = ft_free(tmp, NULL);
		tmp = ft_strdup(map_str);
		map_str = join(map_str, get_next_line(fd));
	}
	free(tmp);
	close(fd);
	if (ft_parsing_check(map_str) == ERROR)
		return (NULL);
	return (map_str);
}

char	**create_map_tab(char *map_name)
{
	char	*map_str;
	char	**map;

	map_str = create_map_str(map_name);
	if (!map_str)
		return (NULL);
	map = ft_split(map_str, '\n');
	free(map_str);
	if (ft_check_valid_map(map) == ERROR
		|| ft_check_rectangular_map(map) == ERROR
		|| ft_check_map_edges(map) == ERROR
		|| ft_check_occurence(map) == ERROR)
		return (NULL);
	return (map);
}

int	ft_map_height(char **map)
{
	int	k;

	k = 0;
	while (map[k])
		k++;
	return (k);
}

int	ft_map_wide(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j])
		j++;
	return (j);
}
