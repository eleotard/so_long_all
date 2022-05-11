/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:56:15 by eleotard          #+#    #+#             */
/*   Updated: 2022/05/11 13:01:51 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_error_exit(char *error)
{
	ft_putstr_fd(error, 2);
	exit (-1);
}

void	ft_destroy_all(char **map, void *mlx, void *win, t_img *img)
{
	if (map)
		ft_destroy_map(map);
	if (img)
	{
		mlx_destroy_image(mlx, img->sol);
		mlx_destroy_image(mlx, img->mur);
		mlx_destroy_image(mlx, img->perso);
		mlx_destroy_image(mlx, img->collect);
		mlx_destroy_image(mlx, img->escape);
	}
	if (win)
		mlx_destroy_window(mlx, win);
	if (mlx)
	{
		mlx_destroy_display(mlx);
		free(mlx);
	}	
}

void	ft_destroy_all_message(char **map, void	*mlx, t_img *img, char *message)
{
	ft_destroy_all(map, mlx, NULL, img);
	ft_print_error_exit(message);
}

void	ft_destroy_map(char **map)
{
	int	k;

	k = 0;
	while (map[k])
		k++;
	while (k >= 0)
	{
		free(map[k]);
		k--;
	}
	free(map);
}
