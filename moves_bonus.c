/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 00:55:08 by eleotard          #+#    #+#             */
/*   Updated: 2022/07/30 16:36:22 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_collectibles(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map[i])
	{
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'C')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	ft_move_left(t_vars *vars, int *count)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (vars->map[++i])
	{
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'P')
				break ;
			j++;
		}
		if (vars->map[i][j] == 'P')
			break ;
		j = 0;
	}
	(*count)++;
	ft_display_str_and_number("Number of moves : ", count);
	write(1, "\n", 1);
	while (vars->map[i][j - 1] != '1' && (j > 0))
	{
		;
		if (ft_swap_perso(vars, &vars->map[i][j],
			&vars->map[i][j - 1], count) == 1)
			break ;
		j--;
	}
}

void	ft_move_right(t_vars *vars, int *count)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (vars->map[++i])
	{
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'P')
				break ;
			j++;
		}
		if (vars->map[i][j] == 'P')
			break ;
		j = 0;
	}
	(*count)++;
	ft_display_str_and_number("Number of moves : ", count);
	write(1, "\n", 1);
	while (vars->map[i][j + 1] != '1' && j < (ft_map_wide(vars->map) - 2))
	{
		if (ft_swap_perso(vars, &vars->map[i][j],
			&vars->map[i][j + 1], count) == 1)
			break ;
		j++;
	}
}

void	ft_move_up(t_vars *vars, int *count)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (vars->map[++i])
	{
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'P')
				break ;
			j++;
		}
		if (vars->map[i][j] == 'P')
			break ;
		j = 0;
	}
	(*count)++;
	ft_display_str_and_number("Number of moves : ", count);
	write(1, "\n", 1);
	while (vars->map[i - 1][j] != '1' && (i > 0))
	{
		if (ft_swap_perso(vars, &vars->map[i][j],
			&vars->map[i - 1][j], count) == 1)
			break ;
		i--;
	}
}

void	ft_move_down(t_vars *vars, int *count)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (vars->map[++i])
	{
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'P')
				break ;
			j++;
		}
		if (vars->map[i][j] == 'P')
			break ;
		j = 0;
	}
	(*count)++;
	ft_display_str_and_number("Number of moves : ", count);
	write(1, "\n", 1);
	while (vars->map[i + 1][j] != '1' && (i < (ft_map_height(vars->map) - 2)))
	{
		
		if (ft_swap_perso(vars, &vars->map[i][j],
			&vars->map[i + 1][j], count) == 1)
			break ;
		i++;
	}
}
