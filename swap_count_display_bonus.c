/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_count_display_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 00:55:08 by eleotard          #+#    #+#             */
/*   Updated: 2022/05/10 19:35:12 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_print_mooves_and_display(t_vars *vars, int *count)
{
	char	*string;
	char	*count_recup;
	char	*base;

	*count = *count + 1;
	base = ft_strdup("Number of moves : ");
	count_recup = ft_itoa(*count);
	string = join(base, count_recup);
	ft_display_str_and_number("Number of moves : ", count);
	write(1, "\n", 1);
	ft_display_txt_background(vars);
	mlx_string_put(vars->mlx, vars->win, 60, (ft_map_height(vars->map)
			* SIZEPIC) + 22, 0x000000, string);
	free(string);
	ft_display_images(vars);
}

int	ft_swap_perso(t_vars *vars, char *position
	, char *swap, int *count)
{
	int		collect_status;

	if (*swap == 'C')
		*swap = '0';
	if (*swap == 'E')
	{
		collect_status = ft_check_collectibles(vars);
		if (collect_status == 1)
			return (1);
		else if (collect_status == 0)
		{
			*swap = '0';
			ft_swap(position, swap);
			ft_print_mooves_and_display(vars, count);
			ft_display_str_and_number("GG! You finished the game in ", count);
			ft_putstr_fd(" moves.", 1);
			write(1, "\n", 1);
			ft_close(vars);
		}
	}
	ft_swap(position, swap);
	ft_print_mooves_and_display(vars, count);
	usleep(COMPTEUR);
	return (0);
}
