/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 00:52:45 by eleotard          #+#    #+#             */
/*   Updated: 2022/05/10 14:44:14 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_zero_init(t_data *va)
{
	va->i = 0;
	va->j = 0;
	va->x = 0;
	va->y = 0;
}

void	ft_check_image(t_vars *vars, void *img)
{
	if (!img)
		ft_destroy_all_message(vars->map, vars->mlx, NULL,
			"Error\nIncorrect image\n");
}

void	ft_set_relative_path(t_vars *vars)
{
	vars->img.relative_path = "sol3.xpm";
	vars->img.relative_path2 = "glace3.xpm";
	vars->img.relative_path3 = "pingouin.xpm";
	vars->img.relative_path4 = "fish4.xpm";
	vars->img.relative_path5 = "exit.xpm";
}

void	ft_img_init(t_vars *vars)
{
	ft_set_relative_path(vars);
	vars->img.sol = mlx_xpm_file_to_image(vars->mlx, vars->img.relative_path,
			&vars->img.img_width, &vars->img.img_height);
	ft_check_image(vars, vars->img.sol);
	vars->img.mur = mlx_xpm_file_to_image(vars->mlx, vars->img.relative_path2,
			&vars->img.img_width, &vars->img.img_height);
	ft_check_image(vars, vars->img.mur);
	vars->img.perso = mlx_xpm_file_to_image(vars->mlx, vars->img.relative_path3,
			&vars->img.img_width, &vars->img.img_height);
	ft_check_image(vars, vars->img.perso);
	vars->img.collect = mlx_xpm_file_to_image(vars->mlx,
			vars->img.relative_path4, &vars->img.img_width,
			&vars->img.img_height);
	ft_check_image(vars, vars->img.collect);
	vars->img.escape = mlx_xpm_file_to_image(vars->mlx,
			vars->img.relative_path5, &vars->img.img_width,
			&vars->img.img_height);
	ft_check_image(vars, vars->img.escape);
}

void	ft_check_edges_init(t_data *co, char **map)
{
	co->i = -1;
	co->j = -1;
	co->y = ft_map_height(map);
	co->x = ft_map_wide(map);
}
