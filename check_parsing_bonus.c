/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 00:49:30 by eleotard          #+#    #+#             */
/*   Updated: 2022/05/11 13:01:20 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_parsing_check(char *map_str)
{
	int	i;

	i = 0;
	while (map_str[i])
	{
		if (map_str[i] != '1' && map_str[i] != '0' && map_str[i] != 'P'
			&& map_str[i] != 'C' && map_str[i] != 'E' && map_str[i] != '\n')
		{
			free(map_str);
			ft_putstr_fd("Error\nCaractere incorect\n", 2);
			return (ERROR);
		}
		i++;
	}
	return (0);
}

void	ft_count_check_occurence(int *count_p, int *count_e,
			int *count_c, char c)
{
	if (c == 'P')
		*count_p = *count_p + 1;
	if (c == 'E')
		*count_e = *count_e + 1;
	if (c == 'C')
		*count_c = *count_c + 1;
}

int	ft_check_occurence(char **map)
{
	t_data	va;
	int		count_c;

	count_c = 0;
	ft_zero_init(&va);
	while (map[va.i])
	{
		while (map[va.i][va.j])
		{
			ft_count_check_occurence(&va.x, &va.y, &count_c, map[va.i][va.j]);
			va.j++;
		}
		va.j = 0;
		va.i++;
	}
	if (va.x != 1 || va.y != 1 || count_c == 0)
	{
		ft_destroy_map(map);
		ft_putstr_fd("Error\nError Perso or Exit or Collect\n", 2);
		return (ERROR);
	}
	return (0);
}
