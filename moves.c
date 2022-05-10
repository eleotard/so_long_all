/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 00:55:08 by eleotard          #+#    #+#             */
/*   Updated: 2022/05/10 17:53:06 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (vars->map[i][j - 1] != '1' && (j > 0))
		ft_swap_perso(vars, &vars->map[i][j],
			&vars->map[i][j - 1], count);
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
	if (vars->map[i][j + 1] != '1' && j < (ft_map_wide(vars->map) - 2))
		ft_swap_perso(vars, &vars->map[i][j],
			&vars->map[i][j + 1], count);
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
	if (vars->map[i - 1][j] != '1' && (i > 0))
		ft_swap_perso(vars, &vars->map[i][j],
			&vars->map[i - 1][j], count);
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
	if (vars->map[i + 1][j] != '1' && (i < (ft_map_height(vars->map) - 2)))
		ft_swap_perso(vars, &vars->map[i][j],
			&vars->map[i + 1][j], count);
}
