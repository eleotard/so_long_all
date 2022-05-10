/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_count_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 00:55:08 by eleotard          #+#    #+#             */
/*   Updated: 2022/05/10 17:51:49 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_swap(char *position, char *swap)
{
	char	c_tmp;

	c_tmp = *swap;
	*swap = *position;
	*position = c_tmp;
}

void	ft_display_str_and_number(char *str, int *count)
{
	ft_putstr_fd(str, 1);
	ft_putnbr_fd(*count, 1);
}

void	ft_print_moves_and_display(t_vars *vars, int *count)
{
	*count = *count + 1;
	ft_display_str_and_number("Number of moves : ", count);
	write(1, "\n", 1);
	ft_display_images(vars);
}

void	ft_swap_perso(t_vars *vars, char *position
	, char *swap, int *count)
{
	int		collect_status;

	if (*swap == 'C')
		*swap = '0';
	if (*swap == 'E')
	{
		collect_status = ft_check_collectibles(vars);
		if (collect_status == 1)
			return ;
		else if (collect_status == 0)
		{
			*swap = '0';
			ft_swap(position, swap);
			ft_print_moves_and_display(vars, count);
			ft_display_str_and_number("GG! You finished the game in ", count);
			ft_putstr_fd(" moves.", 1);
			write(1, "\n", 1);
			ft_close(vars);
		}
	}
	ft_swap(position, swap);
	ft_print_moves_and_display(vars, count);
}
